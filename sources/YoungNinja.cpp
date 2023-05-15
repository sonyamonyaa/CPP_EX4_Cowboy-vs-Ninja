#include "YoungNinja.hpp"
namespace ariel{
    YoungNinja::YoungNinja(const string &name, const Point &loc)
            : Ninja(name, loc, HealthPoints::youngNinjaHP, Speed::youngNinjaS){};
}