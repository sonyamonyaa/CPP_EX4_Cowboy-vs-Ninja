#include <algorithm>
#include "Team.hpp"
// #include <stdexcept>
/**
 * attack(Team rival):
 *      first check if the leader is alive, if dead appoint the closest member to the leader's last location
 *      Then, the attacking team chooses the weakest link - the closest member of the rivaling team to the attacking leader
 *      All the team members will attack the chosen weakest link
 *          Cowboys: if they have bullets they will shoot, otherwise will reload
 *          Ninjas: if close enough will slash, otherwise move towards them
 *      Each stage, if the weakest link is dead, a new one will be chosen the same as before
 *      If there are no members in the attacking team or the rival team, the attack is over
 */
namespace ariel
{
	//------------------TEAM------------------
	/**
	 * First cowboys, then ninjas while within each group by order of addition
	 */
	Team::Team(Character *leader) : curr_size(0)
	{
		this->leader = leader;
		add(leader);
	}

	// add cowboys at the front, ninjas at the back
	void Team::add(Character *member)
	{
		if (curr_size == MAX_MEMBERS)
			throw std::runtime_error{"Team reached max size"};
		if (member->isInTeam())
			throw std::runtime_error{"Character is already in a team"};

		Cowboy *new_cowboy = dynamic_cast<Cowboy *>(member);
		Ninja *new_ninja = dynamic_cast<Ninja *>(member);

		if (new_cowboy)
		{
			insertTeammate(member);
		}
		else if (new_ninja)
		{
			insertTeammate(member, true);
		}
		else
		{
			throw std::runtime_error{"Character is ambigous"};
		}
	}
	Character *Team::find_closest(Character *target, Team *from_team)
	{
		Character *closest = NULL;
		int min_distance = INT32_MAX;
		for (const auto &member : from_team->teammates)
		{
			if (member->isAlive())
			{
				int curr_distance = member->distance(target);
				if (curr_distance < min_distance)
				{
					min_distance = curr_distance;
					closest = member;
				}
			}
		}
		return closest;
	}

	void Team::insertTeammate(Character *member, bool front)
	{
		curr_size++;
		member->enterTeam();
		if (!front)
		{
			teammates.push_back(member);
		}
		else
		{
			teammates.insert(teammates.begin(), member);
		}
	}

	void Team::attack(Team *rival)
	{
		// check attack is legit
		if (!rival)
		{
			throw std::invalid_argument{"enemy team is null"};
		}
		if (rival == this)
		{
			throw std::runtime_error{"Team can't attack itself"};
		}
		if (this->stillAlive() == 0)
		{
			throw std::runtime_error{"The dead cannot attack"};
		}
		if (rival->stillAlive() == 0)
		{
			throw std::runtime_error{"Team cannot attack a dead team"};
		}
		if (!this->leader->isAlive())
		{
			this->leader = find_closest(this->leader, this);
		}
		Character *target = find_closest(this->leader, rival);
		if (target == NULL)
			return; // no target found

		for (const auto &member : teammates) // the structures order is already first cowboys and then ninjas
		{
			if (member->isAlive() && target->isAlive())
			{
				Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
				Ninja *ninja = dynamic_cast<Ninja *>(member);

				if (cowboy)
				{
					cowboy->shoot(target); // would reload if doesn't have bullets
				}
				if (ninja)
				{
					if (ninja->distance(target) <= 1)
					{
						ninja->slash(target);
					}
					else
					{
						ninja->move(target);
					}
				}
			}
			if (!target->isAlive() && rival->stillAlive() > 0) // change the target if dead
			{
				target = find_closest(this->leader, rival);
			}
		}
	}

	int Team::stillAlive()
	{
		// iterator does not consider null member so count if should work
		int alive_members = std::count_if(teammates.begin(), teammates.end(), [](Character *member)
										  { return member && member->isAlive(); });
		return alive_members;
	}

	void Team::print() const
	{
		using std::cout;
		using std::endl;
		cout << "-----------------------------" << endl;
		for (const auto &member : teammates)
		{
			if (member == leader)
			{
				cout << "LEADER";
			}
			cout << "\t" << member->print() << endl;
		}
		cout << "-----------------------------" << endl;
	}

	Team::~Team()
	{
		for (const auto &member : teammates)
		{
			delete member;
		}
		leader = NULL;
	}
}
