#include <iostream>
#include <vector>
#include "../date.h"

class Employee_Interface
{
    protected:
    std::string first_name;
    std::string last_name;
    std::string email_adress;
    std::string PESEL;
    std::string type;
    double hourly_rate;
    double x;
    std::vector<std::pair<Date, int>> roster;
    std::vector<std::pair<Date, int>> free_days;


    public:
    virtual double get_worked_hours() const=0;
    virtual void set_worked_hours(double)=0;
    virtual std::string get_first_name() const=0;
    virtual std::string get_last_name() const=0;
    virtual std::string get_email_adress() const=0;
    virtual std::string get_PESEL() const=0;
    virtual std::string get_type() const=0;
    virtual double get_Hourly_rate() const=0;
    virtual void set_Hourly_rate(double)=0;
    virtual void print_roster()=0;
    virtual void add_relay_to_roster(std::pair<Date,int> relay)=0;
    virtual double get_hourly_rate(std::string) const=0;
    virtual int get_working_days(std::string) const=0;
    virtual int get_working_hours(std::string) const=0;
    virtual void set_name(std::string, std::string)=0;
    virtual void set_email_adress(std::string)=0;
    virtual void set_PESEL(std::string)=0;
    virtual void set_hourly_rate()=0;
    virtual double working_hours()=0;
    virtual double salary()=0;
    virtual void tidy_room()=0;
    virtual void make_roster(std::vector<std::pair<Date, int>>)=0;
    virtual void start_day()=0;
    virtual void take_vacation(Date)=0;
    virtual void remove_vacation(Date)=0;
    virtual bool works_in_a_change(Date, int)=0;

    virtual bool operator==(const Employee_Interface& second_employee)
    {
        return(PESEL == second_employee.PESEL);
    }
};
