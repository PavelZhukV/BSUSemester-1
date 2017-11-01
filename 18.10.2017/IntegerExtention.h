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