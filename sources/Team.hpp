#pragma once
#include <array>
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
    public:
        Team(Character *leader);
        virtual void add(Character *member);
        virtual void attack(Team *rival);
        int stillAlive(); // shouldn't be so different from the rest
        virtual void print() const;

        Team(const Team &) = default;
        Team &operator=(const Team &) = default;
        Team(Team &&) noexcept = default;
        Team &operator=(Team &&) noexcept = default;
        virtual ~Team();

        // protected:
        Character *leader;
        std::array<Character *, MAX_MEMBERS> team = {nullptr};
    };

    class Team2 : public Team
    {
    public:
        Team2(Character *leader) : Team(leader){};
        void add(Character *member) override;
        void attack(Team *rival) override;
        void print() const override;

        Team2(const Team2 &) = default;
        Team2 &operator=(const Team2 &) = default;
        Team2(Team2 &&) noexcept = default;
        Team2 &operator=(Team2 &&) noexcept = default;
        ~Team2() override;
    };

    class SmartTeam : public Team
    {
        /**
         * In this implementation, the find_weakest_link() method takes the opponent's leader point as an argument,
         * and calculates the distance of each member from that point using the Euclidean distance formula.
         * The members are then added to a priority queue with their distance as priority,
         * and the member with the highest priority (i.e., the member closest to the opponent's leader)
         * is returned as the weakest link.
         */
    public:
        SmartTeam(Character *leader) : Team(leader){};
        void add(Character *member) override;
        void attack(Team *rival) override;
        void print() const override;

        SmartTeam(const SmartTeam &) = default;
        SmartTeam &operator=(const SmartTeam &) = default;
        SmartTeam(SmartTeam &&) noexcept = default;
        SmartTeam &operator=(SmartTeam &&) noexcept = default;
        ~SmartTeam() override;
    };
}