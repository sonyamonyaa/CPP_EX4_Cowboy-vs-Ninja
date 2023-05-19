#pragma once
#include <string>
#include "Point.hpp"

using std::string;

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
    ninjaPP = 40
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
        bool inTeam;

    public:
        
        int getHealth() const { return _health; }
        string getName() const { return _name; }
        Point getLocation() const { return _location; }
        bool isAlive() const { return _health > 0; } // is health > 0
        double distance(Character *other) const;     // the distance of this character from the other
        void hit(int damage);                        // health =- damage
        virtual string print() const;
        //assist funcs for entering a team and if is already in one
        void enterTeam() { inTeam = true; } 
        bool isInTeam() const{ return inTeam; }

        Character(const Character &) = default;
        Character &operator=(const Character &) = default;
        Character(Character &&) noexcept = default;
        Character &operator=(Character &&) noexcept = default;
        virtual ~Character() = default;

    protected:
        // Character() = default;

        Character(const string &name, const Point &loc, int health)
            : _name(name), _location(loc), _health(health), inTeam(false){};
        void setLocation(const Point &new_loc) { _location = new_loc; }
    };
}
