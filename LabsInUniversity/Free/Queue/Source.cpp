#include <iostream>
#include <vector>
#include "Queue.h"

using namespace std;

void test1();
void test2();

int main()
{
    test2();
    return 0;
}

void test1()
{
    Queue q(5);
    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    q.EnQueue(4);
    q.EnQueue(5);
    if (q.isFull())
        cout << "IS FULL\n\n";
    cout << q.DeQueue();
    cout << "\n";
    if (q.isFull())
        cout << "IS FULL\n\n";
    cout << q.DeQueue();
}
void test2()
{
    Priority_Queue q(5);
    q.EnQueue(3, 3);
    q.EnQueue(4, 4);
    q.EnQueue(1, 1);
    q.EnQueue(2, 2);
    q.EnQueue(2, 2);
    if (q.isFull())
        cout << "IS FULL\n\n";
    cout << q.DeQueue();
    cout << "\n";
    cout << q.DeQueue();
    cout << "\n";
    cout << q.DeQueue();
    cout << "\n"; 
    cout << q.DeQueue();
    cout << "\n";
    cout << q.DeQueue();
    cout << "\n";
    if (q.isEmpty())
        cout << "IS EMPTY\n\n";
}

