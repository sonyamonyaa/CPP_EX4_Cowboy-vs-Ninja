#include "SmartTeam.hpp"
namespace ariel
{
    //----------------SMART TEAM----------------
    /**
     * ninjas at the front of the container and the cowboys at the back
     * basically opposite addition order of Team
     * 
     * Attacking:
     *  first the ninjas find the closest enemy to them and move towards them if too far to attack
     *  meaning that ninjas won't needd to move too far before implying damage
     *  then, since the cowboys are immobile and have the lowest damage power
     *  they can be used to confirm kill the weakest members
     */
    void SmartTeam::add(Character *member)
    {
        
        if (this->isFull())
            throw std::runtime_error{"Team reached max size"};
        if (member->isInTeam())
            throw std::runtime_error{"Character is already in a team"};
        Cowboy *new_cowboy = dynamic_cast<Cowboy *>(member);
        Ninja *new_ninja = dynamic_cast<Ninja *>(member);

        if (new_cowboy)
        {
            insertTeammate(member);
        }
        else if (new_ninja)
        {
            insertTeammate(member, true);
        }
        else
        {
            throw std::runtime_error{"Character is ambigous"};
        }
    }
    Character *findWeakest(Team *team)
    {
        const std::vector<Character *> &teammates = team->getTeammates();
        int max_health = 999;
        Character *weakest = nullptr;
        for (const auto &member : teammates)
        {
            if (member->getHealth() < max_health && member->isAlive())
            {
                max_health = member->getHealth();
                weakest = member;
            }
        }
        return weakest;
    }
    void SmartTeam::attack(Team *rival)
    {
        // check attack is legit
        if (!rival)
        {
            throw std::invalid_argument{"enemy team is null"};
        }
        if (rival == this)
        {
            throw std::runtime_error{"Team can't attack itself"};
        }
        if (this->stillAlive() == 0)
        {
            throw std::runtime_error{"Dead Team cannot attack"};
        }
        if (rival->stillAlive() == 0)
        {
            throw std::runtime_error{"Team cannot attack a dead team"};
        }
        const std::vector<Character *> &teammates = this->getTeammates();
        if (!getLeader()->isAlive())
        {
            // perhaps find the first one alive
            for (auto &member : teammates)
            {
                if (member->isAlive())
                {
                    setLeader(member);
                    break;
                }
            }
        }
        for (auto &member : teammates)
        {
            if (!member->isAlive()) continue;
            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
            Ninja *ninja = dynamic_cast<Ninja *>(member);
            // ninja attacks the closest one to him
            if (ninja)
            {
                Character *target = find_closest(member, rival);
                if (ninja->distance(target) <= 1)
                {
                    ninja->slash(target);
                }
                else
                {
                    ninja->move(target);
                }
            }
            // cowboy attacks the weakest at the moment
            if (cowboy){
                Character *target = findWeakest(rival);
                cowboy->shoot(target);
            }
        }
    }

    // void SmartTeam::print() const
    // {
    //     Team::print();
    // }
    // SmartTeam::~SmartTeam()
    // {
    //     // no need for content because Team takes care of the container
    // }
}
