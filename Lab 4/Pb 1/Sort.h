#pragma once
class Sort
{
    // add data members
    int* vector;
    int count;
public:
    // add constuctors
    Sort(int n, int min, int max);
    Sort();
    Sort(int* v, int n);
    Sort(int n, ...);
    Sort(const char* s);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};