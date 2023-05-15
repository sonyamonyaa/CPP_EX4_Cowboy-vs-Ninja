#include "Ninja.hpp"
namespace ariel
{
    void Ninja::move(Character *enemy)
    {
        Point new_loc = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->getSpeed());
        this->setLocation(new_loc);
    }

    void Ninja::slash(Character *enemy)
    {
        if (!enemy)
        {
            throw string{"enemy is null"};
        }
        if (enemy == this)
        {
            throw string{"can't slash self"};
        }
        // TODO: add a test if a team member?
        if (this->distance(enemy) <= 1)
        {
            enemy->hit(PowerPoints::ninjaPP);
        }
        else
        {
            this->move(enemy);
        }
    }

    string Ninja::print() const
    {
        string represent = "N ";
        represent += Character::print();
        return represent;
    }
}