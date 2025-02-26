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

// Hardware Configuration
struct PinConfig {
    static const int LEFT_BALL;
    static const int LEFT_HEEL;
    static const int RIGHT_BALL;
    static const int RIGHT_HEEL;
};

#endif