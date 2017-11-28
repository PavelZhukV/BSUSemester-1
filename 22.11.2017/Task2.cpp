#include<iostream>

using namespace std;

void systemTransfer(int num, int base, char trnum[]);
void DisplayArray(char array[], int n);

int main()
{
	double x;
	int p;
	char trnum[256];
	cout << "enter x : ";
	cin >> x;
	cout << "enter base : ";
	cin >> p;
	int n = 0,k = x;
	while (k /= p)
		n++;
	systemTransfer(x, p, trnum);
	DisplayArray(trnum, n);

	system("pause");
}

void systemTransfer(int num, int base,char trnum[])
{
	int n = 0,m,k = num;

	while (k /= base)
		n++;
	trnum[n + 1] = 0;
	for (; n >= 0; n--,num /= base)
	{
		m = num % base;
		switch (m)
		{
		case 0:
			trnum[n] = '0';
			break;
		case 1:
			trnum[n] = '1';
			break;
		case 2:
			trnum[n] = '2';
			break;
		case 3:
			trnum[n] = '3';
			break;
		case 4:
			trnum[n] = '4';
			break;
		case 5:
			trnum[n] = '5';
			break;
		case 6:
			trnum[n] = '6';
			break;
		case 7:
			trnum[n] = '7';
			break;
		case 8:
			trnum[n] = '8';
			break;
		case 9:
			trnum[n] = '9';
			break;
		case 10:
			trnum[n] = 'A';
			break;
		case 11:
			trnum[n] = 'B';
			break;
		case 12:
			trnum[n] = 'C';
			break;
		case 13:
			trnum[n] = 'D';
			break;
		case 14:
			trnum[n] = 'E';
			break;
		case 15:
			trnum[n] = 'F';
			break;
		}
	}
}

void DisplayArray(char array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] ;
	}
	cout << endl;
}