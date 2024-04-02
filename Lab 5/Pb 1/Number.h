#pragma once
class Number
{
	// add data members
	int base = 0;
	char* value;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(const char* value);
	Number(int numar);
	~Number();

	// add operators and copy/move constructor
	Number(const Number& num);
	Number(Number&& num);

	friend Number operator+(Number num1, Number num2);
	friend Number operator-(Number num1, Number num2);

	Number& operator+=(const Number& num);

	bool operator<(Number num);
	bool operator>(Number num);
	bool operator<=(Number num);
	bool operator>=(Number num);
	bool operator==(Number num);

	void operator--();
	void operator--(int);

	int operator[](int index);

	Number& operator=(Number&& num);
	Number& operator=(int num);
	Number& operator=(const char * num);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};