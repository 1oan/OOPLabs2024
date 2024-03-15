#include <stdio.h>
#include "Math.h"

using namespace std;

int main()
{

    printf("Suma dintre 10 si 7 este : %d\n", Math::Add(10, 7));
    printf("Suma dintre 10, 7 si 2 este : %d\n", Math::Add(10, 7, 2));
    printf("Suma dintre 10.3 si 7.2 este : %d\n", Math::Add(10.3, 7.2));
    printf("Suma dintre 10.3, 7.2 si 2.8 este : %d\n", Math::Add(10.3, 7.2, 2.8));
    printf("Produsul numerelor 10 si 7 este : %d\n", Math::Mul(10, 7));
    printf("Produsul numerelor 10, 7 si 3 este : %d\n", Math::Mul(10, 7, 3));
    printf("Produsul numerelor 10.6 si 7.4 este : %d\n", Math::Mul(10.6, 7.4));
    printf("Produsul numerelor 10.6, 7.4 si 9.8 este : %d\n", Math::Mul(10.6, 7.4, 9.8));
    printf("Suma dintre 1,2,3,4,5,6,7,8,9,10 este : %d\n", Math::Add(10,1,2,3,4,5,6,7,8,9,10));
    printf("Suma dintre 10794543289 si 9431218465 este : %s\n", Math::Add("10794543289", "9431218465"));

}