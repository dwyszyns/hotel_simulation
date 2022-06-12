#ifndef CPP_PROJECT_DATA_H
#define CPP_PROJECT_DATA_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <vector>
#include "employee.h"
#include "barman.h"
#include "bodyguard.h"
#include "cook.h"
#include "maid.h"
#include "manager.h"
#include "recepcionist.h"
#include "waiter.h"

class Data_employee
{
    std::vector<std::unique_ptr<Employee_Interface>> database;

    public:
    bool add_employee(std::string, std::string, std::string, std::string, std::string, double);
    bool remove_employee(std::string, std::string, std::string, std::string, std::string, double);
    std::unique_ptr<Employee_Interface> make_employee_pointer(std::string, std::string, std::string, std::string, std::string, double);

    int get_size();
    int get_number_of_workers_with_type(std::string type);
    double working_hours(std::string);
    double salary(std::string);
    bool print_employee(std::string);
    bool edit_employee(std::string, std::string, std::string, std::string);
    void print_rates();
    void set_employee_rate(std::string, double);
    bool employee_roster(std::string);
    bool make_employee_roster(std::string, std::vector<std::pair<Date, int>>);
    void clear();
    std::vector<std::unique_ptr<Employee_Interface>>::iterator begin();
    std::vector<std::unique_ptr<Employee_Interface>>::iterator end();
    std::unique_ptr<Employee_Interface>& operator[](int);

    std::string print_employees();
};

#endif
