#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	Sort A; // constructoru cu lista de initializare
	A.Print();
	A.QuickSort(true);
	A.Print();
	cout << "\n\n\n";

	Sort B(5, 7, 6, 9, 5, 8);
	B.BubbleSort(true);
	B.Print();
	cout << "\n\n\n";

	
	Sort C("87,46,96,32,45,111,52,87,54,13,84,555,4923,42");
	C.InsertSort(true);
	C.Print();
	cout << C.GetElementsCount() << "\n";
	cout << "\n\n\n";
	
	int* v, n;
	v = new int[12] {7, 6, 1, 8, 2, 8, 2, 78, 159, 7, 6};
	n = 11;
	Sort D(v, n);
	D.QuickSort();
	D.Print();
	cout << D.GetElementFromIndex(7) << "\n";
	cout << "\n\n\n";

	Sort E(10, 55, 1254);
	E.Print();
	E.QuickSort();
	E.Print();
	
}