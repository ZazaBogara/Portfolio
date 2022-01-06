#include "Matrix.h"
#include <iostream>

/*
Конструктор повинен створювати матрицю заданої розмірності з можливістю ініціалізації.
Визначити конструктор копій.
Перевантажити операції +, =, ==, *, виводу << і вводу >> для об'єктів класу.
*/

int main()
{
    Matrix OurFirstMatrix(2, 2);//створення матриці заданого розміру
    Matrix OurSecondMatrix(OurFirstMatrix);//конструктор копій
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
