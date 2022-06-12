#ifndef CPP_PROJECT_DATE_H
#define CPP_PROJECT_DATE_H
#include <iostream>
#include <string>
#include <vector>
#pragma once

class Date
{
    public:
    int day, month, year;
    Date(int day=1, int month=1, int year=1);

    std::string print();

    int get_day();
    int get_month();
    int get_year();
    int get_month_length(int);

    void control_inputs();
    void set_day(int);
    void set_month(int);
    void set_year(int);

    bool operator<(const Date&);
    bool operator==(const Date&) const;
    bool operator<=(const Date&);
    bool operator>(const Date&);
    bool operator>=(const Date&);

    Date operator+=(int);
    Date& operator++();
    Date operator++(int);
    Date operator+(int) const;
    Date operator-=(int);
    int operator-(const Date&);
    Date operator-(int)const;

    friend std::ostream& operator<<(std::ostream& os, Date d)
    {
        if(d.day<10) os<<'0'<<d.day;
    else os<<d.day;
    os<<'.';
    if(d.month<10) os<<'0'<<d.month;
    else os<<d.month;
    os<<'.';
    if(d.year<10) os<<'0'<<d.year;
    else os<<d.year;

    return os;
    }

};
#endif
