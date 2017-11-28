#include <iostream>

using namespace std;

int getLength(char array[]);
void breakStringIntoWords(char string[], char ** words);
void strCopy(char source[], char  destination[], int from, int to);

int main()
{
	const int N = 256;
	char string[N];
	char *words[N];

	breakStringIntoWords(string,words);


	for(int i = 0;i<256;i++)
	cout << words[i] << endl;
	system("pause");
}

void breakStringIntoWords(char string[], char ** words)
{
	int n = getLength(string);
	for (int i = 0,j = 0,k = 0; i < n; i++)
	{
		while (string[i] != 0)
		{
			words[j][k] = string[i];
			i++; k++;
		}
		if (k > 0)
		{
			k = 0;
			j++;
		}
	}
}

int getLength(char array[])
{
	int i = 0;

	while (array[i])
	{
		i++;
	}

	return i;
}
