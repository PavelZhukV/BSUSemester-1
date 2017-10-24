#pragma once

#include<iostream>
#include<cmath>

using namespace std;

int numberdigit( int long long number)
{
	int i = 0;
	for (; number > 0; i++)
		number = number / 10;
	return i;
}

int valuedigit(int long long number, int order)
{
	int a;
	a = ((number / pow(10, order)) * 10) - (number / pow(10, (order - 1)));
	return a;
}

void polynomial(int long long number)
{
	int m = numberdigit(number);
	bool ans = true;
	for (int i = 1; i <= (m / 2); i++)
		if (valuedigit(number, i) != valuedigit(number, m - i))
		{
			ans = false;
			break;
		}
	if (ans = true)
		cout << " This number is polynomial";
}

void increasingdigit(int long long number)
{
	int m = numberdigit(number);
	bool ans = true;
	for (int i = m; i > 1; i--)
		if (valuedigit(number, i) < valuedigit(number, i-1))
		{
			ans = false;
			break;
		}
	if (ans = true)
		cout << " This number have increasing digits";
}

void nonstrincreasingdigit(int long long number)
{
	int m = numberdigit(number);
	bool ans = true;
	for (int i = m; i > 1; i--)
		if (valuedigit(number, i) <= valuedigit(number, i - 1))
		{
			ans = false;
			break;
		}
	if (ans = true)
		cout << " This number have non-srictly increasing digits";
}

void decreasingdigit(int long long number)
{
	int m = numberdigit(number);
	bool ans = true;
	for (int i = m; i > 1; i--)
		if (valuedigit(number, i) > valuedigit(number, i - 1))
		{
			ans = false;
			break;
		}
	if (ans = true)
		cout << " This number have decreasing digits";
}

void nonstrdecreasingdigit(int long long number)
{
	int m = numberdigit(number);
	bool ans = true;
	for (int i = m; i > 1; i--)
		if (valuedigit(number, i) >= valuedigit(number, i - 1))
		{
			ans = false;
			break;
		}
	if (ans = true)
		cout << " This number have non-srictly decreasing digits";
}

int biggestsq(long long int number)
{
	int m = numberdigit(number);
	for (int i = m, j = 0,k = 0; i > 1; i++)
	{
		if (valuedigit(number, i) == valuedigit(number, i - 1))

	}

}

int newnumber(int long long number, int digit, int newdigit)
{
	int m = numberdigit(number);
	for (int i = m; i > 1; i++)
		if (valuedigit(number, i) == digit)
			number = (number / pow(10, i)) + (newdigit * pow(10, i - 1)) + (number % pow(10, i - 1));
	return number;
}

int delnumber(int long long number, int digit, int newdigit)
{
	int m = numberdigit(number);
	for (int i = m; i > 1; i++)
		if (valuedigit(number, i) == digit)
			number = (number / pow(10, i)) + (number % pow(10, i - 1));
	return number;
}