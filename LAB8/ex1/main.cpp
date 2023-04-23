#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

ifstream fin("input.txt");

class Compare
{public:
	bool operator() (pair<string, int>p1, pair<string, int>p2)
	{
		if (p1.second == p2.second)
		{
			if (p1.first.compare(p2.first) > 0)
				return 1;
			return 0;
		}
		return p1.second < p2.second;
	}
};

int main()
{
	string s, del(" ,?!."), temp;

    getline(fin, s);
	cout << "Sirul citit:\n" << s << '\n';
	cout << "----------------------------------------\n";

	map<string, int> m;
	int lg = s.size(), i, j;
	i = s.find_first_not_of(del, 0);
	
	while (i != -1)
	{
		j = s.find_first_of(del, i + 1);
		temp = s.substr(i, j - i);
		//transform lowercase
		for (int k = 0; k < temp.size(); k++)
			if ('A' <= temp[k] && temp[k] <= 'Z')
				temp[k] = temp[k] + ('a' - 'A');
		//cout << temp << '\n'; //debug
		//inserez in mapa
		if (m[temp]) m[temp]++;
		else m[temp] = 1;

		if (j == -1) { break; }
		i = s.find_first_not_of(del, j + 1);
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> q;
	for (auto it = m.begin(); it != m.end(); it++)
		q.push(make_pair(it->first, it->second));
	while (!q.empty())
	{
		cout << q.top().first << " => " << q.top().second << '\n';
		q.pop();
	}
	fin.close();
	return 0;
}