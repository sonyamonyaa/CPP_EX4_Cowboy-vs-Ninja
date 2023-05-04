#pragma once
#include "Character.hpp"

#define MAX_MEMBERS 10
namespace ariel
{
    /**
     * A team consistant of 10 members at most, consistant of Charcters
     * Each team has a leader, as one of the members.
     * When a team is made, it gets a charcter pointer as leader
     *
     * Suggested iterations on team members:
     * 1. Team: First cowboys, then ninjas while within each group by order of addition //queue for each
     * 2. Team2: by order of addition, with no distinction between groups //general queue
     * 3. smart team: a different algorithm
     *      //put the leader as the root/start of the structure, add/iterate based on distance.
     *      // during the attack make a priority queue by ref? of the rivaling team to find scape goat?
     */
    class GeneralTeam
    {
    private:
        Character *_leader;

    public:
        GeneralTeam(Character *leader){setLeader(leader);};
        virtual ~GeneralTeam();
        void setLeader(Character *leader) {_leader = leader;}
        virtual void add(const Character &member) = 0; // add a team member

        /**
         * attack(Team rival):
         *      first check if the leader is alive, if dead appoint the closest member to the leader's last location
         *      Then, the attacking team chooses the scapegoat - the closest member of the rivaling team to the attacking leader
         *      All the team members will attack the chosen scapegoat
         *          Cowboys: if they have bullets they will shoot, otherwise will reload
         *          Ninjas: if close enough will slash, otherwise move towards them
         *      Each stage, if the scapegoat is dead, a new one will be chosen the same as before
         *      If there are no members in the attacking team or the rival team, the attack is over
         */
        virtual void attack(Team *rival) = 0;
        virtual int stillAlive() = 0; // number of members that are still alive
        virtual void print() = 0;     // goes over all the team members and prints them
    };

    class Team : public GeneralTeam
    {
    private:
        // queue ninjas, queue cowboys

    public:
        Team(Character *leader): GeneralTeam(leader){};
        ~Team();
        void add(const Character &member);

        void attack(Team *rival);
        int stillAlive();
        void print();
    };

    class Team2 : public GeneralTeam
    {
    private:
        /* data */
    public:
        Team2(Character *leader): GeneralTeam(leader){};
        ~Team2();
        void add(Character *member);

        void attack(Team *rival);
        int stillAlive();
        void print();
    };

    class SmartTeam : public GeneralTeam
    {
    private:
        /* data */
    public:
        SmartTeam(Character *leader): GeneralTeam(leader){};
        SmartTeam();
        void add(Character *member);

        void attack(Team *rival);
        int stillAlive();
        void print();
    };

    // Team::Team(/* args */)
    // {
    // }

    // Team::~Team()
    // {
    // }
}