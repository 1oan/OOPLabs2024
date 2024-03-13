#include <stdio.h>
#include "Math.h"

using namespace std;

int main()
{
    const char* num1 = "8";
    const char* num2 = "7";

    char* result = Math::Add(num1, num2);

    printf("Sum: %s\n", result);

}