#pragma once
#include <vector>
#include "Character.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

const int MAX_MEMBERS = 10;
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

    class Team
    {
    private:
        // unsigned int cowboy_count;
        unsigned int curr_size;
        Character *leader;
        std::vector<Character *> teammates;

    public:
        Team(Character *leader);
        virtual void add(Character *member);
        virtual void attack(Team *rival);
        int stillAlive(); // shouldn't be so different from the rest
        void print() const;
        Character *find_closest(Character *target, Team *from_team);
        bool isFull() const { return curr_size == MAX_MEMBERS; }
        void setLeader(Character *new_leader) { this->leader = new_leader; }
        Character *getLeader() const { return this->leader; }
        const std::vector<Character *> &getTeammates() const {return teammates;}
        void insertTeammate(Character *member, bool front = false);
        Team(const Team &) = default;
        Team &operator=(const Team &) = default;
        Team(Team &&) noexcept = default;
        Team &operator=(Team &&) noexcept = default;
        virtual ~Team();
    };

}