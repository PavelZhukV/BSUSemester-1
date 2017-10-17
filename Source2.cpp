#include"stdafx.h"
#include<iostream>
#include<cmath>

using namespace std;

int number(long long int , int );

int main()
{
	long long int N;
	cout << "enter a number :";
	cin >> N;
	int  y, min = 9, max = 0;
	for (int n = 0; n < 10; n++)
	{
		y = number(N , n);
		if (y > 0)
		{
			if (n < min)
				min = n;
			if (n > max)
				max = n;
		}
		cout << "Quantity of " << n << " :" << y <<endl;
	}
	cout << "max = " << max << endl;
	cout << "min = " << min;
}


int number(long long int N, int n)
{
	int i = 0;
	for (; N > 0; N = N / 10)
	{
		if (N % 10 == n)
			i++;
	}
	return i;
}