
/**
 * Created by K. Suwatchai (Mobizt)
 *
 * Email: suwatchai@outlook.com
 *
 * Github: https://github.com/mobizt
 *
 * Copyright (c) 2023 mobizt
 *
 * Edited by Lucretia Field 
 */

// This example shows how to append new values to spreadsheet.

#include <Arduino.h>
#include "arduino_secrets.h"
#include "Config.h"

#if defined(ESP32) || defined(ARDUINO_RASPBERRY_PI_PICO_W)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#elif __has_include(<WiFiNINA.h>)
#include <WiFiNINA.h>
#elif __has_include(<WiFi101.h>)
#include <WiFi101.h>
#elif __has_include(<WiFiS3.h>)
#include <WiFiS3.h>
#endif

#include <ESP_Google_Sheet_Client.h>

// For SD/SD_MMC mounting helper
#include <GS_SDHelper.h>

unsigned long ms = 0;

#if defined(ARDUINO_RASPBERRY_PI_PICO_W)
WiFiMulti multi;
#endif

void tokenStatusCallback(TokenInfo info);

//Set up Sensor Values 
// int sensorVal_LEFT_BALL;
// int sensorVal_LEFT_HEEL;
// int sensorVal_RIGHT_BALL;
// int sensorVal_RIGHT_HEEL;

// Define the structure for pressure data 
struct Pressure {
  int left_ball;
  int left_heel;
  int right_ball;
  int right_heel;
};

// Define delays for integration with P5.js
int del_60fps = 1000/60;
int del_30fps = 1000/30;
int del_15fps = 1000/15;

void setup()
{
  //  Serial.begin(115200);
  //  Serial.println();

  //  Serial.println();

    GSheet.printf("ESP Google Sheet Client v%s\n\n", ESP_GOOGLE_SHEET_CLIENT_VERSION);

#if defined(ESP32) || defined(ESP8266)
    WiFi.setAutoReconnect(true);
#endif

#if defined(ARDUINO_RASPBERRY_PI_PICO_W)
    multi.addAP(WiFiConfig::WIFI_SSID, WiFiConfig::WIFI_PASSWORD);
    multi.run();
#else
    WiFi.begin(WiFiConfig::WIFI_SSID, WiFiConfig::WIFI_PASSWORD);
#endif

  //  Serial.print("Connecting to Wi-Fi");
    unsigned long ms = millis();
    while (WiFi.status() != WL_CONNECTED)
    {
      //  Serial.print(".");
      //  delay(300);
        delay(10);
#if defined(ARDUINO_RASPBERRY_PI_PICO_W)
        if (millis() - ms > 10000)
            break;
#endif
    }
  //  Serial.println();
  //  Serial.print("Connected with IP: ");
  //  Serial.println(WiFi.localIP());
  //  Serial.println();

    // In case SD/SD_MMC storage file access, mount the SD/SD_MMC card.
    // SD_Card_Mounting(); // See src/GS_SDHelper.h

    // Set the callback for Google API access token generation status (for debug only)
    GSheet.setTokenCallback(tokenStatusCallback);

    // The WiFi credentials are required for Pico W
    // due to it does not have reconnect feature.
#if defined(ARDUINO_RASPBERRY_PI_PICO_W)
    GSheet.clearAP();
    GSheet.addAP(WiFiConfig::WIFI_SSID, WiFiConfig::WIFI_PASSWORD);
#endif

    // Set the seconds to refresh the auth token before expire (60 to 3540, default is 300 seconds)
    GSheet.setPrerefreshSeconds(10 * 60);

    // Begin the access token generation for Google API authentication
    GSheet.begin(GoogleSheetConfig::CLIENT_EMAIL, GoogleSheetConfig::PROJECT_ID, GoogleSheetConfig::PRIVATE_KEY);

    // Or begin with the Service Account JSON file
    // GSheet.begin("path/to/serviceaccount/json/file", esp_google_sheet_file_storage_type_flash /* or esp_google_sheet_file_storage_type_sd */);

    //Set up sensor pins
    pinMode(PinConfig::LEFT_BALL, INPUT);
    pinMode(PinConfig::LEFT_HEEL, INPUT);
    pinMode(PinConfig::RIGHT_BALL, INPUT);
    pinMode(PinConfig::RIGHT_HEEL, INPUT);

}

// Function that gets current epoch time
unsigned long getTime() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
  //  Serial.println("Failed to obtain time");
    return(0);
  }
  time(&now);
  //Serial.println(now);
  return now;
}

void loop()
{
    // Call ready() repeatedly in loop for authentication checking and processing
    bool ready = GSheet.ready();

    // GSheet.setSystemTime(getTime());
    // Serial.println(getTime());

    if (ready && millis() - ms > 5000)
    {
        ms = millis();

        // For basic FirebaseJson usage example, see examples/FirebaseJson/Create_Edit_Parse/Create_Edit_Parse.ino

        // If you assign the spreadsheet id from your own spreadsheet,
        // you need to set share access to the Service Account's CLIENT_EMAIL

        FirebaseJson response;
        // Instead of using FirebaseJson for response, you can use String for response to the functions
        // especially in low memory device that deserializing large JSON response may be failed as in ESP8266



      //  Serial.println("\nAppend spreadsheet values...");
      //  Serial.println("----------------------------");

        FirebaseJson valueRange;

        Pressure reading = pressureReading();

        valueRange.add("majorDimension", "COLUMNS");
        valueRange.set("values/[0]/[0]", getTime());
        valueRange.set("values/[1]/[0]", reading.left_ball);
        valueRange.set("values/[2]/[0]", reading.left_heel);
        valueRange.set("values/[3]/[0]", reading.right_ball);
        valueRange.set("values/[4]/[0]", reading.right_heel);
        
        // For Google Sheet API ref doc, go to https://developers.google.com/sheets/api/reference/rest/v4/spreadsheets.values/append

        bool success = GSheet.values.append(&response /* returned response */, GoogleSheetConfig::SHEET_ID /* spreadsheet Id to append */, "Sheet1!A2" /* range to append */, &valueRange /* data range to append */);
        // if (success) {
        //   delay(10);
        // //    response.toString(Serial, true);
        // //    Serial.println("Success: I am here!");
        // }
        // else {       // Removed because confusing messages 
        //     delay(10);
        //     //Serial.println(GSheet.errorReason()); 
        // }
        //Serial.println();
  }
}

Pressure pressureReading() {

  Pressure reading;

  reading.left_ball=analogRead(PinConfig::LEFT_BALL);
  reading.left_heel=analogRead(PinConfig::LEFT_HEEL);

  reading.right_ball=analogRead(PinConfig::RIGHT_BALL);
  reading.right_heel=analogRead(PinConfig::RIGHT_HEEL);

  return reading;
}

void tokenStatusCallback(TokenInfo info)
{
    if (info.status == token_status_error)
    {
        GSheet.printf("Token info: type = %s, status = %s\n", GSheet.getTokenType(info).c_str(), GSheet.getTokenStatus(info).c_str());
        GSheet.printf("Token error: %s\n", GSheet.getTokenError(info).c_str());
    }
    else
    {
        GSheet.printf("Token info: type = %s, status = %s\n", GSheet.getTokenType(info).c_str(), GSheet.getTokenStatus(info).c_str());
    }
}