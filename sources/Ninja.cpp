// #include <algorithm>
#include "Ninja.hpp"
namespace ariel
{
    void Ninja::move(Character *enemy)
    {
        double dist = std::min(this->distance(enemy), double(this->getSpeed()));
        Point new_loc = Point::moveTowards(this->getLocation(), enemy->getLocation(), dist);
        this->setLocation(new_loc);
    }

    void Ninja::slash(Character *enemy)
    {
        if (!enemy)
        {
            throw std::runtime_error{"enemy is null"};
        }
        if (enemy == this)
        {
            throw std::runtime_error{"can't slash self"};
        }
        if (!enemy->isAlive())
        {
            throw std::runtime_error{"can't slash the dead"};
        }
        if (!this->isAlive())
        {
            throw std::runtime_error{"the dead cannot attack"};
        }
        // TODO: add a test if a team member?
        if (this->distance(enemy) <= 1)
        {
            enemy->hit(PowerPoints::ninjaPP);
        }
    }

    string Ninja::print() const
    {
        string represent = "N ";
        represent += Character::print();
        return represent;
    }
}