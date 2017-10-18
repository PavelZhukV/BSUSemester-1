#include<iostream>

using namespace std;

double power(double x, double eps);
void creatTable(double a, double b, double h, double eps);//void-возвращает пустое значение,пустой тип
double morethenValue(double value);
double lessthenValue(double value);
double morelessValue(double x,double y);

int main()
{
	double a = morethenValue(0);
	double b = morethenValue(a);
	double h = lessthenValue(b - a);
	double eps = morelessValue(0,1);
	creatTable(a, b, h, eps);
	system("pause");
	return 0;
}

double morethenValue(double value)
{
	double x;
	while (true)
	{
		cout << "x > " << value << " : ";
		cin >> x;
		if (x > value)
			return x;
		cout << "Error data!Tey again ";
		system("pause");
		system("cls");
	}
}

double lessthenValue(double value)
{
	double x;
	while (true)
	{
		cout << "x < " << value << " : ";
		cin >> x;
		if (x < value)
			return x;
		cout << "Error data!Tey again ";
		system("pause");
		system("cls");
	}
}

double morelessValue(double x, double y)
{
	double z;
	while (true)
	{
		cout << x <<" < z < " << y << ":" ;
		cin >> z;
		if (x < z && z < y)
			return z;
		cout << "Error data!Tey again ";
		system("pause");
		system("cls");
	}
}

void creatTable(double a, double b, double h, double eps)
{
	for (double x = a; x <= b; x += h)
		cout << "x = " << x << " y = " << power(x, eps) << " yt = " << sqrt(x) << endl;
	return;
}

double power(double x, double eps)
{
	double yPrev = x, yNext = 1. / 2 * (yPrev + x / yPrev);
	while (fabs(yPrev - yNext) > eps)
	{
		yPrev = yNext;
		yNext = 1. / 2 * (yPrev + x / yPrev);
	}
	/*
	double yPrev = x, yNext = yPrev;
	do
	{
	yPrev = yNext;
	yNext = 1. / 2 * (yPrev + x / yPrev);
	}
	while (fabs(yPrev - yNext) > eps);
	*/
	return yNext;
}

double nextValue(double x, double y)
{
	return 1. / 2 * (y + x / y);
}