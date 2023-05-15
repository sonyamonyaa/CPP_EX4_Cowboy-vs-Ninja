#pragma once
#include <string>
#include "Character.hpp"
namespace ariel
{
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
        Ninja(Ninja &&) noexcept = default;
        Ninja &operator=(Ninja &&) noexcept = default;
        ~Ninja() override = default;

    protected:
        Ninja(const string &name, const Point &loc, HealthPoints health, int movSp)
            : Character(name, loc, health), movementSpeed(movSp){};
    };
}