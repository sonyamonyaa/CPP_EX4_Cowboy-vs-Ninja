#include "Point.hpp"

namespace ariel
{
    Point::Point(double x, double y)
    {
        setX(x);
        setY(y);
    }

    Point::~Point()
    {
    }
    //https://stackoverflow.com/a/35069576
    double Point::distance(const Point &other)
    {
        return 0.0;
    }
    
    void Point::print()
    {
    }
    
    Point Point::moveTowards(Point &src, Point &dest, double dist)
    {
        return;
    }
}