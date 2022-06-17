#include <Servo.h>
Servo myservo;
int flame = 10;
int smoke = 11;
int red = 3;
int green = 2;
int buzzer = 13 ;
int motorPin1 = 4 ;
 int motorPin2 = 5 ;
 int motorPin3 = 8 ;
 int motorPin4 = 9 ;
 int kakisensor_1 = 6 ;
 int kakisensor_2 = 7 ;
 int sensor1 = HIGH;
 int sensor2 = HIGH;
void setup ()
{
  pinMode (flame, INPUT) ;
  pinMode (smoke, INPUT) ;
  pinMode (red, OUTPUT) ;
  pinMode (green, OUTPUT) ;
  pinMode (buzzer, OUTPUT) ;
  Serial.begin(9600);
  myservo.attach(12);
  myservo.write(0);
  pinMode(motorPin1, OUTPUT);
   pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
     pinMode(motorPin4, OUTPUT);
      pinMode(kakisensor_1, OUTPUT);
       pinMode(kakisensor_2, OUTPUT);
       Serial.begin(9600);
       
}

void loop ()
{
  int fval = digitalRead (flame) ;
  int sval = digitalRead(smoke);
  Serial.print("fval = ");
  Serial.println(fval);
  Serial.print("sval = ");
  Serial.println(sval);

  if ( sval == HIGH or fval == HIGH)
  {
    Serial.println(" WARNING! ");
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(green, LOW);
    myservo.write(180);
  }
  else
  {
    Serial.println(" SAFE ");
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(buzzer, LOW);
    myservo.write(0);
    delay(100);
  }
   sensor1 = digitalRead(kakisensor_1);
  sensor2 = digitalRead(kakisensor_2);
  
  if(sensor1== LOW && sensor2== LOW )
  {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(1000);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(1000);}
 else if (sensor1== LOW&& sensor2== HIGH )
    {digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(1000);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(1000);
    }
 else if (sensor1== HIGH && sensor2== LOW )
    {digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(1000);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(1000);
    }
  else if (sensor1== HIGH && sensor2== HIGH )
  {digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    delay(1000);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4,LOW);
    delay(1000);
    }
  
}
