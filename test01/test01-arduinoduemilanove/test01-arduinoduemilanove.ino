#include <DHT.h>
#include <DHT_U.h>

//#define DHTPIN D4
//#define DHTTYPE DHT22

#define voltageFlipPin1 6
#define voltageFlipPin2 7
#define sensorPin 0

//DHT dht(DHTPIN, DHTTYPE);
//const boolean IS_METRIC = false;
int flipTimer = 1000;

void setup() {
 Serial.begin(9600);
  pinMode(voltageFlipPin1, OUTPUT);
  pinMode(voltageFlipPin2, OUTPUT);
  pinMode(sensorPin, INPUT);
   
}

void setSensorPolarity(boolean flip){
  if(flip){
    digitalWrite(voltageFlipPin1, HIGH);
    digitalWrite(voltageFlipPin2, LOW);
  }else{
    digitalWrite(voltageFlipPin1, LOW);
    digitalWrite(voltageFlipPin2, HIGH);
  }
}

void loop() {
  
//read from the dht22 sensor

//float hum = dht.readHumidity();
//float temp = dht.readTemperature(); 

// Humidity Sensor reading
  setSensorPolarity(true);
  delay(flipTimer);
  int val1 = analogRead(sensorPin);
  delay(flipTimer);  
  setSensorPolarity(false);
  delay(flipTimer);
  // invert the reading
  int val2 = 1023 - analogRead(sensorPin);
  //
  reportLevels(val1,val2);

//print reading

/*Serial.print("Humidity: ");
Serial.println(hum);

Serial.print("Dirt Humidity: ");


Serial.print("Temperature: ");
Serial.println(temp);
  
delay(1000);*/
}


void reportLevels(int val1,int val2){
  
  int avg = (val1 + val2) / 2;
  
  String msg = "avg: ";
  msg += avg;
  Serial.println(msg);

}
