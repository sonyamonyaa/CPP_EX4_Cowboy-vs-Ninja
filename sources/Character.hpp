#pragma once
#include <string>
#include "Point.hpp"

using namespace std;

enum Health
{
    cowboy = 110,
    youngNinja = 100,
    trainedNinja = 120,
    oldNinja = 150
};
enum Speed
{
    youngNinja = 14,
    trainedNinja = 12,
    oldNinja = 8
};

enum Power
{
    cowboy = 10,
    ninja = 13
};

namespace ariel
{
    /**
     * Character
     * represents game character
     */
    class Character
    {
    private:
        string _name;
        int _health;
        Point &_location;
        const int _power; // how much damage a character can inflict

    public:
        Character(string name, Point &loc, int health, const int power) : _name(name), _location(loc),
                                                                          _health(health), _power(power){};
        virtual ~Character() { _location.~Point(); };
        string getName() { return _name; }
        Point getLocation() { return _location; }
        bool isAlive() { return _health > 0; }      // is health > 0
        double distance(Character *other);           // the distance of this character from the other
        void hit(int damage) { _health -= damage; } // health =- damage
        /** name, health points, position.
         *          if dead, no health points, and name will be in parentheses
         *          before name would be a type indicator (N = ninja, C = cowboy)
         **/
        virtual void print();
    };

    // Character::Character(/* args */)
    // {
    // }

    // Character::~Character()
    // {
    // }

    /**
     * Cowboy
     * an instance of a character, with 110 health points
     * has additional variable bulletCount, starting with 6 on construction
     **/
    class Cowboy : public Character
    {
    private:
        int bulletCount;

    public:
        Cowboy(string name, Point loc) : Character(name, loc, Health::cowboy, Power::cowboy), bulletCount(6){};
        ~Cowboy(){};

        bool hasboolets() { bulletCount > 0; } // if bulletCount > 0
        void reload() { bulletCount == 6; };   // reload bulletCount with 6
        void shoot(Character *enemy);           // inflict damage to the enemy, bullet count goes down by 1
    };
    /**
     * Ninja
     * an instance of a character
     * has additional variable movementSpeed
     **/
    class Ninja : public Character
    {
    private:
        int movementSpeed;

    public:
        Ninja(string name, Point loc, int health, int movSp) : Character(name, loc, health, Power::ninja),
                                                               movementSpeed(movSp){};
        ~Ninja(){};

        void move(Character *enemy);  // moves towards the enemy the distance as the movement speed
        void slash(Character *enemy); // if the distance is less than 1 meter, the ninja will inflict 13(?) damage points to enemy.
    };

    /**
     * there are 3 types of ninjas-
     * YoungNinja- movementSpeed = 14, health=100
     * TrainedNinja- movementSpeed = 12, health=120
     * OldNinja- movementSpeed = 8, health=150
     **/
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string name, Point loc) : Ninja(name, loc, Health::youngNinja, Speed::youngNinja){};
        ~YoungNinja(){};
    };

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string name, Point loc) : Ninja(name, loc, Health::trainedNinja, Speed::trainedNinja){};
        ~TrainedNinja(){};
    };

    class OldNinja : public Ninja
    {
    public:
        OldNinja(string name, Point loc) : Ninja(name, loc, Health::oldNinja, Speed::oldNinja){};
        ~OldNinja(){};
    };

}
