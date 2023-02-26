#include<LiquidCrystal.h>
const int trigger = 6;
const int echo = 9;
const int buzzer = 10;
int count = 0;
long duration = 0;
int distance = 0;
LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(buzzer, OUTPUT);
lcd.begin(16,2);
lcd.clear();
}
void loop()
{
lcd.clear();
digitalWrite(trigger,HIGH);
delayMicroseconds(1000);
digitalWrite(trigger,LOW);
delayMicroseconds(10);
duration = pulseIn(echo,HIGH);
distance = (duration/2)/29.1;
delay(100);
if (distance<25)
 {
tone(buzzer,2000);
count++;
 }
else
noTone(buzzer); 
lcd.clear();
lcd.print("DISTANCE:");
lcd.print(distance);
lcd.print("cm");
lcd.setCursor(0,1);
lcd.print("no. of object:");
lcd.print(count);
delay(1000);
Serial.print("DISTANCE");
Serial.print(distance);
Serial.print("cm");
delay(1000);
 }

