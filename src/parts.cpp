#include <iostream>
#include "parts.h"
using namespace std;

NameContainer partContainer;

void Part::describe()
{
	cout << "Part ";
	cout << name;
	cout << " subparts are:";
	cout << endl;
	if (subparts.empty())
	{
		cout << "There are no subparts";
		cout << endl;
	}
	else
	{
		for (map<Part *, int>::const_iterator iterator = subparts.begin(); iterator != subparts.end(); iterator++)
		{
			cout << "\t";
			cout << iterator->second;
			cout << " ";
			cout << iterator->first->name;
			cout << endl;
		}
	}
}

int Part::count_howmany(Part const* part)
{
	if(this != part && !subparts.empty())
	{
		int amount = 0;
		for (map<Part *, int>::const_iterator iterator = subparts.begin(); iterator != subparts.end(); iterator++)
			amount += iterator->first->count_howmany(part) * iterator->second;
		return amount;
	}
	else
	{
		if (this == part)
			return 1;
		else
		{
			if (subparts.empty())
				return 0;
		}
	}
}

Part* NameContainer::lookup(std::string const& name)
{
	map<string, Part*>::const_iterator iterator = name_map.find(name);
	Part *part = new Part(name);
	if (iterator != name_map.end())
		return iterator->second;
	else
		name_map.insert(make_pair(name, part));
	return part;
}

void add_part(std::string const& x, int q, std::string const& y)
{
	Part* part = partContainer.lookup(x);
	Part* subpart = partContainer.lookup(y);
	subpart->parent = part;
	part->subparts.insert(make_pair(subpart, q));
}

NameContainer::~NameContainer()
{
	for (map<string, Part*>::const_iterator iterator = name_map.begin(); iterator != name_map.end(); iterator++)
		delete iterator->second;
}
