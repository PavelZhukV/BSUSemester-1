#include "stdafx.h"
#include<iostream>

using namespace std;

void counter(long long num, int & less, int & more, int & equal);
void ans(int less, int more, int equal);

int main()
{
	long long x;
	cout << " Enter x = ";
	cin >> x;
	int less = 0, more = 0, equal = 0;
	counter(x, less, more, equal);
	ans( less, more, equal);
	system("pause");
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

void ans( int less, int more, int equal)
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