#include "Array.h"

int sortDesc(const int& a,const int& b)
{
	return a < b;
}

int egal(const int& a, const int& b)
{
	return a == b;
}

int main() //aici se testeaza totul din header
{
	Array<int> a, b(100);

	try
	{
		b[3] = 6;
	}
	catch (const char* exc)
	{
		cout << exc << '\n';
	}

	b += 0; b += 10; b += 20; b += 30;

	Array<int> c(b);
	cout << c[2] << '\n';
	c.insert(2, 200);
	b.insert(0, c);
	b.print();

	try
	{
		Array<int> test(11);
		test += 5;
		test.insert(0, c);
		test.print();
		test.insert(0, c);
		test.print();
		test += 5;
	}
	catch (const char* exc) { cout << exc << '\n'; }
	
	c.print();
	c.Delete(2);
	c.print();
	b = c;
	b.print();
	b[0] = 100;
	b[3] = 0;
	cout << "--------\n";

	b.print();
	b.Sort(); //crescator
	b.print();
	cout << "--------\n";

	b.print();
	b.Sort(sortDesc); //descrescator
	b.print();
	cout << "--------\n";

	b.print();
	CompareByMod3 mod3;
	b.Sort(&mod3); //byMod3
	b.print();
	cout << "--------\n";

	b.print();
	cout << b.Find(100) << ' ' << b.Find(11) << '\n';
	cout << b.Find(100, egal) << ' ' << b.Find(11, egal) << '\n';
	Equal equal;
	cout << b.Find(100, &equal) << ' ' << b.Find(11, &equal) << '\n';
	cout << "--------\n";

	c.insert(0, b);
	c.Sort();
	c.print();
	cout << c.BinarySearch(10) << '\n';
	c.Sort(sortDesc);
	c.print();
	cout << c.BinarySearch(10, sortDesc) << '\n';
	cout << c.BinarySearch(20, sortDesc) << '\n';
	c.Sort(&mod3); //byMod3
	c.print();
	cout << c.BinarySearch(10, &mod3) << '\n';
	cout << "--------\n";

	c.print();
	ArrayIterator<int> it = c.GetEndIterator();
	cout << *it.GetElement() << ' ';
	--it;
	--it;
	cout << *it.GetElement() << ' ';
	++it;
	cout << *it.GetElement() << ' ';

	cout << "\n--------\n";
	ArrayIterator<int> it2 = c.GetBeginIterator();
	cout << (it != it2) << ' ';
	cout << *it2.GetElement() << ' ';
	it2 = it;
	cout << *it2.GetElement() << ' ';
	return 0;
}