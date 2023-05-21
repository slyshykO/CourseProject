#pragma once

#include <iostream>
#include <map>

class Date {
private:
    int day;
    int month;
    int year;

    class Validator
    {
    private:
        static std::map<int, int> monthDaysMap;
        static std::map<int, int> initMonthDaysMap();
    public:
        static int getDaysByMonth(int month);
        
        Validator();

        void validateDay(int month, int day);
        void validateMonth(int month);
        void validateYear(int year);

        void validateAll(int day, int month, int year);
    };

    Validator validator;
protected:
    int baseGetDay() const;
    int baseGetMonth() const;
    int baseGetYear() const;

    void baseSetDay(int day);
    void baseSetMonth(int month);
    void baseSetYear(int year);
public:
    // конструктори
    Date();
    Date(int day, int month, int year);
    Date(const Date& other);

    // деструктор
    ~Date();

    // методи отримання значень полів
    virtual int getDay() const;
    virtual int getMonth() const;
    virtual int getYear() const;

    // методи встановлення значень полів
    virtual void setDay(int day);
    virtual void setMonth(int month);
    virtual void setYear(int year);

    void operator+=(int days);
    void operator-=(int days);
    void operator=(const Date& other);

    friend std::ostream& operator << (std::ostream& os, const Date& date);
    friend std::istream& operator >> (std::istream& os, Date& date);
    
    bool operator<(const Date&);
};