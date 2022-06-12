#include <iostream>
#include "employee.h"
#include "manager.h"
#include <algorithm>
#include <memory>
#include "data.h"
#include <vector>

Manager::Manager(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{type = "manager";}


void Manager::make_roster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    for(auto& parr : new_schedule)
    {
        if(parr.second == 3 || parr.second == 2) new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), parr));
    }
    for(unsigned int i = 0; i < free_days.size(); i++)
        new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), free_days[i]));

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (get_working_days("manager")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}


// void Manager::dismissEmployee(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate, Data data){
//     data.remove_employee(type, first_name, second_name, email_adress, pesel, hourly_rate);
// }

// void Manager::hireEmployee(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate, Data data)
// {
//     data.add_employee(type, first_name, second_name, email_adress, pesel, hourly_rate);
// }

// void Manager::setEmployeeRate(std::string PESEL, double newRate, Data data){
//     data.set_employee_rate(PESEL, newRate);
// }

