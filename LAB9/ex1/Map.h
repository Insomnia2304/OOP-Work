#pragma once
#include <iostream>
using namespace std;

template <typename K, typename V>
struct Obiect {
	K key;
	V value;
	int index;
};

template <typename K, typename V>
class Map
{
	int size = 0;
	Obiect<K, V> array[101];
public:
	V& operator[](K key) {
		for (int i = 0; i < size; i++)
		{
			if (array[i].key == key) { return array[i].value; }
		}
		array[size].index = size;
		array[size].key = key;
		size++;
		return array[size - 1].value;
	}
	Obiect<K, V>* begin() { return &array[0]; }
	Obiect<K, V>* end() { return &array[size]; }
	void Set(K key, V value) {
		for (int i = 0; i < size; i++)
		{
			if (array[i].key == key) { array[i].value = value; return; }
		}
		array[size].index = size;
		array[size].key = key;
		array[size].value = value;
		size++;
	}
	bool Get(const K& key, V& value) {
		for (int i = 0; i < size; i++)
		{
			if (array[i].key == key) { value = array[i].value; return 1; }
		}
		return 0;
	}
	int Count() {
		return size;
	}
	void Clear() {
		size = 0;
	}
	bool Delete(const K& key) {
		for (int i = 0; i < size; i++)
		{
			if (array[i].key == key)
			{
				for (int j = i + 1; j < size; j++)
				{
					array[j - 1] = array[j];
					array[j - 1].index--;
				}
				size--;
				return 1;
			}
		}
		return 0;
	}
	bool Includes(const Map<K, V>& map) {
		int i, j;
		for (i = 0; i < map.size; i++)
		{
			for (j = 0; j < size; j++)
				if (map.array[i].key == array[j].key)
					break; //am gasit elementul respectiv
			if (j == size) return 0; //nu am gasit elementul respectiv
		}
		return 1;
	}
};
