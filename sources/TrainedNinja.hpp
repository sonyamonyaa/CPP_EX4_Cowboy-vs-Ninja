#pragma once
#include <string>
#include "Ninja.hpp"
namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const string &name, const Point &loc)
            : Ninja(name, loc, HealthPoints::trainedNinjaHP, Speed::trainedNinjaS){};

        TrainedNinja(const TrainedNinja &other) = default;
        TrainedNinja &operator=(const TrainedNinja &) = default;
        TrainedNinja(TrainedNinja &&) noexcept = default;
        TrainedNinja &operator=(TrainedNinja &&) noexcept = default;
        ~TrainedNinja() override = default;
    };
}