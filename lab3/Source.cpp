#include "Header.h"
State *State::head = NULL;
int main()
{
	char name[10];
	int kolPeople;
	int area;
	State *a = new State(453, "Belarus", 1000000);
	a->add();
	a = new State(542, "France", 3000000);
	a->add();
	a = new State(743, "Germany", 5000000);
	a->add();
	State::show();
	system("pause");
}