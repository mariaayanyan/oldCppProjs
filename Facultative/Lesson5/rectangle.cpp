#include <iostream>
using namespace std;

struct point
{
    double x, y;
};

struct rectangle
{
    point upper, lower;
    void reset(const point&, const point&); //upper-left and lower-right corners
    void reset(const point&, double, double); //upper-left corner and dimensions
    double area();
    double perimeter();
    void stretch(double);
    void move(double, double);
    bool contains(const point&);
    bool contains(const rectangle&);
};

void rectangle::reset(const point& u, const point& l)
{
    upper = u;
    lower = l;
}

void rectangle::reset(const point& u, double x, double y)
{
    upper = u;
    lower = u; 
    lower.x += x;
    lower.y -= y;
}
    
double rectangle::area()
{
    return (lower.x - upper.x)*(upper.y - lower.y);
}    

double rectangle::perimeter()
{
    return (lower.x - upper.x + upper.y - lower.y)*2;
}

void rectangle::stretch(double factor)
{
    reset(upper, (lower.x - upper.x)*factor, (upper.y - lower.y)*factor);
}

void rectangle::move(double x, double y)
{
    upper.x += x;
    upper.y += y;
    lower.x += x;
    lower.y += y;
}

bool rectangle::contains(const point& p)
{
    return(p.x > upper.x && p.x < lower.x && p.y > lower.y && p.y < upper.y);
}

bool rectangle::contains(const rectangle& r)
{
    return contains(r.upper) && contains(r.lower);
}

void print(const point& p)
{
    cout << "(" << p.x << ";" << p.y << ")";
}

void print(const rectangle& r)
{
    print(r.upper);
    cout << " ";
    print(r.lower);
    cout << endl;
}

int main()
{
    rectangle r;
    r.reset(point{3, 4}, 12, 6);
    print(r);
    cout << r.perimeter() << endl;
    r.stretch(0.5);
    print(r);   
    cout << r.perimeter() << endl;
    r.move(-6, -21);
    print(r);
    cout << r.area() << endl;
}