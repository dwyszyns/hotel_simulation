#include <iostream>
#include "date.h"

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::get_day()
{
    return day;
}
int Date::get_month()
{
    return month;
}
int Date::get_year()
{
    return year;
}

int Date::get_month_length(int month)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        {
            return 31;
            break;
        }
    case 4:
    case 6:
    case 9:
    case 11:
        {
            return 30;
            break;
        }
    case 2:
        {
            if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) return 29;
            else return 28;
            break;
        }
    }
    return 30;
}

void Date::set_day(int new_day)
{
    day = new_day;
}

void Date::set_month(int new_month)
{
    month = new_month;
}

void Date::set_year(int new_year)
{
    year = new_year;
}

bool Date::operator<(const Date& second_date)
{
    if(year < second_date.year) return true;
    else if(year == second_date.year && month < second_date.month) return true;
    else if(year == second_date.year && month == second_date.month && day < second_date.day) return true;
    else return false;
}

bool Date::operator==(const Date& second_date) const
{
    return (year == second_date.year && month == second_date.month && day == second_date.day);
}

bool Date::operator<=(const Date& second_date)
{
    return ((*this) < second_date || (*this) == second_date);
}

bool Date::operator>(const Date& second_date)
{
    return !((*this) <= second_date);
}

bool Date::operator>=(const Date& second_date)
{
    return ((*this) > second_date || (*this) == second_date);
}

Date Date::operator+=(int days)
{
    if(day + days > get_month_length(month))
    {
        day += days;
        do
        {
            int old_month = month;
            if(month == 12) {month = 1; year++;}
            else month++;
            day -= get_month_length(old_month);
        }
        while(day > get_month_length(month));
    }
    else day += days;
    return *this;
}

Date& Date::operator++()
{
    this->operator+=(1);
    return *this;
}

Date Date::operator++(int)
{
    Date old_date = *this;
    ++(*this);
    return old_date;
}

Date Date::operator+(int days) const
{
    Date new_date = *this;
    new_date += days;
    return new_date;
}

Date Date::operator-=(int days)
{
    if(day - days < 0)
    {
        day -= days;
        do
        {
            int old_month = month;
            if(month == 1) {month = 12; year--;}
            else month--;
            day += get_month_length(month);
        }
        while(day <= 0);
    }
    else day -= days;
    return *this;
}

int Date::operator-(const Date& date)
{
    int i=0;
    if(*this > date)
    {
        while(date + i < *this) i++;
    }
    else
    {
        while(date - i > *this) i++;
    }
    return i;
}

Date Date::operator-(int days) const
{
    Date old_date = *this;
    old_date -= days;
    return old_date;
}

std::string Date::print()
{
    std::string date = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
    return date;
}
