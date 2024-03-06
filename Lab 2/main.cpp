#include <stdio.h>
#include "NumberList.h"

using namespace std;

int main()
{
	NumberList L;
	L.Init(); // initializare
	L.Add(8);
	L.Add(85);
	L.Add(28);
	L.Add(812);
	L.Add(8555);	// adaugam elemente	
	L.Add(81);
	L.Add(80);
	L.Add(18);
	L.Print(); // afisam elementele adaugate
	L.Sort(); // sortam elementele
	L.Print(); // afisam elementele dupa sortare
}