#include<iostream>

using namespace std;

long long longestorder(long long num);

int main()
{
	long long x;
	cout << "enter x = ";
	cin >> x;
	cout << longestorder(x);
}

long long longestorder(long long num)
{
	long long order = 0,maxorder;
	int value = 1,prev = num % 10,next,maxvalue = 1;
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
