#include "Trangle.h"
#include <iostream>
#include <math.h>

using namespace std;

Trangle::Trangle()
{
	cout << "Input:\na:";
	cin >> a;
	cout << "b:";
	cin >> b;
	cout << "c:";
	cin >> c;
	angle();
	
}
Trangle::Trangle(const Trangle& obj)
{
	a = obj.a;
	b = obj.b;
	c = obj.c;
	ab = obj.ab;
	bc = obj.bc;
	ac = obj.ac;
}
Trangle::Trangle(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
	angle();
}
void Trangle::angle()
{
	ab = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / 2 * a * b);
	bc = acos((pow(c, 2) + pow(b, 2) - pow(a, 2)) / 2 * b * c);
	ac = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / 2 * a * c);
}

int Trangle::square()
{
	return sqrt(perimetr() / 2 * (perimetr() - a) * (perimetr() - b) * (perimetr() - c));
}
int Trangle::perimetr()
{
	return a + b + c;
}
int Trangle::h(int c)
{
	if (c == this->a)
	{
		return b * cos(ab);
	}
	if (c == this->b)
	{
		return a * cos(ab);
	}
	if (c == this->c)
	{
		return a*cos(ac);
	}
	return 0;//не правильна сторона
}
void Trangle::whatItIs()
{
	if ((ab == bc) || (ab = ac) || (bc = ac))
	{
		cout << "Rivnobedreniu";
	}
	else if ((ab == bc) && (bc == ac))
	{
		cout << "Rivnostoroniu";
	}
	else if ((ab == 90) || (ab = 90) || (bc = 90))
	{
		cout << "Priamokytniu";
	}
	else
	{
		cout << "Niyakiy";
	}
}

void Trangle::set_static(int a)
{
	self_static = a;
}