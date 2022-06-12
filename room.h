
#ifndef CPP_PROJECT_ROOM_H
#define CPP_PROJECT_ROOM_H
#include <iostream>
#include <vector>
#include <map>
#include "date.h"
#include "room_interface.cpp"

class Room : public Room_Interface
{
protected:
    char type;
    double area;
    double price;
    bool high_standard;
    bool family;
    int number;
    double base_price;
    double base_area;
    std::pair<double, double> maintain_costs_function;
    std::vector<Date> reserved_days;

public:
    Room(int number, bool high_standard, bool family);
    std::vector<Date> get_reserved_days();
    virtual void add_reserved_day(Date);
    virtual void remove_reserved_day(Date);
    virtual int quantity_of_reserved_days(Date first_date, Date second_date);
    virtual char get_type();
    virtual double get_area();
    virtual int get_price();
    virtual bool is_family();
    virtual bool is_high_standard();
    virtual int get_number();
    virtual std::pair<double,double> get_maintain_costs_function();
    virtual int get_number_of_beds()=0;
    virtual void set_parameters(double price_multiplier_high, double area_multiplier_high,
                        double price_multiplier_low, double area_multiplier_low);
    virtual bool is_reserved_at_day(Date);
    virtual bool is_reserved_in_period(std::pair<Date,Date>);
    virtual ~Room() {;}

    //

    bool operator==(const Room& second_room)
    {
        return(number == second_room.number);
    }

    friend std::ostream& operator<<(std::ostream& os, Room&);
};

class OnePersonRoom : public Room
{
public:
    OnePersonRoom(int number, bool high_standard);
    virtual int get_number_of_beds();
};

class TwoPersonRoom : public Room
{
public:
    TwoPersonRoom(int number, bool high_standard, bool family);
    virtual int get_number_of_beds();
};

class ThreePersonRoom : public Room
{
public:
    ThreePersonRoom(int number, bool high_standard, bool family);
    virtual int get_number_of_beds();
};

class FourPersonRoom : public Room
{
public:
    FourPersonRoom(int number, bool high_standard, bool family);
    virtual int get_number_of_beds();

};

class Studio : public Room
{
public:
    Studio(int number);
    virtual int get_number_of_beds();
};

class Apartment : public Room
{
public:
    Apartment(int number);
    virtual int get_number_of_beds();
};

#endif
