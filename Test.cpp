#include "doctest.h"
#include "sources/Character.hpp"

using namespace ariel;
TEST_CASE("Test 1 - Point Functions")
{
    SUBCASE("1.1 - Check Valid Creation")
    {
        CHECK_NOTHROW(Point(0, 0));
        CHECK_NOTHROW(Point(-1.2, 3.5));
        CHECK_NOTHROW(Point(1.2, -3.5));

        Point p(0, 0);
        CHECK_EQ(p.getX(), 0);
        CHECK_EQ(p.getY(), 0);
    }

    Point p1(0, 0);
    SUBCASE("1.2 - Test Distance")
    {
        // https://github.com/doctest/doctest/blob/master/doc/markdown/assertions.md#floating-point-comparisons
        double expected_distance = 5.0;
        double actual_distance = p1.distance(Point(3, 4));
        CHECK(expected_distance == doctest::Approx(actual_distance).epsilon(0.0001));
        //
        actual_distance = p1.distance(Point(0, 5));
        CHECK(expected_distance == doctest::Approx(actual_distance).epsilon(0.0001));
        actual_distance = p1.distance(Point(5, 0));
        CHECK(expected_distance == doctest::Approx(actual_distance).epsilon(0.0001));
    }

    SUBCASE("1.3 - Test moveTowards")
    {
        Point p2(3, 4);

        // Test distance less than distance between points
        double distance = 2.5;
        Point expected_point1(1.5, 2);
        Point actual_point1 = Point::moveTowards(p1, p2, distance);
        CHECK(expected_point1.getX() == doctest::Approx(actual_point1.getX()).epsilon(0.0001));
        CHECK(expected_point1.getY() == doctest::Approx(actual_point1.getY()).epsilon(0.0001));

        // Test distance greater than distance between points
        distance = 7.0;
        Point expected_point2(4.2, 5.6);
        Point actual_point2 = Point::moveTowards(p1, p2, distance);
        CHECK(expected_point2.getX() == doctest::Approx(actual_point2.getX()).epsilon(0.0001));
        CHECK(expected_point2.getY() == doctest::Approx(actual_point2.getY()).epsilon(0.0001));

        //Distance cannot be negative
        CHECK_THROWS(Point::moveTowards(p1, p2, -5.0));
    }
    SUBCASE("1.4 - Check Print")
    {
        CHECK_NOTHROW(p1.print()); // same as Point(0,0).print()
        CHECK_NOTHROW(Point(-1.2, 3.5).print());
        CHECK_NOTHROW(Point(1.2, -3.5).print());
    }
}

TEST_CASE("Test 2 - Character Functions")
{
    Point point_cowboy(0, 0);
    Point point_ninja_old(30, 40);
    Point point_ninja_tra(30, 40);
    Point point_ninja_yng(30, 40);

    SUBCASE("2.1 - Test initialization - basic")
    {
        // not sure if empty name valid
        CHECK_NOTHROW(Cowboy("", point_cowboy));
        CHECK_NOTHROW(YoungNinja("", point_ninja_yng));
        CHECK_NOTHROW(OldNinja("", point_ninja_old));
        CHECK_NOTHROW(TrainedNinja("", point_ninja_tra));
    }

    Cowboy cb ("Billy", point_cowboy);
    YoungNinja yn ("Youngin", point_ninja_yng);
    TrainedNinja tn ("Tony", point_ninja_tra);
    OldNinja old ("Sensei", point_ninja_old);

    SUBCASE("2.2 - Test getters")
    {
        CHECK_EQ(cb.getName(), "Billy");
        //all should be alive rn
        CHECK((cb.isAlive() && yn.isAlive() && tn.isAlive() && old.isAlive()));
        Point test_loc_yn = yn.getLocation();
        CHECK_EQ(test_loc_yn.getX(), point_ninja_yng.getX());
        CHECK_EQ(test_loc_yn.getY(), point_ninja_yng.getY());
    }

    SUBCASE("2.3 - Test Distance")
    {
        // https://github.com/doctest/doctest/blob/master/doc/markdown/assertions.md#floating-point-comparisons

        SUBCASE("2.3.1 - All ninjas from the same distance from cowboy")
        {
            double expected_distance_from_cowboy = 50;
            CHECK(expected_distance_from_cowboy == doctest::Approx(cb.distance(&yn)).epsilon(0.0001));
            CHECK(expected_distance_from_cowboy == doctest::Approx(cb.distance(&tn)).epsilon(0.0001));
            CHECK(expected_distance_from_cowboy == doctest::Approx(cb.distance(&old)).epsilon(0.0001));
        }
        SUBCASE("2.3.2 - Doesn't matter the order")
        {
            CHECK(yn.distance(&cb) == doctest::Approx(cb.distance(&yn)).epsilon(0.0001));
            CHECK(tn.distance(&cb) == doctest::Approx(cb.distance(&tn)).epsilon(0.0001));
            CHECK(old.distance(&cb) == doctest::Approx(cb.distance(&old)).epsilon(0.0001));
        }
        SUBCASE("2.3.3 - Same location points")
        {
            CHECK(tn.distance(&yn) == 0);
            CHECK(old.distance(&tn) == 0);
            CHECK(yn.distance(&old) == 0);
        }
    }
    SUBCASE("2.4 - Test Ninjas")
    {
        SUBCASE("2.4.1 - Test initialization")
        {
            //Health - tho it's guranteed by enums
            CHECK_EQ(yn.getHealth(), 100);
            CHECK_EQ(tn.getHealth(), 120);
            CHECK_EQ(old.getHealth(), 150);

            //Speed
            CHECK_EQ(yn.getSpeed(), 14);
            CHECK_EQ(tn.getSpeed(), 12);
            CHECK_EQ(old.getSpeed(), 8);

        }

        SUBCASE("2.4.2 - Test move")
        {
            //all ninjas move towards cowboy

            Point expected_point_y(21.6, 28.8);
            yn.move(&cb); 
            Point actual_point_y = yn.getLocation();
            CHECK(expected_point_y.getX() == doctest::Approx(actual_point_y.getX()).epsilon(0.0001));
            CHECK(expected_point_y.getY() == doctest::Approx(actual_point_y.getY()).epsilon(0.0001));

            Point expected_point_t(22.8, 30.4);
            tn.move(&cb);
            Point actual_point_t = tn.getLocation();
            CHECK(expected_point_t.getX() == doctest::Approx(actual_point_t.getX()).epsilon(0.0001));
            CHECK(expected_point_t.getY() == doctest::Approx(actual_point_t.getY()).epsilon(0.0001));

            Point expected_point_o(25.5, 33.6);
            old.move(&cb);
            Point actual_point_o = old.getLocation();
            CHECK(expected_point_o.getX() == doctest::Approx(actual_point_o.getX()).epsilon(0.0001));
            CHECK(expected_point_o.getY() == doctest::Approx(actual_point_o.getY()).epsilon(0.0001));
        }

        SUBCASE("2.4.3 - Test Slash")
        {
            ///TODO: add the following tests: cannot slash null, cannot slash self
            //ninjas too far to imply damage to cowboy
            yn.slash(&cb);
            tn.slash(&cb);
            old.slash(&cb);
            CHECK_EQ(cb.getHealth(), 110); //didn't get hit

            //ninjas can slash eachother, because at the same point
            yn.slash(&old);
            int expected_health = 137;
            CHECK_EQ(old.getHealth(), expected_health);
        }
    }

    SUBCASE("2.5 - Test Cowboy")
    {
        SUBCASE("2.5.1 - Test initialization")
        {
            CHECK_EQ(cb.getHealth(), 110);
            CHECK(cb.hasboolets());
        }
        SUBCASE("2.5.2 - Test Shoot")
        {
            cb.shoot(&yn);
            int expected_health = 90;
            CHECK_EQ(yn.getHealth(), expected_health);
            ///TODO: add the following tests: cannot shoot null, cannot shoot self
        }
    }
}
TEST_CASE("Test 3 - Team Functions")
{

    SUBCASE("3.1 - Test Team assembly")
    {
        ///TODO: add members to the team till it's full

    }


    SUBCASE("3.2 - Test Team attacks")
    {

    }

    SUBCASE("3.3 - Different Teams have different prints")
    {
       
    }
}