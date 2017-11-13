#pragma once
#include<iostream>

using namespace std;

long long undnum(long long num)
{
	long long undnum = 0;
	int rest = num % 10;
	while (num)
	{
		rest = num % 10;
		undnum = undnum * 10 + rest;
		num /= 10;
	}
	return undnum;
}

void ans(long long num)
{
	if (num == undnum(num))
		cout << "this number is polynomyal";
	else
		cout << "this number isn't polynomyal";
}

void counter(long long num, int & less, int & more, int & equal)
{
	int prev = num % 10, next;
	num /= 10;
	while (num)
	{
		next = num % 10;
		if (prev == next)
			equal++;
		if (prev > next)
			more++;
		if (prev < next)
			less++;
		prev = next;
		num /= 10;
	}
}

void ans(int less, int more, int equal)
{
	if (less == 0 && more == 0 && equal > 0)
		cout << "monotonus";
	if (less == 0 && more > 0 && equal == 0)
		cout << "increasing";
	if (less > 0 && more == 0 && equal == 0)
		cout << "descending";
	if (less > 0 && more == 0 && equal > 0)
		cout << "not strict descending";
	if (less == 0 && more > 0 && equal > 0)
		cout << "not strict increasing";
	if (less > 0 && more > 0 && equal > 0)
		cout << "not ordered";
}

long long longestorder(long long num)
{
	long long order = 0, maxorder;
	int value = 1, prev = num % 10, next, maxvalue = 1;
	num /= 10;
	while (num)
	{
		next = num % 10;
		if (next == prev)
		{
			order = order * 10 + next;
			value++;
		}
		else
		{
			if (value > maxvalue)
			{
				maxvalue = value;
			}
			if (order > maxorder)
			{
				maxorder = order;
			}
			value = 0;
			order = 0;
		}
		prev = next;
		num /= 10;
	}
	cout << maxorder;
	return maxvalue;
}

long long newnum(long long num, int digit, int newdigit)
{
	long long newnum = 0;
	int rest = num % 10;
	while (num)
	{
		rest = num % 10;
		if (rest == digit)
			rest = newdigit;
		newnum = newnum * 10 + rest;
		num /= 10;
	}
	return newnum;
}

long long newnum(long long num, int del)
{
	long long newnum = 0;
	int rest = num % 10;
	while (num)
	{
		rest = num % 10;
		num /= 10;
		if (rest == del)
			continue;
		newnum = newnum * 10 + rest;
	}
	return newnum;
}

int NumberUnit(long long number)
{
	int n = 0;
	while (number)
	{
		if (number % 2 == 1)
			n++;
		number /= 2;
	}
	return n;
}

int NumberZero(long long number)
{
	int n = 0;
	while (number)
	{
		if (number % 2 == 0)
			n++;
		number /= 2;
	}
	return n;
}

int createsymbol(char symbol)
{
	int n;
	switch (symbol)
	{
	case '0':
		n = 0;
		break;
	case '1':
		n = 1;
		break;
	case '2':
		n = 2;
		break;
	case '3':
		n = 3;
		break;
	case '4':
		n = 4;
		break;
	case '5':
		n = 5;
		break;
	case '6':
		n = 6;
		break;
	case '7':
		n = 7;
		break;
	case '8':
		n = 8;
		break;
	case '9':
		n = 9;
		break;
	case 'A':
		n = 10;
		break;
	case 'B':
		n = 11;
		break;
	case 'C':
		n = 12;
		break;
	case 'D':
		n = 13;
		break;
	case 'E':
		n = 14;
		break;
	case 'F':
		n = 15;
	}
	return n;
}

int numnersymbol(long long number, char symbol)
{
	int n = 0;
	while (number)
	{
		if (number % 16 == createsymbol(symbol))
			n++;
		number /= 16;
	}
	return n;
}

void GenerateRandomArray(int array[], int n, int range)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % range - range / 2;//0..range - 1
	}
}

void DisplayArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

void EnterArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " a[" << (i + 1) << "] = ";
		cin >> array[i];
	}
}

int FirstMinIndex(int array[], int n)
{
	int min = 0;
	for (int i = 1; i < n; i++)
	{
		if (array[min] > array[i])
		{
			min = i;
		}
	}
	return min;
}

int FirstMaxIndex(int array[], int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (array[max] < array[i])
		{
			max = i;
		}
	}
	return max;
}

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void GenerateArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = i + 1;
	}
}

void ReverseArray(int array[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		Swap(array[i], array[n - i - 1]);
	}
}

void FindAllPrimeElements(int array[], int n, int newArray[], int& m)
{
	m = 0;
	for (int i = 0; i < n; i++)
	{
		if (isPrimeNumber(array[i]))
		{
			newArray[m] = array[i];
			m++;
		}
	}
}