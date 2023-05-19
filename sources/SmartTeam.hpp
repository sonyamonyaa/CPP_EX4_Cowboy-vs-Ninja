#include "Team.hpp"
namespace ariel
{
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