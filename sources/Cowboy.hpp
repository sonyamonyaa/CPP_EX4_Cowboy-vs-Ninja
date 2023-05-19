#pragma once
#include <string>
#include "Character.hpp"

const int MAX_BULLETS = 6;
const int NO_BULLETS = 0;
namespace ariel
{
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
        Cowboy(const string &name, const Point &loc) : Character(name, loc, HealthPoints::cowboyHP), bulletCount(MAX_BULLETS){};

        bool hasboolets() const { return bulletCount > NO_BULLETS; } // if bulletCount > 0
        void reload();                // reload bulletCount with 6
        void shoot(Character *enemy);                                // inflict damage to the enemy, bullet count goes down by 1
        string print() const override;

        Cowboy(const Cowboy &) = default;
        Cowboy &operator=(const Cowboy &) = default;
        Cowboy(Cowboy &&) noexcept = default;
        Cowboy &operator=(Cowboy &&) noexcept = default;
        ~Cowboy() override = default;
    };
}