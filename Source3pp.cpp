#include<iostream>

using namespace std;

int main()
{
	int x = 0, y = 1,xy;
	while (y < 99)
	{
		xy = y;
		y = x + y;
		x = xy;
	}
	cout << y;
	system("pause");
}