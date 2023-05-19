#include "Point.hpp"
#include <cmath>
#include <string>

namespace ariel
{
    Point::Point(double x, double y)
    {
        setX(x);
        setY(y);
    }

    // https://stackoverflow.com/a/35069576
    double Point::distance(const Point &other) const
    {
        double dx = this->getX() - other.getX();
        double dy = this->getY() - other.getY();
        double res = (dx * dx) + (dy * dy);
        return sqrt(res);
    }

    Point Point::moveTowards(const Point &src,const Point &dest, double dist)
    {
        if (dist < 0){
            throw std::invalid_argument {"can't move for a negative distance"};
        }
        double total_dist = src.distance(dest);
        if (total_dist == 0){
            return dest;
        }
        double ratio = dist / total_dist;
        // (((1 - t) * x0 + t * x1), ((1 - t) * y0 + t * y1))
        double new_x = ((1 - ratio) * src.getX()) + (ratio * dest.getX()); 
        double new_y = ((1 - ratio) * src.getY()) + (ratio * dest.getY()); 
        return Point(new_x, new_y);
    }


    void Point::print()
    {
        std::cout << this->toStr() << std::endl;
    }

    std::string Point::toStr()
    {
        std::stringstream pos;
        pos << "(" <<std::defaultfloat << this->_x << "," << this->_y << ")";
        return pos.str();
    }
}