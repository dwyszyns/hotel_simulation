#ifndef CPP_PROJECT_EMPLOYEE_H
#define CPP_PROJECT_EMPLOYEE_H
#include <iostream>
#include <string>
#include <vector>
#include "employee_interface.cpp"

class Employee : public Employee_Interface
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
    Employee(std::string, std::string, std::string, std::string, double);
    virtual ~Employee();

    double get_worked_hours() const;
    void set_worked_hours(double);
    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_email_adress() const;
    std::string get_PESEL() const;
    std::string get_type() const;
    double get_Hourly_rate() const;
    void set_Hourly_rate(double);
    void print_roster();
    void add_relay_to_roster(std::pair<Date,int> relay);
    double get_hourly_rate(std::string) const;
    int get_working_days(std::string) const;
    int get_working_hours(std::string) const;
    void set_name(std::string, std::string);
    void set_email_adress(std::string);
    void set_PESEL(std::string);
    virtual void set_hourly_rate();
    virtual double working_hours();
    virtual double salary();
    virtual void tidy_room() {;}
    virtual void make_roster(std::vector<std::pair<Date, int>>)=0;
    void start_day();
    void take_vacation(Date);
    void remove_vacation(Date);
    bool works_in_a_change(Date, int);
    auto begin();
    auto end();

    bool operator==(const Employee& second_employee)
    {
        return(PESEL == second_employee.PESEL);
    }
};
#endif
