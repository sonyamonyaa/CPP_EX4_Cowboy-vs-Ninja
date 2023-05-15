#include "doctest.h"
#include "sources/Team.hpp"

using namespace ariel;

TEST_SUITE("Test 1 - Point Functions" * doctest::skip(true))
{
    TEST_CASE("1.1 - Check Valid Creation")
    {
        CHECK_NOTHROW(Point(0, 0));
        CHECK_NOTHROW(Point(-1.2, 3.5));
        CHECK_NOTHROW(Point(1.2, -3.5));

        Point p(0, 0);
        CHECK_EQ(p.getX(), 0);
        CHECK_EQ(p.getY(), 0);
    }

    Point p1(0, 0);
    TEST_CASE("1.2 - Test Distance")
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

    TEST_CASE("1.3 - Test moveTowards")
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

        // Distance cannot be negative
        CHECK_THROWS(Point::moveTowards(p1, p2, -5.0));
    }
    TEST_CASE("1.4 - Check Print")
    {
        CHECK_NOTHROW(p1.print()); // same as Point(0,0).print()
        CHECK_NOTHROW(Point(-1.2, 3.5).print());
        CHECK_NOTHROW(Point(1.2, -3.5).print());
    }
}

TEST_SUITE("Test 2 - Character Functions" * doctest::skip(false))
{
    Point point_cowboy(0, 0);
    Point point_ninja(30, 40);

    TEST_CASE("2.1 - Test initialization - basic")
    {
        // not sure if empty name valid
        CHECK_NOTHROW(Cowboy("", point_cowboy));
        CHECK_NOTHROW(YoungNinja("", point_ninja));
        CHECK_NOTHROW(OldNinja("", point_ninja));
        CHECK_NOTHROW(TrainedNinja("", point_ninja));
    }

    TEST_CASE("2.2 - Test getters")
    {
        Cowboy cb("Billy", point_cowboy);
        YoungNinja yn("Youngin", point_ninja);
        TrainedNinja tn("Tony", point_ninja);
        OldNinja old("Sensei", point_ninja);
        CHECK_EQ(cb.getName(), "Billy");
        // all should be alive rn
        CHECK((cb.isAlive() && yn.isAlive() && tn.isAlive() && old.isAlive()));
        Point test_loc_yn = yn.getLocation();
        CHECK_EQ(test_loc_yn.getX(), point_ninja.getX());
        CHECK_EQ(test_loc_yn.getY(), point_ninja.getY());
    }

    TEST_CASE("2.3 - Test Distance")
    {
        Cowboy cb("Billy", point_cowboy);
        YoungNinja yn("Youngin", point_ninja);
        TrainedNinja tn("Tony", point_ninja);
        OldNinja old("Sensei", point_ninja);
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
    TEST_CASE("2.4 - Test Ninjas")
    {

        SUBCASE("2.4.1 - Test initialization")
        {
            YoungNinja yn("Youngin", point_ninja);
            TrainedNinja tn("Tony", point_ninja);
            OldNinja old("Sensei", point_ninja);
            // Health - tho it's guranteed by enums
            CHECK_EQ(yn.getHealth(), 100);
            CHECK_EQ(tn.getHealth(), 120);
            CHECK_EQ(old.getHealth(), 150);

            // Speed
            CHECK_EQ(yn.getSpeed(), 14);
            CHECK_EQ(tn.getSpeed(), 12);
            CHECK_EQ(old.getSpeed(), 8);
        }
        Cowboy cb("Billy", point_cowboy);
        SUBCASE("2.4.2 - Test move")
        {
            YoungNinja yn("Youngin", point_ninja);
            TrainedNinja tn("Tony", point_ninja);
            OldNinja old("Sensei", point_ninja);
            // all ninjas move towards cowboy

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

            Point expected_point_o(25.2, 33.6);
            old.move(&cb);
            Point actual_point_o = old.getLocation();
            CHECK(expected_point_o.getX() == doctest::Approx(actual_point_o.getX()).epsilon(0.0001));
            CHECK(expected_point_o.getY() == doctest::Approx(actual_point_o.getY()).epsilon(0.0001));
        }

        SUBCASE("2.4.3 - Test Slash")
        {
            YoungNinja yn("Youngin", point_ninja);
            TrainedNinja tn("Tony", point_ninja);
            OldNinja old("Sensei", point_ninja);
            
            // ninjas can slash eachother, because at the same point
            CHECK(yn.distance(&old) == 0);
            yn.slash(&old);
            int expected_health = 137;
            CHECK_EQ(old.getHealth(), expected_health);

            // ninjas too far to imply damage to cowboy
            yn.slash(&cb);
            tn.slash(&cb);
            old.slash(&cb);
            CHECK_EQ(cb.getHealth(), 110); // didn't get hit

            // ninjas can't attack themselves
            CHECK_THROWS(yn.slash(&yn));
            CHECK_THROWS(tn.slash(&tn));
            CHECK_THROWS(old.slash(&old));

            // can't attack null enemy
            CHECK_THROWS(yn.slash(NULL));
            CHECK_THROWS(tn.slash(NULL));
            CHECK_THROWS(old.slash(NULL));
        }
    }

    TEST_CASE("2.5 - Test Cowboy")
    {
        Cowboy cb("Billy", point_cowboy);
        YoungNinja yn("Youngin", point_ninja);
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
            // can't shoot themselves
            CHECK_THROWS(cb.shoot(&cb));
            // can't shoot null
            CHECK_THROWS(cb.shoot(NULL));
        }
    }
}

TEST_SUITE("Test 3 - Team Functions" * doctest::skip(true))
{
    // used in all tests
    Point arbit(0, 0); // arbituary point

    Cowboy ch1("", arbit);
    YoungNinja ch2("", arbit);
    TrainedNinja ch3("", arbit);
    OldNinja ch4("", arbit);
    TEST_CASE("3.1 - Test Team assembly")
    {
        Team squad(&ch1);
        CHECK_EQ(squad.stillAlive(), 1);

        // add ninjas
        squad.add(&ch2);
        squad.add(&ch3);
        squad.add(&ch4);
        CHECK_EQ(squad.stillAlive(), 4);

        SUBCASE("3.1.1 - impossible members")
        {

            // can't add existing member
            CHECK_THROWS(squad.add(&ch4));

            // can't add NULL member
            CHECK_THROWS(squad.add(NULL));

            // can't make a team with members from other team
            CHECK_THROWS(Team(&ch2));

            // can't steal a member from another team
            Cowboy other_leader("", arbit);
            Team other(&other_leader);
            CHECK_THROWS(other.add(&ch3));
        }

        SUBCASE("3.1.2 - full team")
        {
            Cowboy ch5("", arbit);
            Cowboy ch6("", arbit);
            Cowboy ch7("", arbit);
            Cowboy ch8("", arbit);
            Cowboy ch9("", arbit);
            Cowboy ch10("", arbit);

            squad.add(&ch5);
            squad.add(&ch6);
            squad.add(&ch7);
            squad.add(&ch8);
            squad.add(&ch9);
            squad.add(&ch10);

            // team has 10 members at most
            Cowboy outsider("", arbit);
            CHECK_THROWS(squad.add(&outsider));
        }
    }

    TEST_CASE("3.2 - Test Team attacks")
    {
        Team squad1(&ch1);
        squad1.add(&ch2);
        SUBCASE("3.2.3 - impossible attacks")
        {
            // can't attack yourself
            CHECK_THROWS(squad1.attack(&squad1));

            // can't attack null team
            CHECK_THROWS(squad1.attack(NULL));
        }

        SUBCASE("3.2.4 - attack another team")
        {
            Team squad2(&ch3);
            squad2.add(&ch4);

            CHECK_EQ(squad1.stillAlive(), 2);
            CHECK_EQ(squad2.stillAlive(), 2);

            while (squad2.stillAlive() > 0)
            {
                squad1.attack(&squad2);
            }
            // squad 2 all dead and cannot be attacked again
            CHECK_THROWS(squad1.attack(&squad2));

            // dead cannot attack back
            CHECK_THROWS(squad2.attack(&squad1));
        }
    }
}