#include <iostream>
#include "Student.h"
#include "Global.h"

using namespace std;

int main()
{
	Student s1;
	s1.SetName("Adrian Iftene");
	s1.SetMate(9.53);
	s1.SetEng(10);
	s1.SetIst(8.79);
	Student s2;
	s2.SetName("Vlad Radulescu");
	s2.SetMate(7.53);
	s2.SetEng(7);
	s2.SetIst(9.79);

	printf("valoare functiei student_compare_name este: %d \n", student_compare_name(&s1, &s2));
	printf("valoare functiei student_compare_mate este: %d \n", student_compare_mate(&s1, &s2));
	printf("valoare functiei student_compare_ist este: %d \n", student_compare_ist(&s1, &s2));
	printf("valoare functiei student_compare_eng este: %d \n", student_compare_eng(&s1, &s2));
	printf("valoare functiei student_compare_med este: %d \n", student_compare_med(&s1, &s2));
}