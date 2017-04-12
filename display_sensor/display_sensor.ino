
#include <Wire.h> 
#include<time.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
LiquidCrystal_I2C lcd(0x3F,16,2);  
#define DHTPIN            7       // Pin which is connected to the DHT sensor.
#define DHTTYPE           DHT11     // DHT 11 

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

char mes[16];

void setup(){
  lcd.init();             
  lcd.backlight();                       
   Serial.begin(9600); 
  // Initialize device.
  dht.begin();
  Serial.println("DHTxx Unified Sensor Example");
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Temperature");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" *C");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" *C");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" *C");  
  Serial.println("------------------------------------");
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Humidity");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println("%");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println("%");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println("%");  
  Serial.println("------------------------------------");
  // Set delay between sensor readings based on sensor details.
  int sec = 1000;
  int minute = sec * 60;
  delayMS = minute;
}

void loop(){

  char mes=Serial.read();
  if(mes=='1'){
    lcd.backlight();
    }else{
      if(mes=='0'){
        lcd.noBacklight();
        }else{
          //Serial.println("invalid input");
          }
      }
 delay(5000);
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    //Serial.print("Temp: ");
    //Serial.print(event.temperature);
    //Serial.println(" *C");
    lcd.print(event.temperature);
    lcd.print(" *C");
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    //Serial.println("Error reading humidity!");
  }
  else {
    //Serial.print("Humidity: ");
    //Serial.print(event.relative_humidity);
    //Serial.println("%");
    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(event.relative_humidity);
    lcd.print("%");
  }
  }
