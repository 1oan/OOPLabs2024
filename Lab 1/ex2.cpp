#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct S
{
    char s[100];
    int length;
}A[100];

int lungime(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

int litera(char c)
{
    if (c >= 'a' && c <= 'z') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    return 0;
}

void Desparte(char s[], S A[], int &len)
{
    int n, k, m;
    n = lungime(s);
    k = len = m = 0;
    for (int i = 0; i < n; i++)
        if (litera(s[i]))
        {
            k++;
            if (s[i + 1] == '\0')
            {
                for (int j = i - k + 1; j <= i; j++)
                    A[len].s[m++] = s[j];
                A[len].length = k;
                len++;
                m = k = 0;
            }
        }
        else if (!litera(s[i]) && k > 0)
        {
            for (int j = i - k; j < i; j++)
                A[len].s[m++] = s[j];
            A[len].length = k;
            len++;
            m = k = 0;
        }
}

int strcomp(char *s, char *t)
{
    while (*s != 0 && *s == *t)
    {
        s++;
        t++;
    }
    return *s - *t;
}

void Sort(S A[], int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if (A[i].length < A[j].length)
            {
                S aux = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
            else if (A[i].length == A[j].length)
            {
                int comp = strcomp(A[i].s, A[j].s);
                if (comp > 0)
                {
                    S aux = A[i];
                    A[i] = A[j];
                    A[j] = aux;
                }
            }
}

char s[100];
int n;

int main()
{
    scanf("%[^\n]s", s);
    Desparte(s, A, n);
    Sort(A, n);
    for (int i = 0; i < n; i++)
        printf("%s\n", A[i].s);
    return 0;
}