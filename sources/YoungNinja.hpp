#pragma once
#include <string>
#include "Ninja.hpp"
namespace ariel
{
    class YoungNinja : public Ninja
    {
    private:
    public:
        YoungNinja(const string &name, const Point &loc)
            : Ninja(name, loc, HealthPoints::youngNinjaHP, Speed::youngNinjaS){};

        YoungNinja(const YoungNinja &other) = default;
        YoungNinja &operator=(const YoungNinja &) = default;
        YoungNinja(YoungNinja &&) noexcept = default;
        YoungNinja &operator=(YoungNinja &&) noexcept = default;
        ~YoungNinja() override = default;
    };
}