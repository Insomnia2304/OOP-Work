#include <iostream>
using namespace std;

struct nume
{
	char a;
	int b;
	short c;
	short d;
};

struct nume2
{
	char arr[6];
	short arr2[3];
};

int main()
{
	/*char x[10];
	memset(x, 0, 10);

	((int*)x)[1] = 4096;
	((int*)x)[8] = 'aA';
	printf("%d", x[5]);

	short q = *(short*)(x + 5);
	printf("%d", q); */

	nume a = { 0 }, c;
	nume2 b;

	memset(&b, 1, sizeof(b));
	b.arr2[2] = 1;
	printf("%d", ((nume*)&b)->d);


	return 0;
}
