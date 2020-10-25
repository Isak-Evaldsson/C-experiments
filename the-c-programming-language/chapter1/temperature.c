#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* Prints a Fahrenheit-Celsius table, chapter 1 exercise 3-5 */
void main()
{
    float fahr, celsius;
    int lower, upper, step;

    fahr = LOWER;

    printf("Fahrenheit to Celius conversion: \n");
    while (fahr <= UPPER)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += STEP;
    }

    printf("\n\nCelius to Fahrenheit conversion: \n");
    for(celsius = LOWER; celsius <= UPPER; celsius += STEP)
        printf("%3.0f %5.0f\n", celsius, (9.0 / 5.0) * celsius + 32);   
}