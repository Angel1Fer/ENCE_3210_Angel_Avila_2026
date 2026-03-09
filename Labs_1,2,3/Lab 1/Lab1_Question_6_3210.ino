void showLed(char *name){
    printf("%s\n", name);
}
//makes leds on//
void runSequenceOnce(void){
    showLed("r");
    showLed("rg");
    showLed("rgb");
    showLed("gb");
    showLed("b");
    showLed("rb");
}

int main(void){
    int running = 0;
    int input = 0;
//starts the program//
    printf("press 1 then enter to start\n");
    printf("press 1 then enter again to stop\n\n");

    while (1)
    {
        scanf("%d", &input);

        if (input == 1)
        {
            if (running == 0)
            {
                running = 1;

                while (running == 1)
                {
                    runSequenceOnce();

                    //press button//
                    scanf("%d", &input);
                    if (input == 1)
                    {
                        running = 0;
                    }
                }
            }
            else
            {
                running = 0;
            }
        }
    }

    return 0;
}\