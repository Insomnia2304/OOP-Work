#pragma once
class Sort
{
    // add data members
    int* v;
    int numberOfElements;
public:
    // add constuctors
    Sort(int numberOfElements, int minElement, int maxElement);
    Sort(int numberOfElements, int* v);
    Sort(int numberOfElements, ...);
    Sort(char* c);
    Sort();
    ~Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(int left, int right, bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};