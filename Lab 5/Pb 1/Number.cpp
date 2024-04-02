#include "Number.h"
#include <stdio.h>

int strlen(const char* s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		;
	return i;
}

void strcpy(char* s, const char* t)
{
	int i, m;
	m = strlen(t);
	for (i = 0; i < m; i++)
		s[i] = t[i];
	s[i] = '\0';
}

char* fromDeci(int base, int n);

int toDeci(char* s, int base);

Number::Number(const char* value, int base)
{
	int size = strlen(value);
	this->value = new char[size + 1];
	strcpy(this->value, value);
	this->base = base;
}

Number::Number(const char* value)
{
	base = 10;
	strcpy(this->value, value);
}

Number::Number(int numar)
{
	base = 10;
	value = fromDeci(base, numar);
}

Number::~Number()
{
	delete[]value;
}

Number::Number(const Number& num)
{
	int size = strlen(num.value);
	value = new char[size + 1];
	strcpy(value, num.value);
	base = num.base;
}

Number::Number(Number&& num)
{
	int size = strlen(num.value);
	this->value = new char[size + 1];
	strcpy(this->value, num.value);
	base = num.base;
	num.value = nullptr;
}

Number& Number::operator+=(const Number& num)
{
	int max_base = base > num.base ? base : num.base;
	value = fromDeci(max_base, toDeci(value, base) + toDeci(num.value, num.base));
	base = max_base;
	return *this;
}

bool Number::operator<(Number num)
{
	return toDeci(this->value, this->base) < toDeci(num.value, num.base);
}

bool Number::operator>(Number num)
{
	return toDeci(this->value, this->base) > toDeci(num.value, num.base);
}

bool Number::operator<=(Number num)
{
	return toDeci(this->value, this->base) <= toDeci(num.value, num.base);
}

bool Number::operator>=(Number num)
{
	return toDeci(this->value, this->base) >= toDeci(num.value, num.base);
}

bool Number::operator==(Number num)
{
	return toDeci(this->value, this->base) == toDeci(num.value, num.base);
}

void Number::operator--()
{
	strcpy(value, (value + 1));
}

void Number::operator--(int)
{
	int size = strlen(value);
	value[size - 1] = '\0';
}

int val(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	else return ch - 'A' + 10;
}

int toDeci(char* s, int base)
{
	int len, pow, num;
	len = strlen(s);
	pow = 1;
	num = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		num += val(s[i]) * pow;
		pow *= base;
	}
	return num;
}

char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

char* fromDeci(int base, int n)
{
	char* rez;
	int len = 0, m;
	m = n;
	while (m > 0)
	{
		len++;
		m /= base;
	}
	rez = new char[len + 1];
	rez[len] = '\0';
	len--;

	while (n > 0)
	{
		rez[len--] = reVal(n % base);
		n /= base;
	}
	return rez;
}

int Number::operator[](int index)
{
	return value[index];
}

Number& Number::operator=(Number&& num)
{
	strcpy(value, num.value);
	base = num.base;
	return *this;
}

Number& Number::operator=(int num)
{
	if (base != 0)
		value = fromDeci(base, num);
	else
	{
		value = fromDeci(10, num);
		base = 10;
	}
	return *this;
}

Number& Number::operator=(const char* num)
{
	if (base != 0)
	{
		strcpy(value, num);
		value = fromDeci(base, toDeci(value, 10));
	}
	else
	{
		strcpy(value, num);
		base = 10;
	}
	return *this;
}

void Number::SwitchBase(int newBase)
{
	if (newBase != base)
	{
		int n = toDeci(value, this->base);
		value = fromDeci(newBase, n);
		base = newBase;
	}
}

void Number::Print()
{
	printf("%s\n", value);
}

int Number::GetDigitsCount()
{
	int count;
	for (count = 0; value[count] != '\0'; count++)
		;
	return count;
}

int Number::GetBase()
{
	return base;
}

Number operator+(Number num1, Number num2)
{
	int max_base = num1.base > num2.base ? num1.base : num2.base;
	Number result = num1;
	Number num2copy = num2;
	result.value = fromDeci(max_base, toDeci(result.value, result.base) + toDeci(num2copy.value,num2copy.base));
	result.SwitchBase(max_base);
	return result;
}

Number operator-(Number num1, Number num2)
{
	int max_base = num1.base > num2.base ? num1.base : num2.base;
	Number result = num1;
	Number num2copy = num2;
	result.value = fromDeci(max_base, toDeci(result.value, result.base) - toDeci(num2copy.value, num2copy.base));
	result.SwitchBase(max_base);
	return result;
}
