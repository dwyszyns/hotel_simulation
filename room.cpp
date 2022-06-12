#include "room.h"
#include <algorithm>

double Room::get_area()
{
    return area;
}

int Room::get_price()
{
    return price;
}

int Room::get_number()
{
    return number;
}

char Room::get_type()
{
    return type;
}

std::vector<Date> Room::get_reserved_days()
{
    return reserved_days;
}

Room::Room(int number, bool high_standard, bool family)
{
    this->number = number;
    this->high_standard = high_standard;
    this->family = family;
    base_price = 150;
    base_area = 50;
}

std::pair<double,double> Room::get_maintain_costs_function()
{
    return maintain_costs_function;
}

void Room::set_parameters(double price_multiplier_low, double area_multiplier_low,
                          double price_multiplier_high, double area_multiplier_high)
{
    if(high_standard)
    {
        price = price_multiplier_high * base_price;
        area = area_multiplier_high * base_area;
    }
    else
    {
        price = price_multiplier_low * base_price;
        area = area_multiplier_low * base_area;
    }
}

int Room::quantity_of_reserved_days(Date first_date, Date second_date)
{
    return std::count_if(reserved_days.begin(), reserved_days.end(), [&](Date d){return(first_date <= d && d <= second_date);});
}

OnePersonRoom::OnePersonRoom(int number, bool high_standard) : Room(number, high_standard, false)
{
    type = '1';
    maintain_costs_function = std::make_pair(1, 10);
    Room::set_parameters(0.7, 0.9, 0.85, 1.1);
}

TwoPersonRoom::TwoPersonRoom(int number, bool high_standard, bool family) : Room(number, high_standard, family)
{
    type = '2';
    maintain_costs_function = std::make_pair(1, 15);
    Room::set_parameters(0.9, 1.2, 0.9, 1.15);
}

ThreePersonRoom::ThreePersonRoom(int number, bool high_standard, bool family) : Room(number, high_standard, family)
{
    type = '3';
    maintain_costs_function = std::make_pair(2, 15);
    Room::set_parameters(1, 1.2, 0.95, 1.2);
}

FourPersonRoom::FourPersonRoom(int number, bool high_standard, bool family) : Room(number, high_standard, family)
{
    type = '4';
    maintain_costs_function = std::make_pair(3, 15);
    Room::set_parameters(1.3, 1.5, 1, 1.2);
}

Studio::Studio(int number) : Room(number, false, false)
{
    type = 's';
    maintain_costs_function = std::make_pair(4, 20);
    Room::set_parameters(1.5, 1.8, 0, 0);
}

Apartment::Apartment(int number) : Room(number, true, true)
{
    type = 'a';
    maintain_costs_function = std::make_pair(5, 25);
    Room::set_parameters(2, 2, 1.4, 1.5);
}

bool Room::is_reserved_at_day(Date date)
{
    return(std::count(reserved_days.begin(), reserved_days.end(), date));
}

bool Room::is_reserved_in_period(std::pair<Date,Date> period)
{
    for(Date iter=period.first; iter<=period.second; iter++)
    {
        if(is_reserved_at_day(iter)) return true;
    }
    return false;
}

bool Room::is_high_standard()
{
    return high_standard;
}

bool Room::is_family()
{
    return family;
}

void Room::add_reserved_day(Date d)
{
    if(is_reserved_at_day(d)) return;
    reserved_days.push_back(d);
}

void Room::remove_reserved_day(Date d)
{
    if(!(is_reserved_at_day(d))) return;
    reserved_days.erase(std::find(reserved_days.begin(), reserved_days.end(), d));
}


int OnePersonRoom::get_number_of_beds()
{
    return 1;
}



int TwoPersonRoom::get_number_of_beds()
{
    if(family) return 1;
    else return 2;
}



int ThreePersonRoom::get_number_of_beds()
{
    if(family) return 2;
    else return 3;
}



int FourPersonRoom::get_number_of_beds()
{
    if(family) return 3;
    else return 4;
}



int Studio::get_number_of_beds()
{
    return 4;
}



int Apartment::get_number_of_beds()
{
    return 1;
}

