#include <cstring>
#include "GlobalExtra.h"

int movie_compare_name(Movie *A, Movie *B)
{
	return strcmp(A->GetName(), B->GetName());
}

int movie_compare_year(Movie *A, Movie *B)
{
	if (A->get_year() > B->get_year()) return 1;
	else if (A->get_year() > B->get_year()) return 0;
	return -1;
}

int movie_compare_score(Movie *A, Movie *B)
{
	if (A->get_score() > B->get_score()) return 1;
	else if (A->get_score() > B->get_score()) return 0;
	return -1;
}

int movie_compare_length(Movie *A, Movie *B)
{
	if (A->get_length() > B->get_length()) return 1;
	else if (A->get_length() > B->get_length()) return 0;
	return -1;
}

int movie_compare_passed_years(Movie *A, Movie *B)
{
	if (A->get_passed_years() > B->get_passed_years()) return 1;
	else if (A->get_passed_years() > B->get_passed_years()) return 0;
	return -1;
}
