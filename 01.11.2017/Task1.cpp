#include<iostream>

using namespace std;

int NumberUnit(long long number);

int main()
{
	long long x;
	cout << "enter x : ";
	cin >> x;
	cout << "number units on binaty represantation : "<< NumberUnit(x) << endl;
	system("pause");
	return 0;
}

int NumberUnit(long long number)
{
	int n = 0;
	while (number)
	{
		if (number % 2 == 1)
			n++;
		number /= 2;
	}
	return n;
}