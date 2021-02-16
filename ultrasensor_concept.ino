 
#include <Wire.h>
#include <LiquidCrystal.h> 




#define trigPin 13
#define echoPin 12
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
   double alpha=0.75;
   int period=20;
   double refresh=0.0;
   
void setup(void)
{
   pinMode(trigPin,OUTPUT);
   pinMode(echoPin,INPUT); 
   pinMode(A0,INPUT);
   lcd.begin(16,2);
 
   lcd.clear();
   lcd.setCursor(0,0);
}

void loop(void)
{
   static double oldValue=0;
   static double oldrefresh=0;
   long duration, distance;
 
   int beat=analogRead(A0);
  
   double value=alpha*oldValue+(0-alpha)*beat;
   refresh=value-oldValue;
  
  
 
   lcd.setCursor(0,0);
   lcd.print(" Heart Monitor (BPM) is : "); 
   lcd.setCursor(0,1);
   lcd.print("          ");
   lcd.setCursor(0,1); 
   lcd.print(beat/3 );
   oldValue=value;
   oldrefresh=refresh;
   delay(period*10); 

   digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance <= 100){ 
tone(9,400,100);
}
else {
noTone(9);
}
delay(50);

  
}
