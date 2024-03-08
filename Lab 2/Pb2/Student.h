#pragma once
class Student
{
	const char* nume;
	float mate, eng, ist, medie;
public:
	void SetName(const char *name);
	const char* GetName();
	void SetMate(float nota);
	float GetMate();
	void SetEng(float nota);
	float GetEng();
	void SetIst(float nota);
	float GetIst();
	float GetAvg();
};

