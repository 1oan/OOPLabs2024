#pragma once
class Movie
{
	const char* nume;
	int an_lansare, lungime;
	float scor;
public:
	void set_name(const char* name);
	const char* GetName();
	void set_year(int an);
	int get_year();
	void set_score(float score);
	float get_score();
	void set_length(int length);
	int get_length();
	int get_passed_years();
};

