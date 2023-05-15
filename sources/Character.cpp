#include "Character.hpp"
namespace ariel
{
    double Character::distance(Character *other) const
    {
        double dist = this->getLocation().distance(other->getLocation());
        return dist;
    }

    void Character::hit(int damage)
    {
        this->_health -= damage;
        if (this->_health < 0)
        {
            this->_health = 0;
        }
    }

    /** name, health points, position.
     *          if dead, no health points, and name will be in parentheses
     *          before name would be a type indicator (N = ninja, C = cowboy)
     **/
    string Character::print() const
    {
        string represent = "";
        if (this->isAlive())
        {
            represent += this->_name;
            represent += " health:" + std::to_string(this->_health);
        }
        else
        {
            represent += "(" + this->_name + ")";
        }
        represent += " position:" + this->getLocation().toStr(); // doesn't say if position needed when dead
        return represent;
    }
}
