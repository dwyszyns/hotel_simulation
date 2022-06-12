#include <iostream>
#include <vector>
#include <map>
#include "date.h"

class Room_Interface
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
    virtual void add_reserved_day(Date)=0;
    virtual void remove_reserved_day(Date)=0;
    virtual int quantity_of_reserved_days(Date first_date, Date second_date)=0;
    virtual char get_type()=0;
    virtual double get_area()=0;
    virtual int get_price()=0;
    virtual bool is_family()=0;
    virtual bool is_high_standard()=0;
    virtual int get_number()=0;
    virtual std::pair<double,double> get_maintain_costs_function()=0;
    virtual int get_number_of_beds()=0;
    virtual void set_parameters(double price_multiplier_high, double area_multiplier_high,
                        double price_multiplier_low, double area_multiplier_low)=0;
    virtual bool is_reserved_at_day(Date)=0;
    virtual bool is_reserved_in_period(std::pair<Date,Date>)=0;
    virtual ~Room_Interface() {;}
};
