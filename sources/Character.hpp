#pragma once
#include <string>
#include "Point.hpp"

using namespace std;

enum HealthPoints
{
    cowboyHP = 110,
    youngNinjaHP = 100,
    trainedNinjaHP = 120,
    oldNinjaHP = 150
};
enum Speed
{
    youngNinjaS = 14,
    trainedNinjaS = 12,
    oldNinjaS = 8
};

enum PowerPoints
{
    cowboyPP = 10,
    ninjaPP = 13
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
        Point _location;
        int _power; // how much damage a character can inflict

    public:
        int getHealth() const { return _health; }
        string getName() const { return _name; }
        Point getLocation() const { return _location; }
        bool isAlive() const { return _health > 0; } // is health > 0
        double distance(Character *other) const;     // the distance of this character from the other
        void hit(int damage);// health =- damage
        virtual string print() const;
        
        Character(const Character &) = default;
        Character &operator=(const Character &) = default;
        Character(Character&&) noexcept = default;
        Character& operator=(Character&&) noexcept = default;
        virtual ~Character() = default;

    protected:
        // Character() = default;
        Character(const string &name, const Point &loc, int health, const int power)
            : _name(name), _location(loc), _health(health), _power(power){};
    };

    /**
     * Cowboy
     * an instance of a character, with 110 health points
     * has additional variable bulletCount, starting with 6 on construction
     **/
    const int MAX_BULLETS = 6;
    class Cowboy : public Character
    {
    private:
        int bulletCount;

    public:
        Cowboy(const string &name, const Point &loc) : Character(name, loc, HealthPoints::cowboyHP, PowerPoints::cowboyPP), bulletCount(MAX_BULLETS){};

        bool hasboolets() const { return bulletCount > MAX_BULLETS; } // if bulletCount > 0
        void reload() { bulletCount = MAX_BULLETS; };                 // reload bulletCount with 6
        void shoot(Character *enemy);                                 // inflict damage to the enemy, bullet count goes down by 1
        string print() const override;

        Cowboy(const Cowboy &) = default;
        Cowboy &operator=(const Cowboy &) = default;
        Cowboy(Cowboy&&) noexcept = default;
        Cowboy& operator=(Cowboy&&) noexcept = default;
        ~Cowboy() override = default;
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
        int getSpeed() const { return movementSpeed; }
        void move(Character *enemy);  // moves towards the enemy the distance as the movement speed
        void slash(Character *enemy); // if the distance is at most 1 meter, the ninja will inflict 13(?) damage points to enemy.
        string print() const override;

        Ninja(const Ninja &) = default;
        Ninja &operator=(const Ninja &) = default;
        Ninja(Ninja&&) noexcept = default;
        Ninja& operator=(Ninja&&) noexcept = default;
        ~Ninja() override = default;

    protected:
        Ninja(const string &name, const Point &loc, HealthPoints health, int movSp)
            : Character(name, loc, health, PowerPoints::ninjaPP), movementSpeed(movSp){};
    };

    /**
     * there are 3 types of ninjas-
     * YoungNinja- movementSpeed = 14, health=100
     * TrainedNinja- movementSpeed = 12, health=120
     * OldNinja- movementSpeed = 8, health=150
     **/
    class YoungNinja : public Ninja
    {
    private:
    public:
        YoungNinja(const string &name, const Point &loc)
            : Ninja(name, loc, HealthPoints::youngNinjaHP, Speed::youngNinjaS){};

        YoungNinja(const YoungNinja &other) = default;
        YoungNinja &operator=(const YoungNinja &) = default;
        YoungNinja(YoungNinja&&) noexcept = default;
        YoungNinja& operator=(YoungNinja&&) noexcept = default;
        ~YoungNinja() override = default;
    };

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const string &name, const Point &loc)
            : Ninja(name, loc, HealthPoints::trainedNinjaHP, Speed::trainedNinjaS){};

        TrainedNinja(const TrainedNinja &other) = default;
        TrainedNinja &operator=(const TrainedNinja &) = default;
        TrainedNinja(TrainedNinja&&) noexcept = default;
        TrainedNinja& operator=(TrainedNinja&&) noexcept = default;
        ~TrainedNinja() override = default;
    };

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const string &name, const Point &loc)
            : Ninja(name, loc, HealthPoints::oldNinjaHP, Speed::oldNinjaS){};

        OldNinja(const OldNinja &other) = default;
        OldNinja &operator=(const OldNinja &) = default;
        OldNinja(OldNinja&&) noexcept = default;
        OldNinja& operator=(OldNinja&&) noexcept = default;
        ~OldNinja() override = default;
    };

}
