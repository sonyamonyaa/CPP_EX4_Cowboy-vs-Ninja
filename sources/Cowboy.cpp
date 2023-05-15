#include "Cowboy.hpp"
namespace ariel
{
    void Cowboy::shoot(Character *enemy)
    {
        if (!enemy)
        {
            throw string{"enemy is null"};
        }
        if (enemy == this)
        {
            throw string{"can't shoot self"};
        }
        // TODO: add a test if enemy a team member?

        if (this->hasboolets())
        {
            enemy->hit(PowerPoints::cowboyPP);
            this->bulletCount--;
        }
        else
        {
            this->reload();
        }
    }

    string Cowboy::print() const
    {
        string represent = "C ";
        represent += Character::print();
        return represent;
    }
}