//Global & constant variables//
const int button1Pin = 2;  
const int button2Pin = 3;   
const int redPin   = 5;
const int greenPin = 4;

volatile long button1Count = 0;   
volatile long button2Count = 0;   
volatile unsigned long lastUs1 = 0;
volatile unsigned long lastUs2 = 0;

//arrays set up// 
int arr1[10] = { 1,2,3,4, 5, 6,7,8,9,10 };
int arr2[10] = { 10,9,8,7,6,5,4,3,2,1 };
int arr3[10]; // results go here

//led setup// 
void setLeds(int r, int g){
  digitalWrite(redPin, r);
  digitalWrite(greenPin, g);
}

//button1 int//
void button1Isr(){
  unsigned long now = micros();
  if (now - lastUs1 > 20000) 
  {
    button1Count++;
    lastUs1 = now;
  }
}

//button2 int//
void button2Isr(){
  unsigned long now = micros();
  if (now - lastUs2 > 20000) //20ms debounce-used Gpt//
  {
    button2Count++;
    lastUs2 = now;
  }
}

void setup(){
  Serial.begin(9600);

  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  setLeds(LOW, LOW);

  attachInterrupt(digitalPinToInterrupt(button1Pin), button1Isr, FALLING);
  attachInterrupt(digitalPinToInterrupt(button2Pin), button2Isr, FALLING);

  Serial.println("calculator ready:");
  Serial.println("button1: press 1/2/3 times to pick add/sub/mul");
  Serial.println("button2: press once to run the operation");
}

void loop(){
  static long lastB2 = 0; //detect new press//
  long b1, b2;

//count//
  noInterrupts();
  b1 = button1Count;
  b2 = button2Count;
  interrupts();

  int op = (int)(b1 % 3);

  //show selected choice//
  //both on is = blue//
  if (op == 1)
  {
    //add//
    setLeds(HIGH, LOW); //red//
  }
  else if (op == 2)
  {
    //subtract//
    setLeds(LOW, HIGH); //green//
  }
  else
  {
    //multi (0)//
    setLeds(HIGH, HIGH);  //blue//
  }

  if (b2 != lastB2)
  {
    lastB2 = b2;

    setLeds(LOW, LOW);

=    for (int i = 0; i < 10; i++)
    {
      if (op == 1)        arr3[i] = arr1[i] + arr2[i];  //add//
      else if (op == 2)   arr3[i] = arr1[i] - arr2[i];  //subtract//
      else                arr3[i] = arr1[i] * arr2[i];  //multi//
    }

    //the buttons are changing stuff but not correctly//
    Serial.println("arr3 results:");
    for (int i = 0; i < 10; i++)
    {
      Serial.print("arr3[");
      Serial.print(i);
      Serial.print("] = ");
      Serial.println(arr3[i]);
    }

    
    setLeds(HIGH, HIGH);

    delay(500); 
  }

  delay(10); 
}