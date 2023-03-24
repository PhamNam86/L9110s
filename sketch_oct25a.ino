#define RIGHT_MOTOR_PIN2  5   //D1 A-1A
#define RIGHT_MOTOR_PIN1  4   //D2 A-1B

#define LEFT_MOTOR_PIN2   2   //D4 B-2B
#define LEFT_MOTOR_PIN1   0   //D3 B-1A
              
//#define RIGHT_MOTOR_SPEED 255                // speed for right motor (0-1023)
//#define LEFT_MOTOR_SPEED  255 

void setup() {
  Serial.begin(115200);
  
  pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN2, OUTPUT);
  pinMode(LEFT_MOTOR_PIN1, OUTPUT);
  pinMode(LEFT_MOTOR_PIN2, OUTPUT);
}

void loop() 
{
   /*
   digitalWrite(RIGHT_MOTOR_PIN1, LOW);
   digitalWrite(RIGHT_MOTOR_PIN2, HIGH);
   digitalWrite(LEFT_MOTOR_PIN1, LOW);
   digitalWrite(LEFT_MOTOR_PIN2 ,HIGH );
   delay(5000);
   
   digitalWrite(RIGHT_MOTOR_PIN1, LOW);
   digitalWrite(RIGHT_MOTOR_PIN2, LOW);
   digitalWrite(LEFT_MOTOR_PIN1, LOW);
   digitalWrite(LEFT_MOTOR_PIN2 ,LOW);
   delay(5000);
*/    
   
   analogWrite(RIGHT_MOTOR_PIN1,255);
   analogWrite(RIGHT_MOTOR_PIN2,LOW);
   analogWrite(LEFT_MOTOR_PIN1,255);
   analogWrite(LEFT_MOTOR_PIN2,LOW);
   delay(5000);


   analogWrite(RIGHT_MOTOR_PIN1,LOW);
   analogWrite(RIGHT_MOTOR_PIN2,200);
   analogWrite(LEFT_MOTOR_PIN1,LOW);
   analogWrite(LEFT_MOTOR_PIN2,200);
   delay(5000);
 
}
