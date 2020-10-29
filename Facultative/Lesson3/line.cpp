#include <iostream>
using namespace std;

struct Point
{
    double x, y;
};

struct Line
{
    double a, b, c;
};

bool isPointOnLine(const Point& p, const Line& l)
{
    return l.a*p.x + l.b*p.y + l.c == 0;
}

Line LineFromTwoPoints(const Point& a, const Point&b)
{
    Line res;
    res.a = a.y - b.y;
    res.b = b.x - a.x;
    res.c = a.x*b.y + b.x*a.y;

    return res;
}

int main()
{

}