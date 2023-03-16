#define _CRT_SECURE_NO_WARNINGS
#define NMAX 100
#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
using namespace std;

int stoi(char* s)
{
	int ans = 0;
	bool minus = 0;
	for (int i = 0; s[i]; i++)
		if ('0' <= s[i] && s[i] <= '9')
			ans = ans * 10 + s[i] - '0';
		else if (s[i] == '-') minus = 1;
	if (minus) return -ans;
	return ans;
}

int main()
{
	FILE* f;
	f = fopen("ini.txt", "r");
	if (!f)
	{
		printf("Eroare");
	}
	else
	{
		printf("Succes\n");

		char line[NMAX];
		int ans = 0;
		while (fgets(line, NMAX, f))
		{
			ans += stoi(line);
		}
		printf("%d", ans);
	}
	return 0;
}