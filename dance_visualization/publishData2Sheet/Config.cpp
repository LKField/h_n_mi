// config.cpp
#include "Config.h"
#include "arduino_secrets.h"

// WiFi Configuration definitions
const char* WiFiConfig::WIFI_SSID = SECRET_SSID;
const char* WiFiConfig::WIFI_PASSWORD = SECRET_PASS;

// Google Sheets Configuration definitions
const char* GoogleSheetConfig::PROJECT_ID = SECRET_ID;
const char* GoogleSheetConfig::CLIENT_EMAIL = SECRET_EMAIL;
const char* GoogleSheetConfig::PRIVATE_KEY = SECRET_API;
const char* GoogleSheetConfig::SHEET_ID = SECRET_SHEET_ID;


// Hardware Configuration definitions for pressure sensors 
const int PinConfig::LEFT_BALL = 1;
const int PinConfig::LEFT_HEEL = 2;
const int PinConfig::RIGHT_BALL = 4;           
const int PinConfig::RIGHT_HEEL = 5;
