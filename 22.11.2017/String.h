#pragma once
#include<iostream>

const int N = 256;

using namespace std;

int getLength(char array[]);
void toUpper(char array[]);
bool isAlphabet(char ch);
bool isAlphabetLowerCase(char ch);
bool isAlphabetUpperCase(char ch);
bool equals(char lhs[], char rhs[], bool foo = false);
void checkIndex(char string[], char undstring[]);
void compareOfStrings(char lhs[], char rhs[]);
int valueIndex(char arr[], char  find[], int position);
void strCopy(char source[], char  destination[], int from, int to);
void strConCat(char  source[], char  str1[], int index);
void strChangeBySymbol(char source[], char ch, int from, int to);
void strDel(char  source[], char  str[]);
void strReplace(char  source[], char  str[], char  replace[]);
void strSwap(char & a, char & b);
void strReverse(char  source[]);
void strDisplay(char massive[], int n);

int getLength(char array[])
{
	int i = 0;

	while (array[i]) 
	{
		i++;
	}

	return i;
}

void toUpper(char array[])
{
	int l = getLength(array);
	int diff = 'a' - 'A';

	for (int i = 0; i < l; i++)
	{
		char ch = array[i]; 

		if (isAlphabetLowerCase(ch))
		{
			array[i] = ch + diff;
		}
	}
}

bool isAlphabet(char ch)
{
	return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}

bool isAlphabetUpperCase(char ch)
{
	return (ch >= 'A' && ch <= 'Z');
}

bool isAlphabetLowerCase(char ch)
{
	return (ch >= 'a' && ch <= 'z');
}

bool equals (char lhs[], char rhs[], bool foo )
{
	if (getLength(lhs) != getLength(rhs))
	{
		return false;
	}

	int length = getLength(lhs);
	for (int i = 0; i < length; i++)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}

	return true;
}

void checkSign(char lhs[], char rhs[], int & less, int & more)
{
	toUpper(lhs);
	toUpper(rhs);
	int i = 0;
	while (lhs[i] == rhs[i] && lhs[i] == 0 && rhs[i] == 0)
	{
		i++;
	}
	if (lhs[i] > rhs[i])
		more++;
	if (lhs[i] < rhs[i])
		less++;
}

void compareOfStrings(char lhs[], char rhs[])
{
	int less = 0, more = 0;
	checkSign(lhs, rhs, less, more);
	if (more == 1)
		cout << "the first string";
	else
		if (less == 1)
			cout << " the second string";
		else
			cout << "strings are equal";
}

void checkIndex(char string[], char undstring[])
{
	if (valueIndex(string, undstring, 0) >= 0)
	{
		cout << valueIndex(string, undstring, 0);
	}
	else
		cout << "string don't include this undstring";
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

void strDel(char  source[], char  str[])
{
	int n = valueIndex(source, str,0);
	char result[N] = "";
	while (n != -1)
	{
		strCopy(source, result, n + getLength(str), getLength(source));
		strConCat(source, result, n);
		n = valueIndex(source, str, n);
		strChangeBySymbol(result, '\0', 0, getLength(result));
	}
}

void strReplace(char  source[], char  str[], char  replace[])
{
	int k = getLength(replace);
	int n = valueIndex(source, str,0);
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

void enterstring(char request, char string)
{
	cout << request;
	cin >> string;
}

void strSwap(char & a, char & b)
{
	char temp = a;
	a = b;
	b = temp;
}

void strReverse(char  source[])
{
	int length = getLength(source);
	for (int i = 0; i < length / 2; i++)
	{
		swap(source[i], source[length - 1 - i]);
	}
}

void strDisplay(char massive[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << massive[i];
	}
}