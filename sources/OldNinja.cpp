#include "OldNinja.hpp"
namespace ariel{
    OldNinja::OldNinja(const string &name, const Point &loc)
            : Ninja(name, loc, HealthPoints::oldNinjaHP, Speed::oldNinjaS){};
}