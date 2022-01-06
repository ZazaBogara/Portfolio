#pragma once
#include <iostream>
#include <vector>
class Matrix
{
private:
public:
	int n;
	int m;
	std::vector<std::vector<int>> matr;
	Matrix(int n, int m);
	Matrix(Matrix &matrix);
	void operator+(int a);
	int b;
	void operator= (const int& a);
	void operator== (int compareInt);
	void operator* (int inputValue);
	void operator>>(Matrix inputmatrix);
	void operator<<(Matrix inputmatrix);

};


