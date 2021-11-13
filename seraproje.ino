#include <LiquidCrystal.h> 

LiquidCrystal  lcd(7, 6, 5, 4, 3, 2); 
  
int sensorPin = A1;
int suSeviyesi = 0;
int analogInPin = A0; 
int sensorValue = 0;
int dhtpin = A3;
 
void setup() {
Serial.begin(9600);
lcd.begin(16, 2);
analogReference(INTERNAL); /*setup fonksiyonumuzda bulunan analogReference(INTERNAL); komutu, Arduino'muzun analogda dijitale çeviricisinin 1,1V referans voltajı kullanmasını sağlıyor. 
                                Bu sayede, analog girişten okuyacağımız 0-1023 arası değerlerin her bir adımı 1,0742 mV (milivolt) gerilime denk düşüyor.*/
lcd.print("Sicaklik Olcumu:");
delay(100);
} 
void loop() {
//su seviyesi ölçümü
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
    lcd.print("%0"); 
    Serial.println("%0"); 
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
  
  delay(1000); 

//toprak nem ölçümü
lcd.clear();
lcd.print("Toprak Nem:");
sensorValue = analogRead(analogInPin);
lcd.setCursor(0, 1);
lcd.print(sensorValue);
delay(1000);

//ısı nem ölçümü
int sicaklikVolt = analogRead(dhtpin);
  float sicaklikC = sicaklikC = sicaklikVolt / 9.31; 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sicaklik:");
  lcd.setCursor(0, 1);
  lcd.print(sicaklikC);
  lcd.setCursor(6,1);
  lcd.print("7C");
  delay(1000);
  
  
}
