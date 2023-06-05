/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;
#include "sources/Team.hpp"
#include "sources/Team2.hpp" //no need for other includes
#include "sources/SmartTeam.hpp"
using namespace ariel;
void demo(){
	Point a(32.3, 44), b(1.3, 3.5);
	assert(a.distance(b) == b.distance(a));
	Cowboy *tom = new Cowboy("Tom", a);
	OldNinja *sushi = new OldNinja("sushi", b);
	tom->shoot(sushi);

	sushi->move(tom);
	sushi->slash(tom);

	cout << tom->print() << endl;
	cout << sushi->print() << endl;
}

void demo_team(){
	Point a(32.3, 44), b(1.3, 3.5);
	Cowboy *tom = new Cowboy("Tom", a);
	OldNinja *sushi = new OldNinja("sushi", b);
	
	Team team_A(tom);
	team_A.add(new YoungNinja("Yogi", Point(64, 57)));
	team_A.add(new TrainedNinja("Tony", a));
	team_A.add(new OldNinja("sensei", Point(44, 32.3)));
	// Team b(tom); should throw tom is already in team a

	Team team_B(sushi);
	team_B.add(new Cowboy ("Billy", b));
	team_B.add(new YoungNinja("Yogi", Point(57, 64)));
	team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

	// team_A.print();
	// team_B.print();
	while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
	{
		team_A.attack(&team_B);
		if(team_B.stillAlive()>0) team_B.attack(&team_A);
		// team_A.print();
		// team_B.print();
	}

	if (team_A.stillAlive() > 0)
		cout << "winner is team_A" << endl;
	else
		cout << "winner is team_B" << endl;
}

void demo_team2(){
	Point a(32.3, 44), b(1.3, 3.5);
	Cowboy *tom = new Cowboy("Tom", a);
	OldNinja *sushi = new OldNinja("sushi", b);

	Team2 team_A(tom);
	team_A.add(new YoungNinja("Yogi", Point(64, 57)));
	team_A.add(new TrainedNinja("Tony", a));
	team_A.add(new OldNinja("sensei", Point(44, 32.3)));
	Team2 team_B(sushi);
	team_B.add(new Cowboy ("Billy", b));
	team_B.add(new YoungNinja("Yogi", Point(57, 64)));
	team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

	while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
	{
		team_A.attack(&team_B);
		if(team_B.stillAlive()>0) team_B.attack(&team_A);
		// team_A.print();
		// team_B.print();
	}

	if (team_A.stillAlive() > 0)
		cout << "winner is team_A" << endl;
	else
		cout << "winner is team_B" << endl;

}

void demo_smart(){
	Point a(32.3, 44), b(1.3, 3.5);
	Cowboy *tom = new Cowboy("Tom", a);
	OldNinja *sushi = new OldNinja("sushi", b);

	Team team_A(tom);
	team_A.add(new YoungNinja("Yogi", Point(64, 57)));
	team_A.add(new TrainedNinja("Tony", a));
	team_A.add(new OldNinja("sensei", Point(44, 32.3)));

	SmartTeam team_B(sushi);
	team_B.add(new Cowboy ("Billy", b));
	team_B.add(new YoungNinja("Yogi", Point(57, 64)));
	team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

	while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
	{
		team_A.attack(&team_B);
		if(team_B.stillAlive()>0) team_B.attack(&team_A);
		// team_A.print();
		// team_B.print();
	}

	if (team_A.stillAlive() > 0)
		cout << "winner is team_A" << endl;	else
		cout << "winner is team_B" << endl;

}
int main()
{	
	cout<<"DEMO"<<endl;
	demo();
	cout<<"----------------"<<endl;
	cout<<"TEAM DEMO"<<endl;
	demo_team();
	cout<<"----------------"<<endl;
	cout<<"TEAM2 DEMO"<<endl;
	demo_team2();
	cout<<"----------------"<<endl;
	cout<<"SMART DEMO"<<endl;
	demo_smart();
	return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.
}
