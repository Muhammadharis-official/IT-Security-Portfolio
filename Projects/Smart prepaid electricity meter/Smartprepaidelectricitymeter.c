#include <SoftwareSerial.h>
#include <EEPROM.h>
#include <FirebaseArduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RELAY_PIN 12
#define CT_PIN A0
#define BUZZER_PIN 8
#define GSM_RX 11
#define GSM_TX 10
#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASSWORD "your_wifi_password"
#define FIREBASE_HOST "your_firebase_host"
#define FIREBASE_AUTH "your_firebase_auth"

SoftwareSerial gsmSerial(GSM_RX, GSM_TX);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float currentUnits = 0.0;
float remainingUnits = 100.0;
bool alertSent = false;

void setup() {
    Serial.begin(9600);
    gsmSerial.begin(9600);
    lcd.begin();
    lcd.backlight();
    
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    
    EEPROM.get(0, remainingUnits);
    
    lcd.print("Units: ");
    lcd.print(remainingUnits);
    
    checkRelay();
}

void loop() {
    readEnergyMeter();
    
    if (remainingUnits <= 10 && !alertSent) {
        sendLowBalanceAlert();
        alertSent = true;
    }
    
    if (remainingUnits <= 0) {
        disconnectPower();
        alertSent = false;
    }
    
    Firebase.setFloat("remainingUnits", remainingUnits);
    
    delay(10000);
}

void readEnergyMeter() {
    float unitsConsumed = analogRead(CT_PIN) * (5.0 / 1023.0);
    currentUnits += unitsConsumed;
    
    remainingUnits -= unitsConsumed;
    
    lcd.clear();
    lcd.print("Units: ");
    lcd.print(remainingUnits);
}

void sendLowBalanceAlert() {
    String message = "Low balance alert! Remaining units: " + String(remainingUnits);
    
    gsmSerial.println("AT+CMGF=1");
    delay(100);
    
    gsmSerial.print("AT+CMGS=\"your_phone_number\"");
    delay(100);
    
    gsmSerial.print(message);
    delay(100);
    
    gsmSerial.write(26);
}

void disconnectPower() {
    digitalWrite(RELAY_PIN, LOW);
    tone(BUZZER_PIN, 1000);
    
    lcd.clear();
    lcd.print("Power Disconnected");
}

void checkRelay() {
    if (remainingUnits > 0) {
        digitalWrite(RELAY_PIN, HIGH);
        noTone(BUZZER_PIN);
    } else {
        disconnectPower();
    }
}