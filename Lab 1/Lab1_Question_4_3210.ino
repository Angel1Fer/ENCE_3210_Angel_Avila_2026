//set up variables//
#define redLed   5
#define greenLed 4
#define blueLed  11

//Global array, the array being sereached//
char letter_array[] = {'R', 'G', 'B', 'R', 'R', 'G', 'B', 'B', 'G'};
int array_size = sizeof(letter_array) / sizeof(letter_array[0]);

void setup(){
    Serial.begin(9600);

    //set Led pins//
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed, OUTPUT);

    //counter for each letter//
    int r_count = 0;
    int g_count = 0;
    int b_count = 0;

    //loop through array//
    for (int i = 0; i < array_size; i++){
        //check for "R"//
        if (letter_array[i] == 'R')
        {
            r_count++;
            digitalWrite(redLed, HIGH);
        }

        //check for "G"//
        else if (letter_array[i] == 'G')
        {
            g_count++;
            digitalWrite(greenLed, HIGH);
        }

        //check for "B"//
        else if (letter_array[i] == 'B')
        {
            b_count++;
            digitalWrite(blueLed, HIGH);
        }
    }

    //print results//
    Serial.print("R count: ");
    Serial.println(r_count);

    Serial.print("G count: ");
    Serial.println(g_count);

    Serial.print("B count: ");
    Serial.println(b_count);
}

void loop(){

}
