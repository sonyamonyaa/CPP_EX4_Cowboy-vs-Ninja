#include "Team2.hpp"
namespace ariel
{
    //------------------TEAM2------------------
    /**
     * by order of addition, with no distinction between groups
     */
    void Team2::add(Character *member)
    {
        if (this->isFull())
            throw std::runtime_error{"Team reached max size"};
        if (member->isInTeam())
            throw std::runtime_error{"Character is already in a team"};
        Cowboy *new_cowboy = dynamic_cast<Cowboy *>(member);
        Ninja *new_ninja = dynamic_cast<Ninja *>(member);

        if (new_cowboy || new_ninja)
        {
            
            insertTeammate(member);
        }
        else
        {
            throw std::runtime_error{"Character is ambigous"};
        }
    }

    void Team2::attack(Team *rival)
    {
        Team::attack(rival); // pretty much the same attack sequence
    }
    // void Team2::print() const
    // {
    //     Team::print();
    // }
    // Team2::~Team2()
    // {
    //     //empty cuz Team already takes care of the teammates container
    //     // for (const auto &member : teammates)
	// 	// {
	// 	// 	delete member;
	// 	// }
	// 	// leader = NULL;
    // }
}