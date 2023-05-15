#pragma once
#include <string>
#include "Ninja.hpp"
namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(const string &name, const Point &loc)
            : Ninja(name, loc, HealthPoints::oldNinjaHP, Speed::oldNinjaS){};

        OldNinja(const OldNinja &other) = default;
        OldNinja &operator=(const OldNinja &) = default;
        OldNinja(OldNinja &&) noexcept = default;
        OldNinja &operator=(OldNinja &&) noexcept = default;
        ~OldNinja() override = default;
    };
}