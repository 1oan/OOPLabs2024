#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int string_to_int(char s[])
{
    int result = 0;
    for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++)
        result = result * 10 + (s[i] - '0');
    return result;
}

int main()
{
    FILE* file;
    char line[100];
    int sum = 0;
    file = fopen("in.txt", "r");

    if (file == NULL)
    {
        printf("Eroare\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file))
        sum += string_to_int(line);

    fclose(file);
    printf("%d\n", sum);

    return 0;
}