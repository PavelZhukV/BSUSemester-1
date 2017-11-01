#include<iostream>

using namespace std;

long long newnum(long long num,int del);
long long undnum(long long num);

int main()
{
	long long x;
	int a;
	cout << " Enter x = ";
	cin >> x;
	cout << " Enter delete digit a = ";
	cin >> a;
	cout << undnum(newnum(x, a));
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