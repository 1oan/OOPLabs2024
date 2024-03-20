#pragma once
class Sort
{
    // add data members
    int* vector;
    int count;
public:
    // add constuctors
    Sort(int n, int min, int max);
    Sort(int n): vector(new int[n] { 7,5,6,9 } ) { }
    Sort(int* v, int n);
    Sort(int n, ...);
    Sort(char* s);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};