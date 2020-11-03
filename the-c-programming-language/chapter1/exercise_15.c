#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float toCelsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32);
}

float toFahr(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

void main()
{
    float fahr, celsius;
    int lower, upper, step;

    fahr = LOWER;

    printf("Fahrenheit to Celius conversion: \n");
    while (fahr <= UPPER)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, toCelsius(fahr));
        fahr += STEP;
    }

    printf("\n\nCelsius to Fahrenheit conversion: \n");
    for(celsius = LOWER; celsius <= UPPER; celsius += STEP)
        printf("%3.0f %5.0f\n", celsius, toFahr(celsius));   
}