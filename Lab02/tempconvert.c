# include <stdio.h>

float fahrenheit2celsius(float fFahrenheitIn)
{
    float fCelsius = (fFahrenheitIn - 32) * 5 / 9;

    return fCelsius;
}

float celsius2fahrenheit(float fCelsiusIn)
{
	float fFahrenheit = (fCelsiusIn * 9 / 5) + 32;

	return fFahrenheit;
}

int main(void)
{
    float fCelsius = 0;
    float fFahrenheit = 0;
    int selection = 0;

    do 
   {
    printf("\nWelcome to the Temperature Converter!\n");
    printf("Please select one of the following options:\n");
    printf("1. Convert from Fahrenheit to Celsius\n");
    printf("2. Convert from Celsius to Fahrenheit\n");
    printf("3. Exit the Converter\n");

    scanf("%d", &selection);

    if (selection == 1)
    {
        float temperature = 0.0;

        printf("Enter a temperature in Fahrenheit: ");
        scanf("%f", &temperature);

        fCelsius = fahrenheit2celsius(temperature);
        printf("%.2f degrees Celsius\n", fCelsius);
    }
    else if (selection == 2)
    {
        float temperature = 0.0;

        printf("Enter a temperature in Celsius: ");
        scanf("%f", &temperature);

	fFahrenheit = celsius2fahrenheit(temperature);
	printf("%.2f degrees Fahrenheit\n", fFahrenheit);
    }
    else
    {
        printf("Goodbye!\n");
        return 0;
    }
   }
while(selection != 3);


}
