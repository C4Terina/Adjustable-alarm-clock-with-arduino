# Adjustable countdown
An adjustable countdown alarm with a LCD display, buzzer and leds for my embedded systems lab

## Hardware requirements 
* Arduino Uno
* Breadboard 
* 3 LEds 
* 3 220Ω resistors 
* 3 Buttons 
* 3 10kΩ resistors 
* Piezo buzzer
* I2C LCD 
* Wires 
* LM35 temperature sensor (optional obviously, only used for the purpose of the exercise) 

## Schematic in tinkercad 


![t725](https://user-images.githubusercontent.com/68371827/215137254-e6073554-560b-4c16-8df1-eee8bd74a118.png)

I ended up wiring the buttons to the analog inputs A1, A2 and A3. 

## Detailed description 
The alarm clock has 3 buttons. One is to start the countdown, the other is to add time and the last is to substract time. Every button has it's own LED as well. The StartLedPin and buzzerpin only activate when the countdown is over. 
