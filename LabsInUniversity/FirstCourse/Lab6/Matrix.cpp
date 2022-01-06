#include "Matrix.h"
Matrix::Matrix(int n, int m)//звичайний конструктор
{
	this->n = n;
	this->m = m;
	matr.resize(n);
	for (int i = 0; i < n; i++)
		matr[i].resize(m);
}

Matrix::Matrix(Matrix &matrix)//конструктор копій
{
	this->matr = matrix.matr;
}

void Matrix::operator+(int a)//Додає число до матриці
{
	for (int i = 0; i < n; i++)
		for (int  j = 0; j < m; j++)
			matr[i][j] = matr[i][j] + a;
}
void Matrix::operator= (const int& a)//присваює елементу значення
{
	int n = 0;
	int m = 0;
	std::cout << "which n:";
	std::cin >> n;
	std::cout << "which m:";
	std::cin >> m;
	matr[n][m] = a;
}

void Matrix::operator== (int compareInt)//говорить чи число є в матриці
{
	bool boolean=0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if(matr[i][j]==compareInt)
			{
				std::cout << "Yes.\n";
				return;
			}
		}
	std::cout << "No.\n";
}
void Matrix::operator* (int inputValue)
{
	for (int row = 0; row < this->n; row++)//Множить всі елементи матриці на число
	{
		for (int colomn = 0; colomn < this->m; colomn++)
		{
			matr[row][colomn] = matr[row][colomn] * inputValue;
		}
	}
}

void Matrix::operator>>(Matrix inputMatrix)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			std::cout << "Element [" << i << "],[" << j << "] is:";
			std::cin >> matr[i][j];
		}
}
void Matrix::operator<<(Matrix inputMatrix)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cout << "Element [" << i << "],[" << j << "] is:" << matr[i][j] << "\n";
}

