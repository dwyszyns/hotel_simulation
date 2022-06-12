#include <iostream>
#include "employee.h"
#include "../menu.h"
#include "../ingredient.h"
#include <algorithm>
#include <vector>
#include "cook.h"

Cook::Cook(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{type = "cook";}


void Cook::make_roster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    for(auto& parr : new_schedule)
    {
        if(parr.second == 3) new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), parr));
    }
    for(unsigned int i = 0; i < free_days.size(); i++){
        new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), free_days[i]));
    }

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (get_working_days("cook")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}


void Cook::add_dish(std::string name, double price, double preparation_cost, double preparation_time, std::vector<Ingredient> ingredients, std::vector<std::string> allergens, Menu menu){
    Dish new_drink(name, price, preparation_cost, preparation_time, ingredients, allergens);
    menu.add_food(new_drink);
}

void Cook::change_dish_price(std::string name, double new_price, double new_preparation_cost, Menu menu){
    menu.change_food_price(name, new_price, new_preparation_cost);
}

void Cook::remove_dish(std::string name, Menu menu){
    menu.remove_drink(name);
}

void Cook::do_dish(std::string name, Menu menu){
    double time = menu.find_preparation_time(name);
    x += time;
}

