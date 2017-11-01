#include<iostream>

using namespace std;

long long newnum(long long num, int digit, int newdigit);
long long undnum(long long num);

int main()
{
	long long x;
	int a, b;
	cout << " Enter x = ";
	cin >> x;
	cout << " Enter old digit a = ";
	cin >> a;
	cout << " Enter new digit b = ";
	cin >> b;
	cout << undnum(newnum(x, a, b));
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
