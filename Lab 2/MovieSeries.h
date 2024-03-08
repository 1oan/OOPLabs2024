#pragma once
#include "Movie.h"
class MovieSeries
{
	int count;
	Movie* Movies[16];
public:
	void init();
	void add(Movie* A);
	void sort();
	void print();
};

