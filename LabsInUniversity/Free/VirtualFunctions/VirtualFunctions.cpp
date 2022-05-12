#include <iostream>
#include <math.h>

using namespace std;

class Point
{
public:
    double x, y;
    Point(double x, double y) : x(x), y(y) { }

    void Show()
    {
        cout << "(" << x << "," << y << ")";
    }

    double Distance(const Point& c)
    {
        return sqrt(pow(x - c.x, 2) + pow(y - c.y, 2));
    }
};

class Fig
{
public:
    virtual void Show() { }
    virtual double Square() = 0;
};

class Rect : public Fig
{
    Point TL;
    double L;
    double H;
public:
    Rect(Point TL, double L, double H) : TL(TL), H(H), L(L) { }

    virtual void Show()
    {
        cout << "RECT: TopLeft: ";
        TL.Show();
        cout << " Width: " << L << " Heigth: " << H << endl;
    }

    virtual double Square()
    {
        return L * H;
    }
};

class Circle : public Fig
{
    Point C;
    double R;
public:
    Circle(Point C, double R) : C(C), R(R) { }

    virtual void Show()
    {
        cout << "CIRCLE: Center: ";
        C.Show();
        cout << " Radius: " << R << endl;
    }

    virtual double Square()
    {
        return 3.14 * R * R;
    }
};

class Triangle : public Fig
{
    Point A, B, C;
public:
    Triangle(Point A, Point B, Point C) : A(A), B(B), C(C) { }

    virtual void Show()
    {
        cout << "TRIANGLE: A: "; A.Show();
        cout << "B: ";  B.Show();
        cout << "C: "; C.Show();
        cout << endl;
    }

    virtual double Square()
    {
        double a = A.Distance(B);
        double b = B.Distance(C);
        double c = C.Distance(A);
        double p = (a + b + c) / 2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
};

int main()
{
    cout << "Hello World!\n";

    const int SZ = 4;
    Fig** figs = new Fig*[SZ];
    figs[0] = new Rect(Point(2, 3), 10, 4);
    figs[1] = new Rect(Point(5, 10), 3, 5);
    figs[2] = new Circle(Point(5, 10), 3);
    figs[3] = new Triangle(Point(1, 1), Point(2, 2), Point(2, 1));

    for (int i = 0; i < SZ; i++)
    {
        figs[i]->Show();
    }

    double sum = 0;
    for (int i = 0; i < SZ; i++)
    {
        sum += figs[i]->Square();
    }
    cout << "Total Square: " << sum << endl;

}
