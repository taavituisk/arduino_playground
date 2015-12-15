#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <SparkFunHTU21D.h>
#include <dht.h>

dht DHT;
Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);
int backlight = 9;
int brightness = 0;
HTU21D hummy;
#define DHT22_PIN 2

void setup() {
  display.begin();
  display.clearDisplay();
  display.setContrast(55);
  display.setTextColor(BLACK);
  display.setTextSize(1);
  display.println("Ready!");
  display.display();
  hummy.begin();
}

void loop() {
  float humd = hummy.readHumidity();
  float temp = hummy.readTemperature();
  int read_dht = DHT.read22(DHT22_PIN);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.println("HTU21D data:");
  display.print(temp);
  display.println("C");
  display.print(humd);
  display.println("%");
  
  display.println("DHT22 data:");
  switch (read_dht)
  {
    case DHTLIB_OK:
      display.print(DHT.temperature);
      display.println("C");
      display.print(DHT.humidity);
      display.println("%");
      break;
      
    case DHTLIB_ERROR_CHECKSUM:
      display.println("chksum failed!");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      display.println("timeout!");
      break;
    default:
     display.println("general error");
     break; 
  }
  
  display.display();
  
  delay(10000);
}

