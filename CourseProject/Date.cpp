#include <iostream>
#include "Date.h"

std::map<int, int> Date::Validator::monthDaysMap = initMonthDaysMap();

Date::Date() : validator()
{
    day = 1;
    month = 1;
    year = 1900;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y), validator()
{
    validator.validateAll(d, m, y);

    /*this->day = d;
    this->month = m;
    this->year = y;*/
}

Date::Date(const Date& other) : validator()
{ 
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

Date::~Date() {}

std::map<int, int> Date::Validator::initMonthDaysMap()
{
    std::map<int, int> monthDaysMap;
    monthDaysMap.emplace(std::make_pair(1, 31));  //JANUARY
    monthDaysMap.emplace(std::make_pair(2, 28));  //FEBRUARY,
    monthDaysMap.emplace(std::make_pair(3, 31));  //MARCH
    monthDaysMap.emplace(std::make_pair(4, 30));  //APRIL
    monthDaysMap.emplace(std::make_pair(5, 31));  //MAY
    monthDaysMap.emplace(std::make_pair(6, 30));  //JUNE
    monthDaysMap.emplace(std::make_pair(7, 31));  //JULY
    monthDaysMap.emplace(std::make_pair(8, 31));  //AUGUST
    monthDaysMap.emplace(std::make_pair(9, 30));  //SEPTEMBER
    monthDaysMap.emplace(std::make_pair(10, 31)); //OCTOBER
    monthDaysMap.emplace(std::make_pair(11, 30)); //NOVEMBER
    monthDaysMap.emplace(std::make_pair(12, 31)); //DECEMBER
    return monthDaysMap;
}

int Date::Validator::getDaysByMonth(int month)
{
    return monthDaysMap.at(month);
}

Date::Validator::Validator()
{
    
}

void Date::Validator::validateDay(int month, int day)
{
    if (day < 1 || day > monthDaysMap.at(month))
        throw std::exception("Incorrect day value!");
}

void Date::Validator::validateMonth(int month)
{
    if (month < 1 || month > 12)
        throw std::exception("Incorrect month value!");
}

void Date::Validator::validateYear(int year)
{
    if (year < 1900 || year > 2100)
        throw std::exception("Incorrect year value!");
}

void Date::Validator::validateAll(int day, int month, int year)
{
    validateMonth(month);
    validateDay(month, day);
    validateYear(year);
}

int Date::baseGetDay() const
{
    return day;
}

int Date::baseGetMonth() const
{
    return month;
}

int Date::baseGetYear() const
{
    return year;
}

void Date::baseSetDay(int day)
{
    validator.validateDay(month, day);
    this->day = day;
}

void Date::baseSetMonth(int month)
{
    validator.validateMonth(month);
    this->month = month;
}

void Date::baseSetYear(int year)
{
    validator.validateMonth(month);
    this->month = month;
}

// Методи налаштування значень полів
void Date::setDay(int day)
{
    std::cout << "You set date day to " << day << std::endl;
    baseSetDay(day);
}

void Date::setMonth(int month) 
{
    std::cout << "You set date month to " << month << std::endl;
    baseSetDay(month);
}

void Date::setYear(int year) 
{
    std::cout << "You set date year to " << year << std::endl;
    baseSetYear(year);
}

// Методи отримання значень полів
int Date::getDay() const {
    std::cout << "Date day is: " << day << std::endl;
    return baseGetDay();
}

int Date::getMonth() const {
    std::cout << "Date month is: " << month << std::endl;
    return baseGetMonth();
}

int Date::getYear() const {
    std::cout << "Date year is: " << year << std::endl;
    return baseGetYear();
}

void Date::operator += (int days)
{
    if (days < 0) 
        *this -= (-days);
    else if (this->day + days <= Date::Validator::getDaysByMonth(month))
        this->day = this->day + days;
    else 
    {
        int prevMonthDays = Date::Validator::getDaysByMonth(month);
        if (this->month < 12)
            this->month++;
        else 
        {
            this->month = 1;
            setYear(year + 1);
        }
        
        //Доробити пізніше
        *this += (days - (prevMonthDays - days));
    }

}

void Date::operator -= (int days)
{
    if (days < 0)
        *this += (-days);
    else if (this->day - days >= 1)
        this->day = this->day - days;
    else
    {
        if (this->month > 1)
            this->month--;
        else
        {
            this->month = 12;
            setYear(year - 1);
            this->day += Date::Validator::getDaysByMonth(month);
        }

        //Доробити пізніше
        *this -= days;
    }
}

void Date::operator = (const Date& other)
{
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

bool Date::operator<(const Date& another)
{
    return this->year < another.year
        || this->month < another.month
        || this->day < another.day;
}

std::ostream& operator << (std::ostream& os, const Date& date)
{
    os << date.day << "." << date.month << "." << date.year;
    return os;
}

std::istream& operator >> (std::istream& is, Date& date)
{    
    int day, month, year;
    
    try 
    {
        is >> day;
        is >> month;
        date.setMonth(month);
        date.setDay(day);
        is >> year;
        date.setYear(year);
       
        return is;
    }

    catch (std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    
}