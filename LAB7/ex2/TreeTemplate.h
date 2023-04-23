#pragma once
#include <iostream>
#include <time.h>
using namespace std;

template <typename T>
class TreeTemplate
{
	TreeTemplate* nodes[100];
	int index;
	T inf;
public:
	TreeTemplate()
	{
		index = 0;
		inf = rand() % 100;
	}
	~TreeTemplate()
	{
		delete_node(0);
		delete nodes[0];
	}
	void add_node(TreeTemplate* x)
	{
		if (x == nullptr)
		{
			index = 1;
			nodes[0] = new TreeTemplate; //va arata spre radacina
		}
		else
		{
			x->nodes[x->index++] = new TreeTemplate;
		}

	}
	TreeTemplate& get_node(TreeTemplate* x)
	{
		if (x == nullptr)
		{
			return *nodes[0];
		}
		else
		{
			return *x->nodes[rand() % (x->index)]; //nu se specifica care nod
		}
	}
	void delete_node(TreeTemplate* x)
	{
		if (x == nullptr) x = nodes[0];
		for (int i = 0; i < x->index; i++)
			 delete_node(x->nodes[i]);
		delete x;
	}
	void insert_node(TreeTemplate* x, int index)
	{
		for (int i = x->index; i >= index; i--)
			x->nodes[i] = x->nodes[i - 1];
		x->nodes[index] = new TreeTemplate;
		x->index++;
	}
	int count(TreeTemplate* x)
	{
		if (x == nullptr)
			x = nodes[0];
		int res = x->index;
		for (int i = 0; i < x->index; i++)
			res += count(x->nodes[i]);
		return res;
	}
	TreeTemplate* find(T val, bool (*callback)(T, T))
	{
		return find_rec(nullptr, val, callback);
	}
	TreeTemplate* find_rec(TreeTemplate* x, T val, bool (*callback)(T, T))
	{
		if (x == nullptr) x = nodes[0];
		if (callback(val, x->inf)) return x;
		for (int i = 0; i < x->index; i++)
			if (find_rec(x->nodes[i], val, callback) != 0)
				return find_rec(x->nodes[i], val, callback);
		return 0;
	}
	void sort(TreeTemplate* x, bool (*callback)(T, T))
	{
		bool ok = 1;
		TreeTemplate* temp;
		while (ok)
		{
			ok = 0;
			for (int i = 1; i < x->index; i++)
				if (callback == nullptr && x->nodes[i - 1]->inf > x->nodes[i]->inf || //sortare crescatoare, default 
					callback != nullptr && !callback(x->nodes[i - 1]->inf, x->nodes[i]->inf)) //sortare descrescatoare
				{
					temp = x->nodes[i];
					x->nodes[i] = x->nodes[i - 1];
					x->nodes[i - 1] = temp;
					ok = 1;
			    }
		}
	}
	void print(TreeTemplate* x)
	{
		if (x == nullptr) x = nodes[0];
		for (int i = 0; i < x->index; i++)
			cout << x->nodes[i]->inf << ' ';
	}
};

template <typename T>
bool callback1(T a, T b)
{
	return a == b;
}

template <typename T>
bool callback2(T a, T b)
{
	return a >= b; //sortare descrescatoare
}
