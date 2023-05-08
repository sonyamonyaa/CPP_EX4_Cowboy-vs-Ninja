#pragma once

/**
 *  A position on the game board
 *  given as 2 coordinates of type double, saving a position on the x, y axises
 **/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>

namespace ariel{
    class Point
    {
    private:
        double __x;
        double __y;
    public:
        Point(double x, double y);
        ~Point();
        void setX(double x){__x = x;}
        void setY(double y){__y = y;};
        double getX(){return __x;}
        double getY(){return __y;}
        double distance(const Point &other); //distance between current point and given one
        void print(); //prints the coordinates between parentheses (x, y)

        static Point moveTowards(Point &src, Point &dest, double dist);//returns the closest point to dest which is within the limit of given distance from the src 
    };
    
    
}