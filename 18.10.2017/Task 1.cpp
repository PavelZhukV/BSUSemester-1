#include<iostream>

using namespace std;

long long undnum(long long num);
void ans(long long num);

int main()
{
	long long x;
	cout << "Enter x = ";
	cin >> x;
	ans(x);
	system("pause");
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

void ans(long long num)
{
	if (num == undnum(num))
		cout << "this number is polynomyal";
	else
		cout << "this number isn't polynomyal";
}