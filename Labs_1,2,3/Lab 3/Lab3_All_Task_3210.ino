#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>

//Set Pins//
const int buttonPin = 2;
const int redPin = 5;
const int greenPin = 4;

//Volatile// 
volatile unsigned long secCount = 0;
volatile bool greenState = false;
volatile unsigned int t2Div = 0;

// Task1 ISR of 1hz//
ISR(TIMER1_COMPA_vect){
  greenState = !greenState;
  digitalWrite(greenPin, greenState? HIGH : LOW);
  secCount++;
}

// Task 2 ISR//
ISR(TIMER2_COMPA_vect){
  t2Div++;
  if(t2Div >= 100)
  {
    t2Div = 0;
    int b = digitalRead(buttonPin);
    //Pushed when pullup is low//
    if(b == LOW) digitalWrite(redPin, HIGH);
    else digitalWrite(redPin, LOW);
  }
}

void setupTimer1_1hz(){
  // Timer 1 ctc 1hz and 15625 ticks/sec//
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 15624;

  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);

  interrupts();
}

 // Timer 2 counts at 1000hz, making the new 10hz also 250khz//
void setupTimer2_1khz(){
  noInterrupts();

  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;

  TCCR2A |= (1 << WGM21);
  OCR2A = 249;

  TCCR2B |= (1 << CS22);
  TIMSK2 |= (1 << OCIE2A);

  interrupts();
}

void setup(){
  Serial.begin(9600);
// On & Off//
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, LOW);

  setupTimer1_1hz();
  setupTimer2_1khz();

  Serial.println("started");
}

void loop(){
  static unsigned long lastPrint = 0;
  unsigned long nowSec;
  noInterrupts();
  nowSec = secCount;
  interrupts();
  if(nowSec - lastPrint >= 3)
  {
    lastPrint = nowSec;
    Serial.println("Heyyy (every 3 sec)");
  }

  delay(10);
}