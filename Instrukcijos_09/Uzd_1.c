#include <stdio.h>
#include <math.h>

typedef struct Point
{
    double x;
    double y;
} Point;

void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);

int main()
{
    Point p1 = createPoint(2.0, -3.0);
    Point p2 = createPoint(-4.0, 5.0);

    printf("Distance: %lf\n", getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0)));
    return 0;
}

void printPoint(Point p)
{
    printf("(%lf, %lf)\n", p.x, p.y);
}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double getDistance(Point a, Point b)
{
    return sqrt(pow(b.x-a.x, 2.0) + pow(b.y-a.y, 2.0));
}