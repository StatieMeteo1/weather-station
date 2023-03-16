#include <LiquidCrystal.h>


#include <Wire.h>  


#include "DHT.h"
#define DHTPIN A0     //digital pin sensor

// Uncomment whatever type you're using!

  #define DHTTYPE DHT11      // DHT 11
  //#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
  //#define DHTTYPE DHT21

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



DHT dht(DHTPIN, DHTTYPE);



void setup() {
  
  lcd.begin(16, 2);
  
  dht.begin();
 

}

void loop() {

 delay(1000);
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
   lcd.print("NO CONNECTION");
    return;
  }

 
  lcd.setCursor(0, 0);
  lcd.print(h);
  lcd.print(" % ");
  
  lcd.print(t);
  lcd.print(" C");


}
