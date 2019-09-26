#include<Servo.h>
int IRSensor1=A1;  //Value initialization of variables
int IRSensor2=A2;
int ldr=A5;
int R1R=6;
int R1G=7;
int R2R=8;
int R2G=9;
int R3R=10;
int R3G=11;
int R4R=12;
int R4G=13;
int Postled=2;
int PostGnd=1;

int count =1;
Servo gate;  //create servo object

unsigned long previousMillis = 0;
const long interval = 5000;




void setup()
{
  Serial.begin(9600);   //serial communication speed
  pinMode(R1R, OUTPUT); //Set the pin modes
  pinMode(R1G, OUTPUT);
  pinMode(R2R, OUTPUT);
  pinMode(R2G, OUTPUT);
  pinMode(R3R, OUTPUT);
  pinMode(R3G, OUTPUT);
  pinMode(R4R, OUTPUT);
  pinMode(R4G, OUTPUT);
  pinMode(Postled, OUTPUT);
  pinMode(PostGnd, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(IRSensor1,INPUT);
  pinMode(IRSensor2,INPUT);
  digitalWrite(PostGnd,LOW);
  
  gate.attach(3); //attach the servo motors pin to 5

  
}

void loop()
{
  int S1value=analogRead(IRSensor1);  //read value from ir sensor's
  int S2value=analogRead(IRSensor2);
  
  if(S1value<500)   //Railway gate write according to sensors value
  {
    gate.write(0);
  }
  if(S2value<500)
  {
    gate.write(90);
  }
 

 unsigned long currentMillis = millis(); // count millisecound
     
if (currentMillis - previousMillis >= interval) // traffic light state change's after certain amount of time
  {
    previousMillis = currentMillis;
    
    if(count==1)    // count value 1to4 for 4 possible state execution 
    {
      //Serial.println("road1 ON"); //print road1 state
      Low();           // Low function call
      road1();          //  road1 function call
      count=2;           //   count value increment for next state execution
    }
     
   else if(count==2)
    {
      //Serial.println("road2 ON");
      Low();
      road2();
      count=3;
    }
     
   else if(count==3)
    {
      
      //Serial.println("road3 ON");
      Low();
      road3();
      count=4;
    }
     
   else if(count==4)
    {
   
      //Serial.println("road4 ON");
      Low();
      road4();
      count=1;
    }
  
  }  

  
 int sunlight = analogRead(ldr);  // measure sunlights luminosity
 Serial.println(sunlight);
 if(sunlight <3)
  {
    //Serial.println("Lamppost ON");
    digitalWrite(Postled,HIGH);   //Lamppost Light ON when sunlight is very low
 
  }
 else
  {
    //Serial.println("Lamppost OFF");
    digitalWrite(Postled,LOW);
   
  }
  

 
}
  
  


void road1()
{
  digitalWrite(R1R,LOW); //State of Road no 1
  digitalWrite(R1G,HIGH);
  digitalWrite(R2R,HIGH);
  digitalWrite(R3R,HIGH);
  digitalWrite(R4R,HIGH);
  digitalWrite(R2G,LOW); 
  digitalWrite(R3G,LOW);
  digitalWrite(R4G,LOW);

    
}

void road2()
{
  digitalWrite(R2R,LOW); //State of Road no 2
  digitalWrite(R2G,HIGH);
  digitalWrite(R1R,HIGH);
  digitalWrite(R3R,HIGH);
  digitalWrite(R4R,HIGH);
  digitalWrite(R1G,LOW); 
  digitalWrite(R3G,LOW);
  digitalWrite(R4G,LOW);
}

void road3()
{
  digitalWrite(R3R,LOW); //State of Road no 3
  digitalWrite(R3G,HIGH);
  digitalWrite(R1R,HIGH);
  digitalWrite(R2R,HIGH);
  digitalWrite(R4R,HIGH);
  digitalWrite(R1G,LOW); 
  digitalWrite(R2G,LOW);
  digitalWrite(R4G,LOW);
}

void road4()
{
  digitalWrite(R4R,LOW); //State of Road no 4
  digitalWrite(R4G,HIGH);
  digitalWrite(R1R,HIGH);
  digitalWrite(R3R,HIGH);
  digitalWrite(R2R,HIGH);
  digitalWrite(R1G,LOW); 
  digitalWrite(R3G,LOW);
  digitalWrite(R2G,LOW);
}

void Low()
{
  digitalWrite(R1R,LOW); //Make all states Low
  digitalWrite(R1G,LOW);
  digitalWrite(R2R,LOW);
  digitalWrite(R2G,LOW);
  digitalWrite(R3R,LOW);
  digitalWrite(R3G,LOW); 
  digitalWrite(R4R,LOW);
  digitalWrite(R4G,LOW);
  
}
    
