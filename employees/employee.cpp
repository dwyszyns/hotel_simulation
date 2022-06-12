
#include <iostream>
#include "employee.h"
#include "../date.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

Employee::Employee(std::string first_name1, std::string last_name1, std::string email_adress1, std::string PESEL1, double hourly_rate1)
{
    first_name = first_name1;
    last_name = last_name1;
    email_adress = email_adress1;
    x = 0;
    if (PESEL1.size() == 11)
        PESEL = PESEL1;
    else
        throw std::range_error("PESEL do not have 11 digits");

    if (hourly_rate1 > 0)
        hourly_rate = hourly_rate1;
    else
        throw std::range_error("Hourly rate has to be positive");
}

void Employee::set_worked_hours(double new_hours){
    x = new_hours;
}

Employee::~Employee() {}

double Employee::get_worked_hours() const{
    return x;
}

void Employee::start_day(){
    set_worked_hours(0);
}

void Employee::add_relay_to_roster(std::pair<Date,int> relay)
{
    roster.push_back(relay);
}

double Employee::get_Hourly_rate() const{
    return hourly_rate;
}

std::string Employee::get_first_name() const{
    return first_name;
}

std::string Employee::get_last_name() const{
    return last_name;
}

std::string Employee::get_email_adress() const{
    return email_adress;
}

std::string Employee::get_PESEL() const{
    return PESEL;
}

std::string Employee::get_type() const {
    return type;
}

double Employee::working_hours()
{
    return get_working_days(type)*get_working_hours(type);
}

double Employee::salary()
{
    return get_hourly_rate(type)*working_hours();
}

void Employee::set_hourly_rate() {
    hourly_rate = get_hourly_rate(type);
}

void Employee::set_Hourly_rate(double new_rate){
    if (new_rate > 0)
        hourly_rate = new_rate;
}

double Employee::get_hourly_rate(std::string employee_name) const{
    std::ifstream outfile;
    outfile.open("working_plan.txt");
    if (!outfile) {
        throw std::logic_error("Couldn't open the file!");
    }
    std::string first_line;
    getline (outfile,first_line);
    std::string employee;
    double Hourly_rate;
    int working_days, working_hours;
    for (int i = 1; i <= 7; i ++)
    {
        outfile >> employee >> Hourly_rate >> working_days >> working_hours;
        if (employee == employee_name)
        {
            outfile.close();
            return Hourly_rate;
        }
    }
    outfile.close();
    return 0;
}

int Employee::get_working_days(std::string employee_name) const{
    std::ifstream outfile;
    outfile.open("working_plan.txt");
    if (!outfile) {
        throw std::logic_error("Couldn't open the file!");
    }
    std::string first_line;
    getline (outfile,first_line);
    std::string employee;
    double Hourly_rate;
    int working_days, working_hours;
    for (int i = 1; i <= 7; i ++)
    {
        outfile >> employee >> Hourly_rate >> working_days >> working_hours;
        if (employee == employee_name)
        {
            outfile.close();
            return working_days;
        }
    }
    outfile.close();
    return 0;
}

int Employee::get_working_hours(std::string employee_name) const{
    std::ifstream outfile;
    outfile.open("working_plan.txt");
    if (!outfile) {
        throw std::logic_error("Couldn't open the file!");
    }
    std::string first_line;
    getline (outfile,first_line);
    std::string employee;
    double Hourly_rate;
    int working_days, working_hours;
    for (int i = 1; i <= 7; i ++)
    {
        outfile >> employee >> Hourly_rate >> working_days >> working_hours;
        if (employee == employee_name)
        {
            outfile.close();
            return working_hours;
        }
    }
    outfile.close();
    return 0;
}

void Employee::set_name(std::string new_first_name, std::string new_last_name) {
    first_name = new_first_name;
    last_name = new_last_name;
}

void Employee::set_email_adress(std::string new_email_adress) {
    email_adress = new_email_adress;
}

void Employee::set_PESEL(std::string new_PESEL) {
    if (new_PESEL.size() == 11)
        PESEL = new_PESEL;
    else
        throw std::range_error("PESEL musi miec 11 cyfr");
}

void Employee::print_roster() {
    std::cout << "Roster for month: date and part of day \n";
    for(long unsigned int i = 0; i < roster.size(); i++){
        roster[i].first.get_day();
        std::cout << " " << roster[i].second << std::endl;
    }
}

void Employee::take_vacation(Date new_date){
    for(unsigned int i = 0; i < free_days.size(); i++)
        if (new_date == free_days[i].first)
            return;
    std::pair<Date, int> new_free_day = std::make_pair(Date(1,1,1),1);
    new_free_day.first = new_date;
    if (get_working_days(get_type()) > (30 - free_days.size()))
        for (int i = 1; i <= 3; i++){
            new_free_day.second = i;
            free_days.push_back(new_free_day);
        }
}

void Employee::remove_vacation(Date date){
        std::pair<Date, int> free_day = std::make_pair(Date(1,1,1),1);
    free_day.first = date;
    for(unsigned int j = 0; j < free_days.size(); j++)
    {
        if (free_days[j].first == date)
        {
            free_days.erase(free_days.begin() + j);
        }
    }
}

bool Employee::works_in_a_change(Date date, int change)
{
    return std::count_if(roster.begin(), roster.end(), [&](std::pair<Date,int> p){return p.first==date && p.second==change;});
}


