/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-datalogging-google-sheets/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
  Adapted from the examples of the Library Google Sheet Client Library for Arduino devices: https://github.com/mobizt/ESP-Google-Sheet-Client
*/

#include <Arduino.h>
#include <WiFi.h>
#include "time.h"
#include <ESP_Google_Sheet_Client.h>
//#include "arduino_secrets.h"
#include "Config.h"

// For SD/SD_MMC mounting helper
#include <GS_SDHelper.h>

//#define WIFI_SSID SECRET_SSID
//#define WIFI_PASSWORD SECRET_PASS

// Google Project ID
//#define PROJECT_ID SECRET_ID

// Service Account's client email
//#define CLIENT_EMAIL SECRET_EMAIL

//const char* WIFI_SSID = SECRET_SSID;
//const char* WIFI_PASSWORD = SECRET_PASS;

//const char PROJECT_ID = SECRET_ID;

//const char CLIENT_EMAIL = SECRET_EMAIL;

// Service Account's private key
//const char PRIVATE_KEY[] PROGMEM = SECRET_API;

// The ID of the spreadsheet where you'll publish the data
//const char spreadsheetId[] = SECRET_SHEET_ID;

// Timer variables
unsigned long lastTime = 0;  
unsigned long timerDelay = 30000;

// Token Callback function
void tokenStatusCallback(TokenInfo info);

// NTP server to request epoch time
const char* ntpServer = "pool.ntp.org";

// Variable to save current epoch time
unsigned long epochTime; 

// Function that gets current epoch time
unsigned long getTime() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return(0);
  }
  time(&now);
  Serial.println(now);
  return now;
}

void setup(){

    Serial.begin(115200);
    delay(10);
    Serial.println();
    Serial.println();
    Serial.println("--------------------------------------------------------------------");

    //Configure time
    configTime(0, 0, ntpServer);

    GSheet.printf("ESP Google Sheet Client v%s\n\n", ESP_GOOGLE_SHEET_CLIENT_VERSION);

    // // Connect to Wi-Fi
    // WiFi.setAutoReconnect(true);
    // WiFi.begin(WiFiConfig::WIFI_SSID, WiFiConfig::WIFI_PASSWORD);
  
    // Serial.print("Connecting to Wi-Fi");
    // while (WiFi.status() != WL_CONNECTED) {
    //   Serial.print(".");
    //   delay(1000);
    // }
    // Serial.println();
    // Serial.print("Connected with IP: ");
    // Serial.println(WiFi.localIP());
    // Serial.println();
    
  // We start by connecting to a WiFi network
  // To debug, please enable Core Debug Level to Verbose

  Serial.println();
  Serial.print("[WiFi] Connecting to ");
  Serial.println(WiFiConfig::WIFI_SSID);

  WiFi.begin(WiFiConfig::WIFI_SSID, WiFiConfig::WIFI_PASSWORD);
  // Auto reconnect is set true as default
  // To set auto connect off, use the following function
  //    WiFi.setAutoReconnect(false);

  // Will try for about 10 seconds (20x 500ms)
  int tryDelay = 500;
  int numberOfTries = 20;

  // Wait for the WiFi event
  while (true) {

    switch (WiFi.status()) {
      case WL_NO_SSID_AVAIL: Serial.println("[WiFi] SSID not found"); break;
      case WL_CONNECT_FAILED:
        Serial.print("[WiFi] Failed - WiFi not connected! Reason: ");
        return;
        break;
      case WL_CONNECTION_LOST: Serial.println("[WiFi] Connection was lost"); break;
      case WL_SCAN_COMPLETED:  Serial.println("[WiFi] Scan is completed"); break;
      case WL_DISCONNECTED:    Serial.println("[WiFi] WiFi is disconnected"); break;
      case WL_CONNECTED:
        Serial.println("[WiFi] WiFi is connected!");
        Serial.print("[WiFi] IP address: ");
        Serial.println(WiFi.localIP());
        return;
        break;
      default:
        Serial.print("[WiFi] WiFi Status: ");
        Serial.println(WiFi.status());
        break;
    }
    delay(tryDelay);

    if (numberOfTries <= 0) {
      Serial.print("[WiFi] Failed to connect to WiFi!");
      // Use disconnect function to force stop trying to connect
      WiFi.disconnect();
      return;
    } else {
      numberOfTries--;
    }
  }
    // Set the callback for Google API access token generation status (for debug only)
    GSheet.setTokenCallback(tokenStatusCallback);

    // Set the seconds to refresh the auth token before expire (60 to 3540, default is 300 seconds)
    GSheet.setPrerefreshSeconds(10 * 60);

    // Begin the access token generation for Google API authentication
    GSheet.begin(GoogleSheetConfig::CLIENT_EMAIL, GoogleSheetConfig::PROJECT_ID, GoogleSheetConfig::PRIVATE_KEY[]);
}

void loop(){
    Serial.println(GoogleSheetConfig::CLIENT_EMAIL);
    Serial.println(GoogleSheetConfig::PROJECT_ID);
    Serial.println(GoogleSheetConfig::PRIVATE_KEY[]); 

    // Call ready() repeatedly in loop for authentication checking and processing
    bool ready = GSheet.ready();
    Serial.print("GSheet.ready bool: ");
    Serial.println(ready);

    //Delay to actually be able to read the serial monitor 
    delay(10000);

    if (ready && millis() - lastTime > timerDelay){
        lastTime = millis();

        FirebaseJson response;

        Serial.println("\nAppend spreadsheet values...");
        Serial.println("----------------------------");

        FirebaseJson valueRange;

        // Get timestamp
        epochTime = getTime();

        valueRange.add("majorDimension", "COLUMNS");
        valueRange.set("values/[0]/[0]", epochTime);


        // For Google Sheet API ref doc, go to https://developers.google.com/sheets/api/reference/rest/v4/spreadsheets.values/append
        // Append values to the spreadsheet
        bool success = GSheet.values.append(&response /* returned response */, GoogleSheetConfig::SHEET_ID[] /* spreadsheet Id to append */, "Sheet1!A1" /* range to append */, &valueRange /* data range to append */);
        if (success){
            response.toString(Serial, true);
            valueRange.clear();
        }
        else{
            Serial.println(GSheet.errorReason());
        }
        Serial.println();
        Serial.println(ESP.getFreeHeap());
    }
}

void tokenStatusCallback(TokenInfo info){
    if (info.status == token_status_error){
        GSheet.printf("Token info: type = %s, status = %s\n", GSheet.getTokenType(info).c_str(), GSheet.getTokenStatus(info).c_str());
        GSheet.printf("Token error: %s\n", GSheet.getTokenError(info).c_str());
    }
    else{
        GSheet.printf("Token info: type = %s, status = %s\n", GSheet.getTokenType(info).c_str(), GSheet.getTokenStatus(info).c_str());
    }
}