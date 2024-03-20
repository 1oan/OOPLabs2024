#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Sort.h"
#include <cstdarg>

Sort::Sort(int n, int min, int max)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		vector[i] = min + rand() % (max - min + 1);
	count = n;
}

Sort::Sort(int* v, int n)
{
	for (int i = 0; i < n; i++)
		vector[i] = v[i];
	count = n;
}

Sort::Sort(int n, ...)
{
	va_list(pr);
	va_start(pr, n);
	for (int i = 0; i < n; i++)
		vector[i] = va_arg(pr, int);
	va_end(pr);
	count = n;
}

int Cif(char ch)
{
	if (ch >= '1' && ch <= '9') return 1;
	return 0;
}

Sort::Sort(char* s)
{
	int nr;
	count = nr = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (Cif(s[i]))
			nr = nr * 10 + (s[i] - '0');
		else
		{
			vector[count++] = nr;
			nr = 0;
		}
	}
}

void Sort::InsertSort(bool ascending)
{
	int x, p;
	for (int i = 0; i < count; i++)
	{
		x = vector[i];
		p = i - 1;
		while (p >= 0 && vector[p] > x)
			vector[p + 1] = vector[p], p--;
		vector[p + 1] = x;
	}
	if (!ascending)
	{
		for (int i = 0; i < count / 2; i++)
			vector[i] = vector[count - i - 1];
	}
}

void Sort::BubbleSort(bool ascending)
{
	bool sortat = false;
	while (!sortat)
	{
		sortat = true;
		for(int i = 0; i < count - 1; i++)
			if (vector[i] > vector[i + 1])
			{
				int aux = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = aux;
				sortat = false;
			}
	}
	
}

void Sort::Print()
{
	for (int i = 0; i < count; i++)
		printf("%d",vector[i]);
}

int Sort::GetElementFromIndex(int index)
{
	if (index < 0 || index > count)
	{
		printf("La pozitia dorita nu exista un element in vector");
		return;
	}
	return vector[index];
}

int Sort::GetElementsCount()
{
	return count;
}