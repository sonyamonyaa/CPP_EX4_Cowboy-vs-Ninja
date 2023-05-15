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

namespace ariel
{
    class Point
    {
    private:
        double _x;
        double _y;

    public:
        Point(double point_x = 0, double point_y = 0);
        void setX(double point_x) { _x = point_x; }
        void setY(double point_y) { _y = point_y; };
        double getX() const { return _x; }
        double getY() const { return _y; }
        double distance(const Point &other) const; // distance between current point and given one
        void print();                              // prints the coordinates between parentheses (x, y)
        std::string toStr();                       // assist for character position

        static Point moveTowards(const Point &src, const Point &dest, double dist); // returns the closest point to dest which is within the limit of given distance from the src

        Point(const Point &) = default;
        Point &operator=(const Point &) = default;
        Point(Point &&) noexcept = default;
        Point &operator=(Point &&) noexcept = default;
        ~Point() = default;
    };

}