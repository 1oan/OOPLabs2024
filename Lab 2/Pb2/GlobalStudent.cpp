#include <cstring>
#include "Global.h";

int student_compare_name(Student* A, Student* B)
{
	return strcmp(A->GetName(), B->GetName());
}

int student_compare_mate(Student* A, Student* B)
{
	if (A->GetMate() > B->GetMate()) return 1;
	else if (A->GetMate() == B->GetMate()) return 0;
	return -1;
}

int student_compare_ist(Student* A, Student* B)
{
	if (A->GetIst() > B->GetIst()) return 1;
	else if (A->GetIst() == B->GetIst()) return 0;
	return -1;
}

int student_compare_eng(Student* A, Student* B)
{
	if (A->GetEng() > B->GetEng()) return 1;
	else if (A->GetEng() == B->GetEng()) return 0;
	return -1;
}

int student_compare_med(Student* A, Student* B)
{
	if (A->GetAvg() > B->GetAvg()) return 1;
	else if (A->GetAvg() == B->GetAvg()) return 0;
	return -1;
}
