//count array//
int countPattern(int data[], int dataSize, int pattern[]){
    int count = 0;

    for (int i = 0; i <= dataSize - 3; i++)
    {
        int match = 1;

        if (data[i] != pattern[0])
        {
            match = 0;
        }
        if (data[i + 1] != pattern[1])
        {
            match = 0;
        }
        if (data[i + 2] != pattern[2])
        {
            match = 0;
        }

        if (match == 1)
        {
            count = count + 1;
        }
    }

    return count;
}

//set Led//
void setLedState(int patternCount, int *greenLed, int *redLed){
    if (patternCount > 0)
    {
        *greenLed = 1;
        *redLed = 0;
    }
    else
    {
        *greenLed = 0;
        *redLed = 1;
    }
}

int main(void){
    //Main array//
    int data[] = {1, 2, 3, 5, 1, 2, 3, 9, 1, 2, 3};
    int dataSize = (int)(sizeof(data) / sizeof(data[0]));

    int pattern[3] = {1, 2, 3};

    int patternCount = 0;

    int greenLed = 0;//Led//
    int redLed = 0;

    patternCount = countPattern(data, dataSize, pattern); //counting// 

    setLedState(patternCount, &greenLed, &redLed);

    if (greenLed == 1)
    {
        printf("Green Led: on\n");
    }
    else
    {
        printf("Green Led: off\n");
    }

    if (redLed == 1)
    {
        printf("Red Led: on\n");
    }
    else
    {
        printf("Red Led: off\n");
    }

    //countint//
    printf("Pattern counts: %d\n", patternCount);

    return 0;
}