#define RIGHT_MOTOR_PIN2  5          // L298N in1 motors Right           D1
#define RIGHT_MOTOR_PIN1  4          // L298N in2 motors Right           D2
#define LEFT_MOTOR_PIN2  2          // L298N in3 motors Left            GPIO2(D4)
#define LEFT_MOTOR_PIN1  0          // L298N in4 motors Left            GPIO0(D3)

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
//#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM800L
//SoftwareSerial mySerial(12,14); //SIM800L Tx & Rx is connected to Arduino #3 & #2

String command;             //String to store app command state.


const char* ssid = "Huong Nam 2.4GHz";
//const char* password = "0868475996";
ESP8266WebServer server(80);

void setup() {
   
 pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
 pinMode(RIGHT_MOTOR_PIN2, OUTPUT);
 pinMode(LEFT_MOTOR_PIN1, OUTPUT);
 pinMode(LEFT_MOTOR_PIN2, OUTPUT); 
  
  //Serial.begin(115200);

  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
/* 
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(115200);

  Serial.println("Starting time ...");
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  mySerial.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
  updateSerial();
  mySerial.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
  updateSerial();
  mySerial.println("AT+CREG?"); //Check whether it has registered in the network
  updateSerial();
  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+84868475996\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("Hello Pham Nam"); //text content
  updateSerial();
  mySerial.write(26);
*/
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}

void goAhead(){ 

   analogWrite(RIGHT_MOTOR_PIN1,0);
   analogWrite(RIGHT_MOTOR_PIN2,255);
   analogWrite(LEFT_MOTOR_PIN1,0);
   analogWrite(LEFT_MOTOR_PIN2,255);
   
  }

void goBack(){ 

   analogWrite(RIGHT_MOTOR_PIN1,1023);
   analogWrite(RIGHT_MOTOR_PIN2,0);
   analogWrite(LEFT_MOTOR_PIN1,1023);
   analogWrite(LEFT_MOTOR_PIN2,0);
   
  }

void goRight(){ 

   analogWrite(RIGHT_MOTOR_PIN1,255);
   analogWrite(RIGHT_MOTOR_PIN2,0);
   analogWrite(LEFT_MOTOR_PIN1,0);
   analogWrite(LEFT_MOTOR_PIN2,255);
  }

void goLeft(){

   analogWrite(RIGHT_MOTOR_PIN1,0);
   analogWrite(RIGHT_MOTOR_PIN2,255);
   analogWrite(LEFT_MOTOR_PIN1,255);
   analogWrite(LEFT_MOTOR_PIN2,0);
  }

void goAheadRight(){
      
   analogWrite(RIGHT_MOTOR_PIN1,0);
   analogWrite(RIGHT_MOTOR_PIN2,200);
   analogWrite(LEFT_MOTOR_PIN1,0);
   analogWrite(LEFT_MOTOR_PIN2,200);
   }

void goAheadLeft(){
      
   analogWrite(RIGHT_MOTOR_PIN1,0);
   analogWrite(RIGHT_MOTOR_PIN2,255);
   analogWrite(LEFT_MOTOR_PIN1,0);
   analogWrite(LEFT_MOTOR_PIN2,255);
  }

void goBackRight(){ 

   analogWrite(RIGHT_MOTOR_PIN1,255);
   analogWrite(RIGHT_MOTOR_PIN2,0);
   analogWrite(LEFT_MOTOR_PIN1,255);
   analogWrite(LEFT_MOTOR_PIN2,0);
  }

void goBackLeft(){ 

   analogWrite(RIGHT_MOTOR_PIN1,255);
   analogWrite(RIGHT_MOTOR_PIN2,0);
   analogWrite(LEFT_MOTOR_PIN1,255);
   analogWrite(LEFT_MOTOR_PIN2,0);
  }

void stopRobot(){  

      digitalWrite(RIGHT_MOTOR_PIN1, LOW);
      digitalWrite(RIGHT_MOTOR_PIN2, LOW);
      digitalWrite(LEFT_MOTOR_PIN1, LOW);
      digitalWrite(LEFT_MOTOR_PIN2, LOW);
      
 }

void loop() {
   
      server.handleClient();
      //updateSerial();
      command = server.arg("State");
      if (command == "F") goAhead();
      else if (command == "B") goBack();
      else if (command == "L") goLeft();
      else if (command == "R") goRight();
      else if (command == "I") goAheadRight();
      else if (command == "G") goAheadLeft();
      else if (command == "J") goBackRight();
      else if (command == "H") goBackLeft();
      /*else if (command == "0") speedCar = 400;
      else if (command == "1") speedCar = 470;
      else if (command == "2") speedCar = 540;
      else if (command == "3") speedCar = 610;
      else if (command == "4") speedCar = 680;
      else if (command == "5") speedCar = 750;
      else if (command == "6") speedCar = 820;
      else if (command == "7") speedCar = 890;
      else if (command == "8") speedCar = 960;
      else if (command == "9") speedCar = 1023;*/
      else if (command == "S") stopRobot();
}
/*void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}*/
void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
