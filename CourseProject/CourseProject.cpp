#include <iostream>
#include <windows.h>

#include "Date.h"
#include "Person.h"
#include "BuildingsQueue.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        Date date1(23, 1, 2003);
        //date1 += 10;
        std::cout << "You entered the date1: " << date1;

        Date* date2;
        Person person(date1, "Oleksii", "Pryadko", "software engineer", 50000, true);
        Person person1(date1, "Мамут", "Рахал", "software engineer", 75000, true);
        date2 = &person;

        std::cout << endl << endl << person;

        cout << endl << "Polymorphism demo" << endl << endl;

        date1.getDay();
        date2->getDay();
        date1.getMonth();
        date2->getMonth();

        cout << endl << "BuilingsQueue Demo" << endl << endl;

        BuildingsQueue queue;
        queue.add(person, Date(15, 2, 2024));
        queue.add(person1, Date(15, 4, 2025));

        cout << queue;

        cout << "" << endl;
        
    }
    catch (std::exception e) {
        std::cout << e.what();
    }

}