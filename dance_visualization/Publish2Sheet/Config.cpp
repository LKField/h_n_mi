// config.cpp
#include "Config.h"
#include "arduino_secrets.h"

// WiFi Configuration definitions
const char* WiFiConfig::WIFI_SSID = SECRET_SSID;
const char* WiFiConfig::WIFI_PASSWORD = SECRET_PASS;

// Google Sheets Configuration definitions
const char* GoogleSheetConfig::PROJECT_ID = SECRET_ID;
const char* GoogleSheetConfig::CLIENT_EMAIL = SECRET_EMAIL;
const char* GoogleSheetConfig::PRIVATE_KEY[] = SECRET_API[];
const char* GoogleSheetConfig::SHEET_ID[] = SECRET_SHEET_ID[];


// Hardware Configuration definitions TODO: Fix This for Hardware
const int PinConfig::ONBOARD_LED = 48;
const int PinConfig::PHOTO_TRANSISTOR = 3;
const int PinConfig::BUZZER = 46;           // Changed to buzzer pin 46 not 43
const int PinConfig::TEMP_SENSOR_SDA = 8;
const int PinConfig::TEMP_SENSOR_SCL = 9;
const int PinConfig::NEOPIXEL = 38;