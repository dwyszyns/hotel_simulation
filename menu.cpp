#include <iostream>
#include <string>
#include <vector>
#include "menu.h"

Menu::Menu(std::string name1="", std::vector<Dish> food1 = {}, std::vector<Dish> drinks1 = {})
{
    name = name1;
    food = food1;
    drinks = drinks1;
}

std::string Menu::get_name(){
    return name;
}

std::vector<Dish> Menu::get_food()
{
    return food;
}

std::vector<Dish> Menu::get_drinks()
{
    return drinks;
}

std::vector<Dish> Menu::get_dishes() {
    std::vector<Dish> dishes;
    for(unsigned int i = 0; i < food.size(); i++)
        dishes.push_back(food[i]);

    for(unsigned int i = 0; i < drinks.size(); i++)
        dishes.push_back(drinks[i]);

    return dishes;
}

void Menu::set_name(std::string new_name){
    name = new_name;
}

bool Menu::add_food(Dish new_food){
    for(unsigned int i = 0; i < food.size(); i++)
        if (new_food.get_name() == food[i].get_name())
            return false;
    food.push_back(new_food);
    return true;
}

bool Menu::add_drink(Dish new_drink){
    for(unsigned int i = 0; i < drinks.size(); i++)
        if (new_drink.get_name() == drinks[i].get_name())
            return false;
    drinks.push_back(new_drink);
    return true;
}

bool Menu::remove_food(std::string name){
    for(unsigned int i = 0; i < food.size(); i++)
        if (name == food[i].get_name())
        {
            food.erase(food.begin() + i);
            return true;
        }
    return false;
}

bool Menu::remove_drink(std::string name){
    for(unsigned int i = 0; i < drinks.size(); i++)
        if (name == drinks[i].get_name())
        {
            drinks.erase(drinks.begin() + i);
            return true;
        }
    return false;
}

void Menu::change_food_price(std::string name, double new_price, double preparation_cost){
    for(unsigned int i = 0; i < food.size(); i++)
        if (name == food[i].get_name())
        {
            food[i].set_price(new_price);
            food[i].set_preparation_cost(preparation_cost);
            break;
        }
}

void Menu::change_drink_price(std::string name, double new_price, double preparation_cost){
    for(unsigned int i = 0; i < drinks.size(); i++)
        if (name == drinks[i].get_name())
        {
            drinks[i].set_price(new_price);
            drinks[i].set_preparation_cost(preparation_cost);
            break;
        }
}

int Menu::count_food(){
    return food.size();
}

int Menu::count_drinks(){
    return drinks.size();
}


double Menu::find_price(std::string name){
    for(unsigned int i = 0; i < food.size(); i++)
        if (name == food[i].get_name())
            return food[i].get_price();

    for(unsigned int i = 0; i < drinks.size(); i++)
        if (name == drinks[i].get_name())
            return drinks[i].get_price();
    return -1;
}

double Menu::find_preparation_cost(std::string name){
    for(unsigned int i = 0; i < food.size(); i++)
        if (name == food[i].get_name())
            return food[i].get_preparation_cost();

    for(unsigned int i = 0; i < drinks.size(); i++)
        if (name == drinks[i].get_name())
            return drinks[i].get_preparation_cost();
    return 0;
}

double Menu::find_preparation_time(std::string name){
     for(unsigned int i = 0; i < food.size(); i++)
        if (name == food[i].get_name())
            return food[i].get_preparation_time();

    for(unsigned int i = 0; i < drinks.size(); i++)
        if (name == drinks[i].get_name())
            return drinks[i].get_preparation_time();
    return 0;
}
