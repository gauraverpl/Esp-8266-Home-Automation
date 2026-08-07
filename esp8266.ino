#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

#define WIFI_SSID "xxxxxxxx"
#define WIFI_PASS "xxxxxxxxxx"
#define APP_KEY "9a20c9a1-xxxxxx-xxxxxx-xxxxxx"
#define APP_SECRET "8baac5e4-50c6-4cxxxxxxxx-xxxxxx -69bfbafddb0f6e0b15a3f842"
#define RELAY2_DEVICE_ID "69bfbxxxxxxxxxxxxxd842"

// ESP8266 Pin Definitions - D5 = GPIO 14, D6 = GPIO 12
#define RELAY1_PIN 14  // D5
#define RELAY2_PIN 12  // D6

#define LCD_ADDRESS 0x27

bool relay1State = false;
bool relay2State = false;
LiquidCrystal_PCF8574 lcd(LCD_ADDRESS);

// Function declaration
void updateLCD();

bool onPowerState1(const String &deviceId, bool &state) {
  Serial.printf("Relay 1 turn %s\r\n", state ? "ON" : "OFF");
  relay1State = state;
  digitalWrite(RELAY1_PIN, relay1State ? HIGH : LOW);
  updateLCD();
  return true;
}

bool onPowerState2(const String &deviceId, bool &state) {
  Serial.printf("Relay 2 turn %s\r\n", state ? "ON" : "OFF");
  relay2State = state;
  digitalWrite(RELAY2_PIN, relay2State ? HIGH : LOW);
  updateLCD();
  return true;
}

void setupWiFi() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");
  lcd.setCursor(0, 1);
  lcd.print("Please wait...");
  
  Serial.printf("\r\n[WIFI]: Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 40) {
    Serial.printf(".");
    delay(250);
    attempts++;
    
    // Animate the LCD while connecting
    static int dotCount = 0;
    if (attempts % 4 == 0) {
      lcd.setCursor(0, 1);
      lcd.print("Please wait");
      for (int i = 0; i < dotCount; i++) {
        lcd.print(".");
      }
      dotCount = (dotCount % 3) + 1;
    }
  }
  
  Serial.printf("\n");
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.printf("connected!\r\n[WiFi]: IP-Address is %s\r\n", WiFi.localIP().toString().c_str());
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WiFi Connected!");
    lcd.setCursor(0, 1);
    lcd.print(WiFi.localIP().toString());
    delay(2000);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WiFi Failed!");
    lcd.setCursor(0, 1);
    lcd.print("Restarting...");
    delay(3000);
    ESP.restart();
  }
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Relay 1: ");
  lcd.print(relay1State ? "ON " : "OFF");
  lcd.setCursor(0, 1);
  lcd.print("Relay 2: ");
  lcd.print(relay2State ? "ON " : "OFF");
}

void setupRelay() {
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);
}

void showWelcomeMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome to IoT");
  lcd.setCursor(0, 1);
  lcd.print("Device Starting");
  
  // Animated welcome effect
  for (int i = 0; i < 3; i++) {
    delay(500);
    lcd.setCursor(0, 1);
    lcd.print("Device Starting");
    for (int j = 0; j <= i; j++) {
      lcd.print(".");
    }
  }
  delay(1000);
}

void setupSinricPro() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SinricPro Init");
  lcd.setCursor(0, 1);
  lcd.print("Connecting...");
  
  SinricProSwitch &mySwitch1 = SinricPro[RELAY1_DEVICE_ID];
  SinricProSwitch &mySwitch2 = SinricPro[RELAY2_DEVICE_ID];
  
  mySwitch1.onPowerState(onPowerState1);
  mySwitch2.onPowerState(onPowerState2);
  
  SinricPro.onConnected([]() {
    Serial.printf("Connected to SinricPro\r\n");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SinricPro Ready");
    lcd.setCursor(0, 1);
    lcd.print("System Active");
    delay(1500);
    updateLCD();
  });
  
  SinricPro.onDisconnected([]() {
    Serial.printf("Disconnected from SinricPro\r\n");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SinricPro Lost");
    lcd.setCursor(0, 1);
    lcd.print("Reconnecting...");
  });
  
  SinricPro.begin(APP_KEY, APP_SECRET);
}

void setup() {
  Serial.begin(115200);
  
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  
  // Show welcome message
  showWelcomeMessage();
  
  // Setup relays
  setupRelay();
  
  // Connect to WiFi with display updates
  setupWiFi();
  
  // Setup SinricPro
  setupSinricPro();
}

void loop() {
  SinricPro.handle();
  delay(10);
}