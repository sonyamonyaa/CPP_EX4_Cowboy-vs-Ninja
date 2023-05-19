#include "Cowboy.hpp"
namespace ariel
{
    void Cowboy::reload()
    {
        if(this->isAlive())
        {
            bulletCount = MAX_BULLETS;
        }
        else{
            throw std::runtime_error{"Dead cowboy can't reload"};
        }
    }

    void Cowboy::shoot(Character *enemy)
    {
        if (!enemy)
        {
            throw std::runtime_error{"enemy is null"};
        }
        if (enemy == this)
        {
            throw std::runtime_error{"can't shoot self"};
        }
        if (!enemy->isAlive())
        {
            throw std::runtime_error{"can't shoot the dead"};
        }
        if(!this->isAlive())
        {
            throw std::runtime_error{"the dead cannot attack"};
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