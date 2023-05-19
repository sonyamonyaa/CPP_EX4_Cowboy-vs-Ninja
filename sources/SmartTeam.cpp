#include "SmartTeam.hpp"
namespace ariel
{
    //----------------SMART TEAM----------------
    //
    void SmartTeam::add(Character *member)
    {
        if (this->isFull())
            throw std::runtime_error{"Team reached max size"};
        if (member->isInTeam())
            throw std::runtime_error{"Character is already in a team"};
        Cowboy *new_cowboy = dynamic_cast<Cowboy *>(member);
        Ninja *new_ninja = dynamic_cast<Ninja *>(member);

        if (new_cowboy || new_ninja)
        {
            member->enterTeam();
            teammates.push_back(member);
            updateSize();
        }
        else
        {
            throw std::runtime_error{"Character is ambigous"};
        }
    }

    void SmartTeam::attack(Team *rival)
    {
    }

    void SmartTeam::print() const
    {
    }
    SmartTeam::~SmartTeam()
    {
        for (const auto &member : teammates)
        {
            delete member;
        }
        leader = NULL;
    }
}
