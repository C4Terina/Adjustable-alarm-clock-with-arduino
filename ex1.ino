#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>

//Set the LCD address to 0x27 for a 16 char and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buzzerPin = 2;

const int StartButtonPin = A1;
const int AddButtonPin = A2;
const int SubstractButtonPin = A3;

bool min_flag = true;
bool run = true;

const int StartLedPin = 9;
const int AddLedPin = 8;
const int SubstractLedPin = 7;

int Min = 0;
int sec = 59;
int snooze = 0;
boolean minb = false;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  //buzzer stuff
  pinMode(buzzerPin, OUTPUT);
  
  pinMode(StartButtonPin, INPUT_PULLUP);
  pinMode(AddButtonPin, INPUT_PULLUP);
  pinMode(SubstractButtonPin, INPUT_PULLUP);
  
  
  pinMode(StartLedPin, OUTPUT); 
  pinMode(AddLedPin, OUTPUT);
  pinMode(SubstractLedPin, OUTPUT);
  
  pinMode(buzzerPin, OUTPUT);
  noTone(buzzerPin);  

  //lcd stuff
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("C4Terina");

  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = voltage*100;


  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C");
  delay(5000); 
  lcd.clear(); 

  lcd.setCursor(0,0);
  lcd.print("Please set time");
  lcd.setCursor(0,1);
  lcd.print("Minutes:");

}

// the loop routine runs over and over again forever:
void loop() {
    if(digitalRead(AddButtonPin) == HIGH){
      digitalWrite(AddLedPin, HIGH);
      Min = Min + 1;
      lcd.setCursor(0,0);
      lcd.print("Please set time");
      lcd.setCursor(0,1);
      lcd.print("Minutes:");
      lcd.print(Min);
      delay(500);
      digitalWrite(AddLedPin, LOW);
    } 
    if (digitalRead(SubstractButtonPin) == HIGH && Min > 0 ){
      digitalWrite(SubstractLedPin, HIGH);
      Min = Min - 1;
      lcd.setCursor(0,0);
      lcd.print("Please set time");
      lcd.setCursor(0,1);
      lcd.print("Minutes:");
      lcd.print(Min);
      delay(300);
      digitalWrite(SubstractLedPin, LOW);
    }
  if(digitalRead(StartButtonPin) == HIGH && Min > 0 && Min <= 10){
    if(Min != 0){
        Min = Min - 1;
    }
      while(min_flag){        
        lcd.clear();
        lcd.setCursor(5,0);
        lcd.print(Min);
        lcd.print(":");
        lcd.print(sec);
        sec = sec - 1;
        if(sec % 10 == 0 && snooze != 5){
          tone(buzzerPin, 500); // Send 1KHz sound signal...
          delay(1000);        // ...for 1 sec
          noTone(buzzerPin);     // Stop sound...
          delay(1000);        // ...for 1sec
          snooze = snooze + 1;
        }
        delay(1000);
        
        if(Min == 0 && sec == 0){
          lcd.clear();
          lcd.setCursor(5,0);
          lcd.print("0:0");
          tone(buzzerPin, 500); // Send 1KHz sound signal...
          delay(1000);        // ...for 1 sec
          noTone(buzzerPin);     // Stop sound...
          delay(1000);        // ...for 1sec
          digitalWrite(StartLedPin, HIGH);
          min_flag = false;
        } 
       
        if(sec == 0 ){
          sec = 59;
        } 
        if(Min != 0){
          Min = Min - 1;
        }
      }
      
  }
}



