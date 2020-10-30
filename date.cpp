#include <iostream>
#include "date.h"

//konstruktor domyślny
Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
}

//konstruktor argumentowy
Date::Date(unsigned day, unsigned month, int year)
{
    //sprawdzenie niepoprawnych argumentów
    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        return;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
    {
        return;
    }

    if (month == 2)
    {
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            if(day > 29)
            {
                return;
            }
        } 
        else 
        {
            if(day > 28)
            {
                return;
            }
        }
    }

    this -> day = day;
    this -> month = month;
    this -> year = year;
}

Date::Date(const Date& source)

{
    this -> day = source.day;
    this -> month = source.month;
    this -> year = source.year;
}

//Temat const
//Jest to funkcja stała, co oznacza funkcję, która nie zmieni żadnych zmiennych składowych klasy, do której należy. 
//Jest to styl zalecany dla getterów, ponieważ ich jedynym celem jest pobieranie danych i nie powinien niczego modyfikować w procesie.

unsigned Date::get_day() const
{
    return day;
}

unsigned Date::get_month() const
{
    return month;
}

int Date::get_year() const
{
    return year;
}

//Settery

void Date::set_day(unsigned day)
{
    if (day >= 1 && day <= 31)
    {
        this -> day = day;
    }
}

void Date::set_month(unsigned month)
{
    if (month >= 1 && month <= 12)
    {
        this -> month = month;
    }
}

void Date::set_year(int year)
{
    this -> year = year;
}

//Operator wypisania

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.day << "." << date.month << "." << date.year;
    return os;
}