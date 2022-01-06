#include "Matrix.h"
#include <iostream>

/*
����������� ������� ���������� ������� ������ ��������� � ��������� �����������.
��������� ����������� ����.
������������� �������� +, =, ==, *, ������ << � ����� >> ��� ��'���� �����.
*/

int main()
{
    Matrix OurFirstMatrix(2, 2);//��������� ������� �������� ������
    Matrix OurSecondMatrix(OurFirstMatrix);//����������� ����
    std::cout << "Operator >>:\n";
    OurFirstMatrix.operator>>(OurFirstMatrix);
    std::cout << "Operator ==:\n";
    OurFirstMatrix.operator==(1);
    std::cout << "Operator +:\n";
    OurFirstMatrix.operator+(5);
    std::cout << "Operator <<:\n";
    OurFirstMatrix.operator<<(OurFirstMatrix);
    std::cout << "Operator =:\n";
    OurFirstMatrix.operator=(10);
    std::cout << "Operator <<:\n";
    OurFirstMatrix.operator<<(OurFirstMatrix);
    std::cout << "Operator *:\n";
    OurFirstMatrix.operator*(-1);
    std::cout << "Operator <<:\n";
    OurFirstMatrix.operator<<(OurFirstMatrix);
}
