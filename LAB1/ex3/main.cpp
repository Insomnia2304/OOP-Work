#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

struct words
{
	char s[101];
	int lenght;
}words[100];
int wordsCount;

void sort_words() //bubblesort
{
	int i;
	bool ok = 1;
	while (ok)
	{
		ok = 0;
		for (i = 1; i < wordsCount; i++)
			if (words[i].lenght > words[i - 1].lenght ||
				words[i].lenght == words[i - 1].lenght && strcmp(words[i].s, words[i - 1].s) < 0)
			 {
				ok = 1;
				swap(words[i], words[i - 1]);
			 }
	}
}

int main()
{
	int i;
	scanf("%d", &wordsCount);
	for (i = 0; i < wordsCount; i++)
	{	
		scanf("%100s", words[i].s);
		words[i].lenght = strlen(words[i].s);
	}
	sort_words();
	for (i = 0; i < wordsCount; i++)
	{
		printf("%s\n", words[i].s);
	}
	return 0;
}