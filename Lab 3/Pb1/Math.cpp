#include <cstring>
#include "Math.h"
#include <cstdarg>
using namespace std;

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	int sum = 0;
	va_list ptr;
	va_start(ptr, count);
	for (int i = 0; i < count; i++)
		sum += va_arg(ptr, int);
	va_end(ptr);
	return sum;
}

char* Math::Add(const char* a, const char* b)
{
	int alen, blen, maxlen, carry, sum, k, i, j;
	char* res;
	if(a == nullptr || b == nullptr)
		return nullptr;
	alen = strlen(a);
	blen = strlen(b);
	maxlen = alen > blen ? alen : blen;
	res = new char[maxlen + 2];
	res[maxlen + 1] = '\0';
	carry = 0;
	i = alen - 1;
	j = blen - 1;
	k = maxlen;
	while (i >= 0 || j >= 0) 
	{
		sum = carry;
		if (i >= 0)
			sum += a[i--] - '0';
		if (j >= 0)
			sum += b[j--] - '0';

		res[k--] = (sum % 10) + '0';
		carry = sum / 10;
	}
	if (carry > 0) 
	{
		res[0] = carry + '0';
		return res;
	}
	return &res[1];


}
