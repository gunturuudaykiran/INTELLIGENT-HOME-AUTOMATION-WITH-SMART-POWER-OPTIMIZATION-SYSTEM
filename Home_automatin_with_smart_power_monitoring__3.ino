#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);  
#include <DHT.h>
#include <DHT-U.h>
#define DHTTYPE DHT11
#define DHTPIN  A0
#define Gas A1
#define Pir A2
#define Soil A3 
int buz = 6;
DHT DHT (DHTPIN, DHTTYPE);   
float Humidity, Temperature;
int Gasv =0, Curv =0, Volv =0; //this 7672051778

void setup ()
{
  lcd.begin(16,2); 
  pinMode(DHTPIN, INPUT);
  pinMode(Gas, INPUT);
  pinMode(Pir, INPUT);
  pinMode(Soil, INPUT);
  //pinMode(relay, OUTPUT);
  pinMode(buz, OUTPUT);
  DHT.begin();    
  lcd.clear();
  lcd.print("  Intelligent ");
  lcd.setCursor(0, 1);
  lcd.print("Home Automation");
  delay(2000);
  lcd.clear();
   
}

void loop()
{
  Temperature = DHT.readTemperature(); 
  Humidity = DHT.readHumidity(); 
  Curv = analogRead(A2);
  Gasv = analogRead(A1);
  Volv = analogRead(A3);
  Serial.println("Temperature:");
  delay(1000);
  Serial.println(Temperature);
  delay(1000);
  Serial.println("Humidity:");
  delay(1000);
  Serial.println(Humidity);
  delay(1000);
  Serial.println("Pir Detection");
  Serial.println(Curv);
  delay(1000);
  Serial.println("Gas");
  delay(1000);
  Serial.println(Gasv);
  delay(1000);
  Serial.println("Soil Moisture");
  delay(1000);
  Serial.println(Volv);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp");
  lcd.setCursor(0, 1);
  lcd.print(Temperature);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humiditty");
  lcd.setCursor(0, 1);
  lcd.print(Humidity);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pir detection");
  lcd.setCursor(0, 1);
  lcd.print(Curv);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas");
  lcd.setCursor(0, 1);
  lcd.print(Gasv);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  lcd.setCursor(0, 1);
  lcd.print(Volv);
  delay(1000);
  lcd.clear();
  // if(Temperature > 37)
  // {
  //   lcd.clear();
  //   lcd.setCursor(0, 0);
  //   lcd.print("Temperature");
  //   lcd.setCursor(0, 1);
  //   digitalWrite(buz,HIGH);
  //   lcd.print(Temperature);
  //   delay(2000);
  //   digitalWrite(buz,LOW);
  // }
  // if(Curv < 37)
  // {
  //   lcd.clear();
  //   lcd.setCursor(0, 0);
  //   lcd.print("Human Detected");
  //   digitalWrite(buz,HIGH);
  //   lcd.setCursor(0, 1);
  //   lcd.print("Check the security");
  //   delay(2000);
  //   digitalWrite(buz,LOW);
  // }
  // if(Gasv > 37)
  // {
  //   lcd.clear();
  //   lcd.setCursor(0, 0);
  //   lcd.print("Gas");
  //   digitalWrite(buz,HIGH);
  //   lcd.setCursor(0, 1);
  //   lcd.print(Gas);
  //   delay(2000);
  //   digitalWrite(buz,LOW);
  // }
  // if(Volv > 37)
  // {
  //   lcd.clear();
  //   lcd.setCursor(0, 0);
  //   lcd.print("Soil no water");
  //   digitalWrite(relay,HIGH);
  //   lcd.setCursor(0, 1);
  //   lcd.print("motor on");
  //   delay(2000);
  // }
  // // if(Soilv < 37)
  // // {
  // //   lcd.clear();
  // //   lcd.setCursor(0, 0);
  // //   lcd.print("Soil water full");
  // //   digitalWrite(relay,LOW);
  // //   lcd.setCursor(0, 1);
  // //   lcd.print("motor off");
  // //   delay(2000);
  // // }


}
  
