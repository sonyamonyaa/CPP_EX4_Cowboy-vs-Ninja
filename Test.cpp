#include "doctest.h"
#include "sources/Team.hpp"

using namespace ariel;
TEST_CASE("Test 1 - Point Functions")
{
    //(-5, 10) (-3, 4) //-3x - 5
    //(3, 1) (6, 3)   // 
    //(5, 5) (3, 2)
    Point p1(0, 0);
    SUBCASE("Point Distance"){
        Point p2(3, 4);
        double expected_distance = 5.0;
        double actual_distance = p1.distance(Point(3, 4));
        CHECK(expected_distance == doctest::Approx(actual_distance).epsilon(0.0001));
        actual_distance = p1.distance(Point(0,5));
        actual_distance = p1.distance(Point(5,0));

    }
}


