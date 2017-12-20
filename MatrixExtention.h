#pragma once
#include <iostream>
#define  N 10

using namespace std;

void EnterMatrix(int matrix[][N], int n, int m);
void DisplayMatrix(int matrix[][N], int n, int m);
void RandomMatrix(int matrix[][N], int n, int m, int k);
void GenerateMatrix(int matrix[][N], int n, int m);
void SumOfStringMatrix(int matrix[][N], int n, int m, int array[]);
void SwapRows(int matrix[][N], int n, int m, int i, int  j);

void EnterMatrix(int matrix[][N], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "a[" << (i + 1) << "][" << (j + 1) << "]=";
			cin >> matrix[i][j];
		}

	}
}


void DisplayMatrix(int matrix[][N], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void RandomMatrix(int matrix[][N], int n, int m, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % k - k / 2;
		}

	}
}

void GenerateMatrix(int matrix[][N], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = i + 1;
		}

	}
}

void SumOfStringMatrix(int matrix[][N], int n, int m, int array[])
{
	for (int i = 0; i < n; i++)
	{
		long s = 0;
		for (int j = 0; j < m; j++)
		{
			s = s + matrix[i][j];
		}
		array[i] = s;
	}
}

void SwapRows(int matrix[][N], int n, int m, int  i, int j)
{
	for (int k = 0; k < n; k++)
	{
		int temp = matrix[i][k];
		matrix[i][k] = matrix[j][k];
		matrix[j][k] = temp;

	}
}

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void BubleSortMatrix(int matrix[][N], int n, int m)
{
	int arr[N];
	SumOfStringMatrix(matrix, n, m, arr);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
				SwapRows(matrix, n, m, j, j + 1);
			}
		}
	}
}