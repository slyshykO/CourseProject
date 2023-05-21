#include <iostream>

#include "Date.h"
#include "Person.h"

Person::Person(Date birthdate, std::string firstname, std::string lastname, std::string occupation, int salary, bool sex) : Date(birthdate)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->occupation = occupation;
	this->salary = salary;
	this->sex = sex;
}

Person::~Person() {}

void Person::setDay(int day)
{
	std::cout << "You set birthdate day to " << day << std::endl;
	Date::baseSetDay(day);
}

void Person::setMonth(int month)
{
	std::cout << "You set birthdate month to " << month << std::endl;
	Date::baseSetMonth(month);
}

void Person::setYear(int year)
{
	std::cout << "You set birthdate year to " << year << std::endl;
	Date::baseSetYear(year);
}

int Person::getDay() const
{
	std::cout << fullname() << "'s Birthdate day is: " << baseGetDay() << std::endl;
	return baseGetDay();
}

int Person::getMonth() const
{
	std::cout << fullname() << "'s Birthdate month is: " << baseGetMonth() << std::endl;
	return baseGetMonth();
}

int Person::getYear() const
{
	std::cout << fullname() << "'s Birthdate year is: " << baseGetYear() << std::endl;
	return baseGetYear();
}

std::string Person::fullname() const
{
	return firstname + " " + lastname;;
}

void Person::setFirstName(std::string firstname)
{
	if (&firstname == NULL || firstname.empty())
		throw new std::exception("Firstname value must be not empty!");
	this->firstname = firstname;
}

void Person::setLastName(std::string lastname)
{
	if (&lastname == NULL || lastname.empty())
		throw new std::exception("Lastname value must be not empty!");
	this->lastname = lastname;
}

void Person::setOccupation(std::string occupation)
{
	if (&occupation == NULL || occupation.empty())
		throw new std::exception("Lastname value must be not empty!");;
	this->occupation = occupation;
}

void Person::setSalary(int salary)
{
	if (salary < 0)
		throw new std::exception("Salary value must be greater than negative number!");
	this->salary = salary;
}

void Person::setSex(bool sex)
{
	this->sex = sex;
}

std::string Person::getFirstName()
{
	return firstname;
}

std::string Person::getLastName()
{
	return lastname;
}

std::string Person::getOccupation()
{
	return occupation;
}

int Person::getSalary()
{
	return salary;
}

bool Person::getSex()
{
	return sex;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	os << "Surname: " << person.lastname << std::endl;
	os << "Name: " << person.firstname << std::endl;
	os << "Birthdate: ";
	
	os << person.baseGetDay() << "." << person.baseGetMonth() << "." << person.baseGetYear() << std::endl;
	
	os << "Sex: " << (person.sex ? "Male" : "Female") << std::endl;
	os << "Salary: " << person.salary << std::endl;
	os << "Occupation: " << person.occupation << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, Person& person)
{
	std::string firstname;
	std::string lastname;
	std::string occupation;
	bool sex;
	int salary;

	int day;
	int month;
	int year;
	
	is >> day >> month >> year >> lastname >> firstname >> occupation >> salary >> sex;

	person.setMonth(month);
	person.setDay(day);
	person.setYear(year);
	person.setFirstName(lastname);
	person.setLastName(firstname);
	person.setOccupation(occupation);
	person.setSalary(salary);
	person.setSex(sex);

	return is;
}