#include <stdio.h>

using namespace std;

float operator"" _Fahrenheit(unsigned long long int x)
{
	return (x - 32) / 1.8;
}

float operator"" _Kelvin(unsigned long long int x)
{
	return x - 273.15;
}

int main()
{
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
	printf("Valoarea din Kelvin in Celsius este %f\n", a);
	printf("Valoarea din Fahrenheit in Celsius este %f\n", b);
	return 0;
}