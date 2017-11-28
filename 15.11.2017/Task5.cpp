#include <iostream>

using namespace std;

const int N = 256;

int valueIndex(char arr[], char  find[], int position);
void strCopy(char source[], char  destination[], int from, int to);
void strConCat(char  source[], char  str1[], int index);
void strChangeBySymbol(char source[], char ch, int from, int to);
void strReplace(char  source[], char  str[], char  replace[]);
int getLength(char array[]);

int main()
{
	char string[N] = "";
	char oldsubstring[N] = "";
	char newsubstring[N] = "";

	strReplace(string, oldsubstring, newsubstring);

	cout << string << endl;
	system("pause");
}

int valueIndex(char arr[], char  find[], int position)
{
	char value = find[0];
	int n = getLength(find), length = getLength(arr), p = 0;

	for (int i = position; i < length; i++)
	{
		if (arr[i] == value)
		{
			while (p <= n - 1)
			{
				p++;
				if (arr[i + p] != find[p]) break;
			}
			if (p == n) return i;
			else p = 0;
		}
	}
	return -1;
}

void strCopy(char source[], char  destination[], int from, int to)
{
	if (from < 0) from = 0;
	if (to > getLength(source)) to = getLength(source);

	for (int i = from, j = 0; i < to; i++, j++)
	{
		destination[j] = source[i];
	}
}

void strConCat(char  source[], char  str1[], int index)
{
	int n = getLength(source), l = getLength(str1);
	if (index > n) index = n;
	if (n - l + index > 0)
	{
		strChangeBySymbol(source, '\0', index, n);
	}
	for (int i = index, j = 0; j <l; i++, j++)
	{
		source[i] = str1[j];
	}
}

void strChangeBySymbol(char source[], char ch, int from, int to)
{
	for (int i = from; i <= to; i++)
	{
		source[i] = ch;
	}
}

void strReplace(char  source[], char  str[], char  replace[])
{
	int k = getLength(replace);
	int n = valueIndex(source, str, 0);
	int l = getLength(str);
	char result[N] = "";
	while (n != -1)
	{
		strCopy(source, result, n + l, getLength(source));
		strConCat(source, replace, n);
		strConCat(source, result, n + k);
		n = valueIndex(source, str, n + k);
		strChangeBySymbol(result, '\0', 0, getLength(result));
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
