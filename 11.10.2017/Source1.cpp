#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int x;
	bool ans = true;
	cout << "enter x :";
	cin >> x;
	for (int n = 2; n <= sqrt(x);n++)
	{
		if (x % n == 0)
		{
			ans = false;
			break;
		}
	}
	if (ans == true)
		cout << "Proper number";
	else
		cout << "Improper number";
}