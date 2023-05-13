#include "Character.hpp"
namespace ariel
{
    double Character::distance(Character *other) const
    {
        return 0.0;
    }

    void Character::hit(int damage)
    {
    }

    /** name, health points, position.
     *          if dead, no health points, and name will be in parentheses
     *          before name would be a type indicator (N = ninja, C = cowboy)
     **/
    string Character::print() const
    {
        return string();
    }

    // Cowboy
    void Cowboy::shoot(Character *enemy)
    {
    }

    string Cowboy::print() const
    {
        return string();
    }

    // Ninja
    void Ninja::move(Character *enemy)
    {
    }

    void Ninja::slash(Character *enemy)
    {
    }

    string Ninja::print() const
    {
        return string();
    }
}
