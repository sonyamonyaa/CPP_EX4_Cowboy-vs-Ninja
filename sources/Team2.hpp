#include "Team.hpp"
namespace ariel
{
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
}