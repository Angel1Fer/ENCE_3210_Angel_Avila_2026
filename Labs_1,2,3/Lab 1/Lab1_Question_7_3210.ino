//Gpt was used// 

//Global varible// 
#define size 10
//print// 
void printLeds(int redLed, int greenLed, int blueLed){
    printf("leds -> r:%d g:%d b:%d\n", redLed, greenLed, blueLed);
}

void doCalc(int a[], int b[], int c[], int op){
    for (int i = 0; i < size; i++)  //starts the opperator// 
    {
        if (op == 1)
        {
            c[i] = a[i] + b[i];
        }
        else if (op == 2)
        {
            c[i] = a[i] - b[i];
        }
        else if (op == 3)
        {
            c[i] = a[i] * b[i];
        }
        else
        {
            c[i] = 0;
        }
    }
}

void printArray(int x[]){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int main(void){
    //1st & 2nd arrays//
    int arr1[size] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[size] = {10,9,8,7,6,5,4,3,2,1};

    //3rd array//
    int arr3[size] = {0,0,0,0,0,0,0,0,0,0};

    int pressCount = 0;  //Button count//
    int op = 0;          //Changes op//

    int redLed = 0;
    int greenLed = 0;
    int blueLed = 0;

    int choice = 0;

    printf("button1 = pick operation\n");
    printf("button2 = run operation on arrays\n");
    printf("type 1 or 2, then enter\n\n");

    while (1){
        scanf("%d", &choice);

        //1st button func//
        if (choice == 1)
        {
            pressCount = pressCount + 1;

            if (pressCount > 3)
            {
                pressCount = 1;
            }

            op = pressCount;

            //Set leds//
            redLed = 0;
            greenLed = 0;
            blueLed = 0;

            if (op == 1){
                redLed = 1;   //Adding//
                printf("Operation: add\n");
            }
            else if (op == 2){
                greenLed = 1; //Subtract//
                printf("Operation: sub\n");
            }
            else{
                blueLed = 1;  //Multi//
                printf("Oeration: mult\n");
            }

            printLeds(redLed, greenLed, blueLed);
        }

        //Button 2 func//
        if (choice == 2){
            if (op == 0)
            {
                printf("pick an operation first (press button 1)\n");
            }
            else
            {
                //button 2 pressed//
                redLed = 0;
                greenLed = 0;
                blueLed = 0;
                printLeds(redLed, greenLed, blueLed);

                doCalc(arr1, arr2, arr3, op);

                //ending//
                redLed = 1;
                greenLed = 1;
                blueLed = 1;
                printLeds(redLed, greenLed, blueLed);

                printf("arr1: ");
                printArray(arr1);
                printf("arr2: ");
                printArray(arr2);
                printf("arr3: ");
                printArray(arr3);
            }
        }
    }

    return 0;
}