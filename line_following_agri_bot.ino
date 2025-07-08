#include <Arduino.h>

#define enA 10//Enable1 L298 Pin enA 
#define in1 9 //Motor1  L298 Pin in1 
#define in2 8 //Motor1  L298 Pin in1 
#define in3 6 //Motor2  L298 Pin in1 
#define in4 7 //Motor2  L298 Pin in1 
#define enB 5 //Enable2 L298 Pin enB 
#define L_S A2 //ir sensor Left
#define R_S A1 //ir sensor Right
int sensor_pin = A0;
#include<SoftwareSerial.h>
//#include<string.h>
#include "DHT.h"

SoftwareSerial B(11,12);    //10-RX,  11-TX

#define DHTPIN 2  
#define DHTTYPE DHT11      // DHT 11
DHT dht(DHTPIN, DHTTYPE);
void setup(){ // put your setup code here, to run once
pinMode(sensor_pin, INPUT);
Serial.begin(9600); // start serial communication at 9600bps
B.begin(9600);
dht.begin();
pinMode(R_S, INPUT); // declare if sensor as input  
pinMode(L_S, INPUT); // declare ir sensor as input
pinMode(enA, OUTPUT); // declare as output for L298 Pin enA 
pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 
pinMode(enB, OUTPUT); // declare as output for L298 Pin enB 
analogWrite(enA, 120); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, 120); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
delay(500);
}
void loop(){  
  int sensor_data = analogRead(sensor_pin);
  Serial.print("Sensor_data:");
  Serial.print(sensor_data);
  Serial.print("\t | ");

  String soilHumidity = "";
  
  if(sensor_data > 950)
  {
    Serial.println("No moisture, Soil is dry");
    soilHumidity = "no";
  }
  else if(sensor_data >= 400 && sensor_data <= 950)
  {
    Serial.println("There is some moisture, Soil is medium");
    soilHumidity = "medium";
  }
  else if(sensor_data < 400)
  {
    Serial.println("Soil is wet");
    soilHumidity = "high";
  }

  // Read humidity
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  B.print(h);
  B.print(",");
  B.print(t);
  B.print(" C");
  B.print(",");
  B.print(f);
  B.print(" F");
  B.print(",");
  B.print(soilHumidity);
  B.print(" humidity");
  B.print(";");

  
  Serial.println("running");
//==============================================
//     Line Follower and Obstacle Avoiding
//==============================================  
 
//if Right Sensor is Black and Left Sensor is White then it will call turn Right function
if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){
  Serial.println("turn right");
  turnRight();

}  
//if Right Sensor is White and Left Sensor is Black then it will call turn Left function
else if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){
  Serial.println("turn left");
  turnLeft();
  } 
else{forword();}
    
delay(10);
}

void forword(){  //forword
digitalWrite(in1, LOW); //Left Motor backword Pin 
digitalWrite(in2, HIGH); //Left Motor forword Pin 
digitalWrite(in3, HIGH); //Right Motor forword Pin 
digitalWrite(in4, LOW); //Right Motor backword Pin 
}
void turnRight(){ //turnRight
digitalWrite(in1, LOW); //Left Motor backword Pin 
digitalWrite(in2, HIGH); //Left Motor forword Pin 
digitalWrite(in3, LOW); //Right Motor forword Pin 
digitalWrite(in4, HIGH); //Right Motor backword Pin 

    delay(100);
}
void turnLeft(){ //turnLeft
digitalWrite(in1, HIGH); //Left Motor backword Pin 
digitalWrite(in2, LOW); //Left Motor forword Pin 
digitalWrite(in3, HIGH); //Right Motor forword Pin 
digitalWrite(in4, LOW); //Right Motor backword Pin 

    delay(100);
}
void Stop(){ //stop
digitalWrite(in1, LOW); //Left Motor backword Pin 
digitalWrite(in2, LOW); //Left Motor forword Pin 
digitalWrite(in3, LOW); //Right Motor forword Pin 
digitalWrite(in4, LOW); //Right Motor backword Pin 
}
