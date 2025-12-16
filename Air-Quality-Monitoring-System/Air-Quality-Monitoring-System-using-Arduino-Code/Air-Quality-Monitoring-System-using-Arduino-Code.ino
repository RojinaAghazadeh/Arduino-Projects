#include <LiquidCrystal.h>

// Pin definitions
const int sensorPin = A0;   // Air quality sensor analog pin
const int ledGreen = 6;     // Green LED pin (Good air quality)
const int ledRed = 7;       // Red LED pin (Poor air quality)
const int buzzerPin = 8;    // Buzzer pin (Audio alert)

// Initialize LCD object (RS, EN, D4, D5, D6, D7 pins)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Global variables - declared outside all functions
int sensorData = 0;         // Store sensor reading

void setup() {
  // Set pin modes (input/output)
  pinMode(sensorPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Set default pin states
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(buzzerPin, LOW);
  
  // Initialize LCD with default message
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AQI Alert System");
  delay(1000);  // Display startup message for 1 second
}

void loop() {
  // Read sensor value (0-1023 from analog input)
  sensorData = analogRead(sensorPin);
  
  // Display sensor value on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AQI: ");
  lcd.print(sensorData);
  
  // Determine air quality level and control outputs
  if (sensorData <= 50) {
    // Good air quality
    lcd.setCursor(0, 1);
    lcd.print("Status: Good");
    digitalWrite(ledGreen, HIGH);  // Green LED ON
    digitalWrite(ledRed, LOW);     // Red LED OFF
    noTone(buzzerPin);             // Buzzer OFF
  } 
  else if (sensorData <= 100) {
    // Moderate air quality
    lcd.setCursor(0, 1);
    lcd.print("Status: Moderate");
    digitalWrite(ledGreen, LOW);   // Green LED OFF
    digitalWrite(ledRed, LOW);     // Red LED OFF
    noTone(buzzerPin);             // Buzzer OFF
  } 
  else if (sensorData <= 150) {
    // Unhealthy air quality
    lcd.setCursor(0, 1);
    lcd.print("Status: Unhealthy");
    digitalWrite(ledGreen, LOW);   // Green LED OFF
    digitalWrite(ledRed, HIGH);    // Red LED ON
    noTone(buzzerPin);             // Buzzer OFF
  } 
  else {
    // Hazardous air quality
    lcd.setCursor(0, 1);
    lcd.print("Status: Hazardous!");
    digitalWrite(ledGreen, LOW);   // Green LED OFF
    digitalWrite(ledRed, HIGH);    // Red LED ON
    tone(buzzerPin, 1000);         // Buzzer ON (1000 Hz tone)
  }
  
  delay(2000);  // Wait 2 seconds before next reading
}