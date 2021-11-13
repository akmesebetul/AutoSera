#include <LiquidCrystal.h> 

int suSeviyesi = 0;  
int sensorPin = A1; 

LiquidCrystal  lcd(7, 6, 5, 4, 3, 2); 

void setup() 
{ 
  lcd.begin(16,2); 
  Serial.begin(9600); 
} 
  
void loop() 
{ 
  suSeviyesi = analogRead(sensorPin);
   
  if (suSeviyesi<=100) 
  { 
    lcd.clear();
    lcd.print("Su Seviyesi: "); 
    lcd.setCursor(0, 1); 
    lcd.print("0"); 
    Serial.println("0");
  } 
  else if (suSeviyesi>100 && suSeviyesi<=250) 
  { 
    lcd.clear();
    lcd.print("Su Seviyesi: ");
    lcd.setCursor(0, 1); 
    lcd.print("%25"); 
    Serial.println("%25"); 
  } 
  else if (suSeviyesi>250 && suSeviyesi<=300) 
  { 
    lcd.clear();
    lcd.print("Su Seviyesi: "); 
    lcd.setCursor(0, 1); 
    lcd.print("%50"); 
    Serial.print("%50"); 
  } 
  else if (suSeviyesi>300) 
  { 
    lcd.clear();
    lcd.print("Su Seviyesi: "); 
    lcd.setCursor(0, 1); 
    lcd.print("%100");
    Serial.println("%100"); 
  }
  
  delay(300); 
}
