#include "TrainedNinja.hpp"
namespace ariel
{
    TrainedNinja::TrainedNinja(const string &name, const Point &loc)
        : Ninja(name, loc, HealthPoints::trainedNinjaHP, Speed::trainedNinjaS){};
}