#include<iostream>

using namespace std;

int createsymbol(char symbol);
int numnersymbol(long long number, char symbol);

int main()
{
	long long x;
	char y;
	cout << "enter x : ";
	cin >> x;
	cout << "enter symbol y : ";
	cin >> y;
	cout << "number " << y << " on hexademical represantation : " << numnersymbol(x,y) << endl;
	system("pause");
	return 0;
}

int createsymbol(char symbol)
{
	int n;
	switch (symbol)
	{
	case '0':
		n = 0;
		break;
	case '1':
		n = 1;
		break;
	case '2':
		n = 2;
		break;
	case '3':
		n = 3;
		break;
	case '4':
		n = 4;
		break;
	case '5':
		n = 5;
		break;
	case '6':
		n = 6;
		break;
	case '7':
		n = 7;
		break;
	case '8':
		n = 8;
		break;
	case '9':
		n = 9;
		break;
	case 'A':
		n = 10;
		break;
	case 'B':
		n = 11;
		break;
	case 'C':
		n = 12;
		break;
	case 'D':
		n = 13;
		break;
	case 'E':
		n = 14;
		break;
	case 'F':
		n = 15;
	}
	return n;
}

int numnersymbol(long long number, char symbol)
{
	int n = 0;
	while (number)
	{
		if (number % 16 == createsymbol(symbol))
			n++;
		number /= 16;
	}
	return n;
}