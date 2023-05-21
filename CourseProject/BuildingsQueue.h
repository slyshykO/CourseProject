#pragma once

#include "Person.h"
#include "Date.h"
#include <vector>
#include <utility> //for pair struct
#include <string>
#include <algorithm>

class BuildingsQueue
{
private:
	
public:
	static bool sortUtilFunction(std::pair<Person, Date>, std::pair<Person, Date>);

	std::vector<std::pair<Person, Date>> list;
	void add(Person, Date);
	Person getPerson(int);
	void sortByTheLengthOfStay();

	//std::string toString();

	friend std::ostream& operator << (std::ostream& os, const BuildingsQueue& date);
};