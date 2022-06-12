#ifndef CPP_PROJECT_SIMULATION_H
#define CPP_PROJECT_SIMULATION_H
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "hotel.h"

class Simulation
{
    int days;
    std::string room_file_name;
    std::string employee_file_name;
    std::string simulation_file;
    std::string menu_file_name;
    std::string guest_file_name;
    Date start_date;
    Date current_date;
    Hotel hotel = Hotel("",0,10000);
    std::vector<Guest> guests_to_add;
    std::vector<Guest> current_guests;
    std::vector<std::string> activity = {"book_room", "change_stay", "choose_entertainment", "CHANGE", "book_room", "change_stay", "choose_entertainment"};
    std::vector<std::string> entertainment = {"order_taxi", "order_dish", "order_tidying_room", "order_waking_up"};

    public:
    Simulation(int, Date, std::string, std::string, std::string, std::string, std::string);

    std::vector<Guest> get_guests_to_add();
    std::vector<Guest> get_current_guests();
    std::string get_file_name();

    void start();
    int change_relay(int);
    void load_rooms();
    void load_employees();
    void load_menu();
    void load_guests();
    void set_hotel();
    void print_tidying_room(Guest, std::string);

    void clear_simulation_file();
    void write_to_file(std::string);

    int drawing_the_booking_room(int);
    void drawing_the_choosing_entertainment();
    void drawing_the_changing_stay();

    double take_receipts();

    void end(double, double, int);

    void print_current_employees();
    void print_wrong_activity(std::string);
    void print_checking_in(std::string, std::string, int);
    void print_adding_employee(std::string, std::string, bool);
    void print_removing_employee(std::string, std::string, bool);
    void print_choosing_entertainment(std::string, std::string, std::string, int, std::string);
    void print_removing_dish(std::string, bool);
    void print_adding_dish(std::string, bool);
    void print_monthly_action(int, double, double);
    void print_changing_stay(std::string, Date, bool);
};

#endif
