#pragma once
#include <iostream>
using namespace std;

class Compare
{
public:
	virtual int CompareElements(const void* e1, const void* e2) = 0; //ar trebui sa fie const, nu non-const ca in enunt
};

class CompareByMod3 : public Compare
{
public:
	int CompareElements(const void* e1, const void* e2)
	{
		//cout << *(int*)e1 << ' ' << *(int*)e2 << '\n';
		return (*(int*)e1) % 3 < (*(int*)e2) % 3 || (*(int*)e1) % 3 == (*(int*)e2) % 3 && (*(int*)e1) < (*(int*)e2);
	}
};

class Equal : public Compare
{
public:
	int CompareElements(const void* e1, const void* e2)
	{
		return *(int*)e1 == *(int*)e2;
	}
};

template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	int Size;
	T** Pointer;
public:
	ArrayIterator() : Current(0), Size(0), Pointer(nullptr) {}
	ArrayIterator(int Current, int Size, T** Pointer) : Pointer(Pointer) {
		if (Current < 0 || Current >= Size) throw("Iterator out of bounds!");
		this->Size = Size;
		this->Current = Current;
	}
	ArrayIterator& operator ++ () {
		if (Current + 1 == Size) throw("Iterator out of bounds!");
		Current++;
		return *this;
	}
	ArrayIterator& operator -- () {
		if (Current - 1 == -1) throw("Iterator out of bounds!");
		Current--;
		return *this;
	}
	bool operator=(ArrayIterator<T>& other) { 
		if (Pointer != other.Pointer) return 0;
		Size = other.Size;
		Current = other.Current;
		return 1;
	}
	bool operator!=(ArrayIterator<T>& other) {
		return !(Pointer == other.Pointer && Size == other.Size && Current == other.Current);
	}
	T* GetElement() {
		return Pointer[Current];
	}
};

template<class T>

class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
public:
	void print()
	{
		for (int i = 0; i < Size; i++)
			cout << *List[i] << ' ';
		cout << '\n';
	}
	Array() : Capacity(0), Size(0), List(nullptr) {} // Lista nu e alocata, Capacity si Size = 0
	~Array() // destructor
	{
		for (int i = 0; i < Capacity; i++)
			delete List[i];
		delete List;
	}
	Array(int capacity) : Capacity(capacity), Size(0) // Lista e alocata cu 'capacity' elemente
	{
		List = new T * [Capacity];
		for (int i = 0; i < Capacity; i++)
			List[i] = new T;
	}
	Array(const Array<T>& otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size)// constructor de copiere
	{
		List = new T * [Capacity];
		for (int i = 0; i < Capacity; i++)
		{
			List[i] = new T;
			*List[i] = *otherArray.List[i];
		}
	}
	T& operator[] (int index) // arunca exceptie daca index este out of range
	{
		if (index < 0 || index >= Size) throw("Index invalid!");
		return *List[index];
	}

	const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
	{
		if (Size + 1 > Capacity) throw("Capacitate depasita!");
		*List[Size++] = newElem;
		return *this;
	}
	const Array<T>& insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. daca index e invalid arunca o exceptie
	{
		if (Size + 1 > Capacity) throw("Capacitate depasita!");
		if (index < 0 || index >= Size) throw("Index invalid!");
		Size++;
		for (int i = Size - 2; i >= index; i--)
			*List[i + 1] = *List[i];
		*List[index] = newElem;
		return *this;
	}
	const Array<T>& insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, returneaza this. daca index e invalid arunca o exceptie
	{
		if (Size + otherArray.Size > Capacity) throw("Capacitate depasita!");
		if (index < 0 || index >= Size) throw("Index invalid!");
		Size += otherArray.Size;
		for (int i = Size - otherArray.Size - 1; i >= index; i--)
			*List[i + otherArray.Size] = *List[i];
		for (int i = index, j = 0; j < otherArray.Size; i++, j++)
			*List[i] = *otherArray.List[j];
		return *this;
	}
	const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. daca index e invalid arunca o exceptie
	{
		if (index < 0 || index >= Size) throw("Index invalid!");
		Size--;
		for (int i = index; i < Size; i++)
			*List[i] = *List[i + 1];
		return *this;
	}
	bool operator=(const Array<T>& otherArray)
	{
		if (Capacity < otherArray.Size) return 0;
		Size = otherArray.Size;
		for (int i = 0; i < Size; i++)
			*List[i] = *otherArray.List[i];
		return 1;
	}

	
	void Sort() // sorteaza folosind comparatia intre elementele din T
	{
		bool ok = 1;
		T p;
		while (ok)
		{
			ok = 0;
			for (int i = 1; i < Size; i++)
				if (*List[i - 1] > *List[i]) //crescator
				{
					ok = 1;
					p = *List[i];
					*List[i] = *List[i - 1];
					*List[i - 1] = p;
				}
		}
	}
	void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
	{
		bool ok = 1;
		T p;
		while (ok)
		{
			ok = 0;
			for (int i = 1; i < Size; i++)
				if (compare(*List[i - 1], *List[i]))
				{
					//cout << *List[i] << ' ' << *List[i - 1] << '\n';
					ok = 1;
					p = *List[i];
					*List[i] = *List[i - 1];
					*List[i - 1] = p;
				}
		}
	}
	void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
	{
		bool ok = 1;
		T p;
		while (ok)
		{
			ok = 0;
			for (int i = 1; i < Size; i++)
				if (comparator->CompareElements(List[i - 1], List[i]))
				{
					ok = 1;
					p = *List[i];
					*List[i] = *List[i - 1];
					*List[i - 1] = p;
				}
		}
	}

	//// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
	{
		int lo = -1, hi = Size, mid;
		while (hi - lo > 1)
		{
			mid = (lo + hi) / 2;
			if (elem <= *List[mid])
				hi = mid;
			else lo = mid;
		}
		if (hi != Size && *List[hi] == elem) return hi;
		return -1;
	}
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
	{
		int lo = -1, hi = Size, mid;
		while (hi - lo > 1)
		{
			mid = (lo + hi) / 2;
			if (!compare(elem, *List[mid]))
				hi = mid;
			else lo = mid;
		}
		if (hi != Size && *List[hi] == elem) return hi;
		return -1;
	}
	int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
	{
		int lo = -1, hi = Size, mid;
		while (hi - lo > 1)
		{
			mid = (lo + hi) / 2;
			if (!comparator->CompareElements(&elem, List[mid]))
				hi = mid;
			else lo = mid;
		}
		if (hi != Size && *List[hi] == elem) return hi;
		return -1;
	}

	int Find(const T& elem) // cauta un element in Array
	{
		for (int i = 0; i < Size; i++)
			if (*List[i] == elem)
				return i;
		return -1;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
	{
		for (int i = 0; i < Size; i++)
			if (compare(elem, *List[i]))
				return i;
		return -1;
	}
	int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
	{
		for (int i = 0; i < Size; i++)
			if (comparator->CompareElements(&elem, List[i]))
				return i;
		return -1;
	}

	int GetSize() {
		return Size;
	}
	int GetCapacity() {
		return Capacity;
	}

	ArrayIterator<T> GetBeginIterator() {
		return ArrayIterator<T>(0, Size, List);
	}
	ArrayIterator<T> GetEndIterator() {
		return ArrayIterator<T>(Size - 1, Size, List);
	}
};