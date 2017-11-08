#include<iostream>

using namespace std;

int NumberZero(long long number);

int main()
{
	long long x;
	cout << "enter x : ";
	cin >> x;
	cout << "number zeroes on binaty represantation : " << NumberZero(x) << endl;
	system("pause");
	return 0;
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