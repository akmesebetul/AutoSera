#include <LiquidCrystal.h> 

LiquidCrystal  lcd(7, 6, 5, 4, 3, 2); 

int analogInPin = A0; 
int sensorValue = 0; 
void setup() {


lcd.begin(16, 2);
delay(100);
} 
void loop() {
lcd.clear();
lcd.print("Toprak Nem:");
sensorValue = analogRead(analogInPin);
lcd.setCursor(0, 1);
lcd.print(sensorValue);

delay(300);
}
