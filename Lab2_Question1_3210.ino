//Global variables & constants// 
const int button1Pin = 2;
const int button2Pin = 3;
const int redPin   = 5;
const int greenPin = 4;

volatile long button1Count = 0;
volatile long button2Count = 0;
volatile long diffCount = 0;
volatile unsigned long lastUs1 = 0;
volatile unsigned long lastUs2 = 0;

void setLeds(int r, int g){
  digitalWrite(redPin, r);
  digitalWrite(greenPin, g);
}
  // used GPT to help set up Int// 
void button1Isr(){
   unsigned long now = micros();
  if (now - lastUs1 > 20000) 
  {
    button1Count++;
    lastUs1 = now;
  }
}


void button2Isr(){
  unsigned long now = micros();
  if (now - lastUs2 > 20000) 
  {
    button2Count++;
    lastUs2 = now;
  }
}

//seting up pins// 
void setup(){
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  setLeds(LOW, LOW);

  attachInterrupt(digitalPinToInterrupt(button1Pin), button1Isr, FALLING);
  attachInterrupt(digitalPinToInterrupt(button2Pin), button2Isr, FALLING);
}

void loop(){
  long b1, b2, d;

  noInterrupts();
  b1 = button1Count;
  b2 = button2Count;
  interrupts();

  d = b1 - b2;

  noInterrupts();
  diffCount = d;   
  interrupts();

  if (d > 0)
  {
    //first case// 
    setLeds(HIGH, LOW); //red on & green off//
  }
  else if (d < 0)
  {
    //2nd case//
    setLeds(LOW, HIGH); //red off & green on//
  }
  else
  {
    //3rd case, both// 
    setLeds(HIGH, HIGH);  //both r on//
  }

  delay(100);
}