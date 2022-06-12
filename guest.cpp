
#include <iostream>
#include "guest.h"
#include "menu.h"
#include <algorithm>
#include <vector>
#include <string>

Guest::Guest(std::string first_name_1, std::string last_name_1, std::string email_1, std::string pesel_1, double money_1)
{
    first_name = first_name_1;
    last_name = last_name_1;
    email_adress = email_1;
    PESEL = pesel_1;
    money = money_1;
}

std::string Guest::get_first_name(){
    return first_name;
}

std::string Guest::get_last_name(){
    return last_name;
}

std::string Guest::get_email_adress(){
    return email_adress;
}

std::string Guest::get_PESEL(){
    return PESEL;
}

double Guest::get_money(){
    return money;
}

double Guest::get_receipt(){
    return receipt;
}

int Guest::get_stay_length()
{
    return stay_length;
}

int Guest::get_room_number(){
    return room_number;
}

void Guest::set_first_date(Date date)
{
    first_day = date;
}

void Guest::set_last_date(Date date)
{
    last_day = date;
}

void Guest::set_name(std::string new_first_name, std::string new_last_name){
    first_name = new_first_name;
    last_name = new_last_name;
}

void Guest::set_email_adress(std::string new_email){
    email_adress = new_email;
}

void Guest::set_PESEL(std::string new_pesel){
    PESEL = new_pesel;
}

void Guest::set_money(double new_money){
    money = new_money;
}

void Guest::set_receipt(double new_receipt){
    receipt = new_receipt;
}

void Guest::set_room_number(int new_number){
    room_number = new_number;
}

void Guest::set_stay_length(int length)
{
    stay_length = length;
}

bool Guest::order_taxi(){
    int price = 100;
    if ((price+receipt) > money)
        return false;
    receipt += price;
    return true;
}

void Guest::add_money(double income)
{
    money += income;
}

bool Guest::subtract_money(double outgo)
{
    if(money - outgo < 0) return false;
    money -= outgo;
    return true;
}

bool Guest::order_dish(std::string dish_name, Menu menu){
    int price = menu.find_price(dish_name);
    if ((price+receipt) > money)
        return false;
    receipt += price;
    if (price != -1)
        return true;
    else return false;
}

bool Guest::order_waking_up(int hour){
    int price = 10;
    if ((price+receipt) > money)
        return false;
    receipt += price;
    return true;
}

bool Guest::order_tidying_room(){
    int price = 30;
    if ((price+receipt) > money)
        return false;
    receipt += price;
    return true;
}

Date Guest::get_first_date()
{
    return first_day;
}

Date Guest::get_last_date()
{
    return last_day;
}

bool Guest::book_room(std::unique_ptr<Room> room, Date arrival_date, Date leave_date){
    room_number = room->get_number();
    receipt += room->get_price();
    return true;
}

