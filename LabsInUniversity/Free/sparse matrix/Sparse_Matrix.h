#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Sparse_Matrix
{
private:
	vector<int> numbers;
	vector<int> column;
	vector<int> indecs_row;
	int n=0, m=0;
public:
	Sparse_Matrix();
	Sparse_Matrix(int **a, int n, int m);
	void set_value(int value, int i_search, int j_search);
	int get_value(int i_search, int j_search);
	void printOn(ostream& os);
	void printMemoryOn(ostream& os);
	int** asMatrix();
	Sparse_Matrix operator*(Sparse_Matrix& s)
	{
		for (int i = 0; i < this->n; i++)
		{
			for (int j = 0; j < this->m; j++)
			{
				this->set_value((get_value(i, j) * s.get_value(i, j)), i, j);
			}
		}
	}
	Sparse_Matrix operator*(int x)
	{
		for (int i = 0; i < this->n; i++)
		{
			for (int j = 0; j < this->m; j++)
			{
				this->set_value((get_value(i, j) * x), i,j);
			}
		}
	}
	Sparse_Matrix operator+(Sparse_Matrix& s)
	{
		for (int i = 0; i < this->n; i++)
		{
			for (int j = 0; j < this->m; j++)
			{
				this->set_value((get_value(i, j) + s.get_value(i, j)), i, j);
			}
		}
	}
	Sparse_Matrix operator-(Sparse_Matrix& s)
	{
		for (int i = 0; i < this->n; i++)
		{
			for (int j = 0; j < this->m; j++)
			{
				this->set_value((get_value(i, j) - s.get_value(i, j)), i, j);
			}
		}
	}
	void trans();
};

