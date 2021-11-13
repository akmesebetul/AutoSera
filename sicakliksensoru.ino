#include <LiquidCrystal.h>
 
int dhtpin = A3;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 
 
void setup() 
{
  lcd.begin(16, 2);
  analogReference(INTERNAL); /*setup fonksiyonumuzda bulunan analogReference(INTERNAL); komutu, Arduino'muzun analogda dijitale çeviricisinin 1,1V referans voltajı kullanmasını sağlıyor. 
                                Bu sayede, analog girişten okuyacağımız 0-1023 arası değerlerin her bir adımı 1,0742 mV (milivolt) gerilime denk düşüyor.*/
  lcd.print("Sicaklik Olcumu:");
}
 
void loop()
{
  int sicaklikVolt = analogRead(dhtpin);
  float sicaklikC = sicaklikC = sicaklikVolt / 9.31; 
  lcd.setCursor(0, 1);
  lcd.print(sicaklikC);
  lcd.setCursor(6,1);
  lcd.print("7C");
  delay(100);
}
