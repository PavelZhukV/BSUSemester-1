#include<iostream>

using namespace std;

long long dectobin(long long decnum);
long long undnum(long long num);
int valuezero(long long num);

int main()
{
	long long x;
	cout << "enter x = ";
	cin >> x;
	cout << "numbber zeroes = " << valueunit(dectobin(x));
	system("pause");
}

long long dectobin(long long decnum)
{
	long long binnum = 0;
	while (decnum)
	{
		binnum = binnum * 10 + decnum % 2;
		decnum /= 2;
		binnum = undnum(binnum);
	}
	return binnum;
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

int valuezero(long long num)
{
	int n = 0;
	while (num)
	{
		if (num % 10 == 0)
			n++;
		num /= 10;
	}
	return n;
}