
#ifndef CPP_PROJECT_HOTEL_H
#define CPP_PROJECT_HOTEL_H
#include <iostream>
#include <string>
#include <vector>
#include "guest.h"
#include "employees/data.h"
#include "database.h"
#include "menu.h"

class Hotel
{
    std::string name;
    int stars;
    double budget;
    double total_income;
    std::vector <Guest> guests;
    Data_employee employees;
    Data_room rooms;
    Menu menu = Menu("",{},{});
    Date current_date;
    Data_employee current_employees;

    public:
    Hotel(std::string, int, double);

    void set_date(Date);
    void set_name(std::string new_name);
    void set_stars(int new_stars);
    void set_budget(double new_budget);
    std::string get_name();
    int get_stars();
    double get_budget();
    double get_total_income();
    Date get_current_date();
    std::vector<Guest> get_guests();
    std::vector<Dish> get_menu();
    std::string print_current_employees();
    int get_number_of_employees();
    int get_number_of_guests();

    bool add_employee(std::string, std::string, std::string, std::string, std::string, double);
    bool remove_employee(std::string, std::string, std::string, std::string, std::string, double);
    void change_employee_rate(std::string, double);

    void add_room(char type='0', int number=0, bool is_high_standard=true, bool is_family=true);
    void remove_room(int number);
    void change_room_price();

    void change_current_employees(Date, int);
    std::string choose_entertainment(std::string guest_pesel, std::string name, std::string type, int);
    double check_guests();

    bool add_dish(std::string, std::string, double, double, double, std::vector<Ingredient>, std::vector<std::string>);
    bool remove_dish(std::string,std::string);

    void increment_current_date();
    void increase_budget(double income);
    bool decrease_budget(double outgo);
    std::string set_maid_to_tidy_room(int);
    void check_in(Guest& guest);
    int book_room(Guest& guest, char type, bool high_standard, bool family, std::pair<Date, Date> period);
    double check_out(Guest&);
    bool shortening_the_stay(Guest&, Date);
    double handing_out_salary();
    int creating_schedule(Date);
    double paying_the_bills();
};
#endif
