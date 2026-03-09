//Global & constant Variables// 
const int button1Pin = 2;
const int button2Pin = 3;
const int redPin   = 5;
const int greenPin = 4;

volatile int running = 0;
volatile unsigned long lastUs = 0;

int stepIndex = 0; 

void setLeds(int r, int g)
{
  //write pins// 
  digitalWrite(redPin, r);
  digitalWrite(greenPin, g);
}

void toggleRunIsr()
{
  //taking it from Q1//
  unsigned long now = micros();
  if (now - lastUs > 20000) 
  {
    running = !running;
    lastUs = now;
  }
}

//wait time// 
void waitMs(int ms)
{
  for (int i = 0; i < ms; i += 10)
  {
    if (!running) return;
    delay(10);
  }
}

//simulating Blue// 
void doStep(int s)
{
  if (s == 0)
  {
    //red//
    setLeds(HIGH, LOW);
    waitMs(250);
  }
  else if (s == 1)
  {
    //red & green// 
    setLeds(HIGH, HIGH);
    waitMs(250);
  }
  else if (s == 2)
  {
    //RGB//
    for (int i = 0; i < 4 && running; i++)
    {
      setLeds(HIGH, HIGH);
      delay(100);
      setLeds(LOW, LOW);
      delay(100);
    }
  }
  else if (s == 3)
  {
    //green & blue//
    for (int i = 0; i < 3 && running; i++)
    {
      setLeds(LOW, HIGH);
      delay(100);
      setLeds(HIGH, HIGH); //flash red// 
      delay(100);
    }
  }
  else if (s == 4)
  {
    //blue//
    for (int i = 0; i < 2 && running; i++)
    {
      setLeds(HIGH, HIGH);
      delay(120);
      setLeds(LOW, LOW);
      delay(120);
    }
  }
  else if (s == 5)
  {
    //red & blue// 
    for (int i = 0; i < 3 && running; i++)
    {
      setLeds(HIGH, LOW);
      delay(100);
      setLeds(HIGH, HIGH); //gren flash//
      delay(100);
    }
  }
}

void setup()
{
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  setLeds(LOW, LOW);

  //using falling to detect high to low// 
  attachInterrupt(digitalPinToInterrupt(button1Pin), toggleRunIsr, FALLING);
  attachInterrupt(digitalPinToInterrupt(button2Pin), toggleRunIsr, FALLING);
}

void loop()
{
  if (!running)
  {
    setLeds(LOW, LOW);
    stepIndex = 0;
    return;
  }

  //run sequence//
  doStep(stepIndex);

  stepIndex++;
  if (stepIndex > 5) stepIndex = 0;
}