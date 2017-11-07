#include<iostream>

using namespace std;

long long dectobin(long long decnum);
long long undnum(long long num);
int valuedigit(long long num, int n);
int binn(int n);


int main()
{
	long long x;
	int n;
	cout << "enter x = ";
	cin >> x;
	cout << "enter digit = ";
	cin >> n;
	cout << "numbber digit" << valuedigit(x, n);
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

int valuedigit(long long num, int n)
{
	long long binnum = dectobin(num);
	int rest = 0, value = 0;
	n = binn(n);
	while (binnum)
	{
		rest = binnum % 10000;
		if (rest == n)
			value++;
	}
	return value;
}

int binn(int n)
{
	switch (n)
	{
	case 1:
		n = 1;
		break;
	case 2:
		n = 10;
		break;
	case 3:
		n = 11;
		break;
	case 4:
		n = 100;
		break;
	case 5:
		n = 101;
		break;
	case 6:
		n = 110;
		break;
	case 7:
		n = 111;
		break;
	case 8:
		n = 1000;
		break;
	case 9:
		n = 1001;
		break;
	case 0:
		n = 0;
		break;
	case 'A':
		n = 1010;
		break;
	case 'B':
		n = 1011;
		break;
	case 'C':
		n = 1100;
		break;
	case 'D':
		n = 1101;
		break;
	case 'E':
		n = 1110;
		break;
	case 'F':
		n = 1111;
		break;
	}
	return n;
}