#include "Student.h"

void Student::SetName(const char *name)
{
	nume = name;
}

const char* Student::GetName()
{
	return nume;
}

void Student::SetMate(float nota)
{
	mate = nota;
}

float Student::GetMate()
{
	return mate;
}

void Student::SetEng(float nota)
{
	eng = nota;
}

float Student::GetEng()
{
	return eng;
}

void Student::SetIst(float nota)
{
	ist = nota;
}

float Student::GetIst()
{
	return ist;
}

float Student::GetAvg()
{
	return (mate + eng + ist) / 3;	
}

