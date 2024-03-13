#include "Movie.h"

void Movie::set_name(const char* name)
{
	strcpy(nume, name);
}

const char* Movie::GetName()
{
	return nume;
}

void Movie::set_year(int an)
{
	an_lansare = an;
}

int Movie::get_year()
{
	return an_lansare;
}

void Movie::set_score(float score)
{
	scor = score;
}

float Movie::get_score()
{
	return scor;
}

void Movie::set_length(int length)
{
	lungime = length;
}

int Movie::get_length()
{
	return lungime;
}

int Movie::get_passed_years()
{
	return 2024 - get_year();
}

