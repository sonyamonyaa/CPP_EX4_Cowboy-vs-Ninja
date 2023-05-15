#include "Team.hpp"

/**
 * attack(Team rival):
 *      first check if the leader is alive, if dead appoint the closest member to the leader's last location
 *      Then, the attacking team chooses the weakest link - the closest member of the rivaling team to the attacking leader
 *      All the team members will attack the chosen weakest link
 *          Cowboys: if they have bullets they will shoot, otherwise will reload
 *          Ninjas: if close enough will slash, otherwise move towards them
 *      Each stage, if the weakest link is dead, a new one will be chosen the same as before
 *      If there are no members in the attacking team or the rival team, the attack is over
 */
namespace ariel
{
        //------------------TEAM------------------
        /**
         * First cowboys, then ninjas while within each group by order of addition
         */
        Team::Team(Character *leader)
        {
                this->leader = leader;
                add(leader);
        }

        void Team::add(Character *member)
        {
                
        }

        void Team::attack(Team *rival)
        {
        }

        int Team::stillAlive()
        {
                return 0;
        }

        void Team::print() const
        {
        }

        Team::~Team()
        {
        }

        //------------------TEAM2------------------
        /**
         * by order of addition, with no distinction between groups
         */
        void Team2::add(Character *member)
        {
        }

        void Team2::attack(Team *rival)
        {
        }
        void Team2::print() const
        {
        }
        Team2::~Team2()
        {
        }
        
        //----------------SMART TEAM----------------
        void SmartTeam::add(Character *member)
        {
        }

        void SmartTeam::attack(Team *rival)
        {
        }

        void SmartTeam::print() const
        {
        }
        SmartTeam::~SmartTeam()
        {
        }
}
