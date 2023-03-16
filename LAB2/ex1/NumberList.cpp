#include "NumberList.h"

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count == 10) return 1;
	this->numbers[this->count++] = x;
	return 0;
}

void NumberList::Sort() //am ales un bubblesort simplu
{
	bool ok = 1;
	int i, temp;
	while (ok)
	{
		ok = 0;
		for (i = 1; i < this->count; i++)
			if (this->numbers[i] < this->numbers[i - 1])
  			{
				temp = this->numbers[i];
				this->numbers[i] = this->numbers[i - 1];
				this->numbers[i - 1] = temp;
				ok = 1;
			 }
	}
}
void NumberList::Print()
{
	cout << "Number of integers: " << this->count << '\n';
	for (int i = 0; i < this->count; i++)
		cout << this->numbers[i] << ' ';
	cout << '\n';
}