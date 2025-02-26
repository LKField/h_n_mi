// config.h - Central configuration file
#ifndef CONFIG_H
#define CONFIG_H

// WiFi Configuration
struct WiFiConfig {
    static const char* WIFI_SSID;
    static const char* WIFI_PASSWORD;
};

// Google Sheet Configuration
struct GoogleSheetConfig {
    static const char* PROJECT_ID;
    static const char* CLIENT_EMAIL;
    static const char* PRIVATE_KEY;
    static const char* SHEET_ID;
};

// Hardware Configuration TODO: Fix this 
struct PinConfig {
    static const int ONBOARD_LED;
    static const int PHOTO_TRANSISTOR;
    static const int BUZZER;
    static const int TEMP_SENSOR_SDA;
    static const int TEMP_SENSOR_SCL;
    static const int NEOPIXEL;
};

#endif