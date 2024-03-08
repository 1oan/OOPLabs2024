#include <stdio.h>
#include "MovieSeries.h"
#include "Movie.h"

void MovieSeries::init()
{
	count = 0;
}

void MovieSeries::add(Movie* A)
{
	if (count >= 16)
	{
		printf("Frate, nu mai e loc!");
		return;
	}
	Movies[count++] = A;
}

void MovieSeries::sort()
{
	for(int i = 0; i < count - 1; i++)
		for(int j = i + 1; j < count; j++)
			if (Movies[i]->get_passed_years() < Movies[j]->get_passed_years())
			{
				Movie *aux;
				aux = Movies[i];
				Movies[i] = Movies[j];
				Movies[j] = aux;
			}
}

void MovieSeries::print()
{
	for (int i = 0; i < count; i++)
		printf("%s %d %g %d %d\n", Movies[i]->GetName(), Movies[i]->get_year(), Movies[i]->get_score(), Movies[i]->get_length(), Movies[i]->get_passed_years());
}
