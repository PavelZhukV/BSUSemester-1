#pragma once

int getLength(char array[]);
void toUpper(char array[]);
bool isAlphabet(char ch);
bool isAlphabetLowerCase(char ch);
bool isAlphabetUpperCase(char ch);
bool equals(char lhs[], char rhs[], bool foo = false);

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

bool equals (char lhs[], char rhs[], bool foo = false)
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
	if (valueIndex(string, undstring) >= 0)
		cout << valueIndex(string, undstring);
	else
		cout << "string don't include this undstring";
}

int valueIndex(char string[], char undstring[])
{
	int index, counter = 0;
	for (int n = getLength(undstring), k = getLength(string), i = 0; i < (k - n + 1); i++)
	{
		if (string[i] == undstring[0])
		{
			index = i;
			while (i < index + n)
			{
				if (string[i] == undstring[counter])
				{
					counter++;
					i++;
				}
			}
			if (counter != n)
			{
				counter = 0;
				index = -1;
			}
		}

	}
	return index;
}

void newString(char string[], char oldundstring[], char newundstring[])
{
	int i = valueIndex(string, oldundstring), s = getLength(string), o = getLength(oldundstring), n = getLength(newundstring);
	for (; i < s - o; i++)
	{
		if (i < 0)
			break;
		substitution(string, newundstring, i);
		i = valueIndex(string, oldundstring);
	}
}

void substitution(char string[], char newundstring[], int index)
{
	int n = getLength(newundstring);
	for (int s = getLength(string); s - index - n > 0; s--)
	{
		string[s - 1 + n] = string[s - 1];
	}
	for (; n > 0; n--)
	{
		string[index + n] = newundstring[n];
	}
}