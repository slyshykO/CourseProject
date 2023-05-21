#include "BuildingsQueue.h"
#include <list>
#include <algorithm>

bool BuildingsQueue::sortUtilFunction(std::pair<Person, Date> i, std::pair<Person, Date> j)
{
	return i.second < j.second;
}

void BuildingsQueue::add(Person person, Date date)
{
	list.push_back(std::pair<Person, Date>(person, date));
}

Person BuildingsQueue::getPerson(int index)
{
	return list[index].first;
}

void BuildingsQueue::sortByTheLengthOfStay()
{
	std::sort(list.begin(), list.end(), sortUtilFunction);
}

//std::string BuildingsQueue::toString()
//{
//    std::string result("Buildings Queue {");
//
//	/*int i = 1;
//	for (auto iter = BuildingsQueue::list.begin(); iter != list.end(); iter++) {
//		result += i++ + ".) " + iter->first + " - " + iter->second + "\n"
//	}*/
//
//	return result;
//
//}

std::ostream& operator << (std::ostream& os, const BuildingsQueue& buildingsQueue)
{
	int i = 1;
	os << "Buildings Queue { \n";
	for (auto iter = buildingsQueue.list.begin(); iter != buildingsQueue.list.end(); iter++)
	{
		os << i++ << ".) " << iter->first << " - " << iter->second << "\n";
	}
	os << "\n} ";
	return os;
}