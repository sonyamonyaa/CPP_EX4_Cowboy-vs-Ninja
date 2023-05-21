#include "Team.hpp"
namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader) : Team(leader){};
        void add(Character *member) override;
        void attack(Team *rival) override;
        // void print() const override;

        SmartTeam(const SmartTeam &) = default;
        SmartTeam &operator=(const SmartTeam &) = default;
        SmartTeam(SmartTeam &&) noexcept = default;
        SmartTeam &operator=(SmartTeam &&) noexcept = default;
        ~SmartTeam() override {};// Team already takes care of the container
    };
}