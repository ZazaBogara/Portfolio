#include <iostream>
#include "Sparse_Matrix.h"

using namespace std;

int main()
{  
    int **x = new int* [2];
    for (int i = 0; i < 2; i++)
    {
        x[i] = new int[2];
    }
    
    x[0][0] = 1;
    x[0][1] = 2;
    x[1][0] = 3;
    x[1][1] = 5;
    Sparse_Matrix matr(x,2,2);
    matr.printOn(cout);
    cout << "\n5:" << matr.get_value(1, 1);
    matr.set_value(0, 1, 1);
    matr.printOn(cout);
    cout << "\n0:" << matr.get_value(1, 1);
    matr.set_value(0, 1, 1);
    matr.printOn(cout);
    cout << "\n0:" << matr.get_value(1, 1);
    matr.set_value(7, 1, 1);
    matr.printOn(cout);
    cout << "\n7:" << matr.get_value(1, 1);
    matr.set_value(3, 1, 1);
    matr.printOn(cout);
    cout << "\n3:" << matr.get_value(1, 1);
    cout << "\n\n";
    Sparse_Matrix matr1;
    matr1.printOn(cout);
    matr1.set_value(3, 1, 1);
    matr1.printOn(cout);

    matr.trans();
    matr.printOn(cout);
    return 0;
}
