#ifndef CPP_PROJECT_DISH_H
#define CPP_PROJECT_DISH_H
#include <iostream>
#include <vector>
#include <functional>
#include "ingredient.h"


class Dish
{
    std::string name;
    double price, preparation_cost, preparation_time;
    int mass;
    std::vector<std::string> allergens;
    std::vector<Ingredient> ingredients;

    public:
    Dish(std::string name="foo", double price=0, double preparation_cost=0, double preparation_time=0, std::vector<Ingredient> ingredients = {}, std::vector<std::string> allergens = {});

    void set_name(std::string name);
    void set_price(double price);
    void set_preparation_cost(double preparation_cost);
    void set_preparation_time(double preparation_time);

    std::string get_name();
    double get_price();
    int get_mass();
    double get_preparation_cost();
    double get_preparation_time();
    void update_mass();
    std::vector<std::string> get_allergens();

    bool does_dish_contain_the_ingredient(Ingredient i);
    bool has_dish_the_allergen(std::string allergen);
    void add_ingredient(Ingredient i);
    void remove_ingredient(Ingredient i);
    void add_allergen(std::string al);
    void remove_allergen(std::string al);

    void sort_allergens_by_alphabet();
    void sort_ingredients_by_name();
    void sort_ingredients_by_quantity();
    int number_of_allergens();
    int number_of_ingredients();
    int number_of_ingredients_bigger_than(int mass);

    bool operator<(const Dish& second_dish) const;
    bool operator<=(const Dish& second_dish) const;
    bool operator>(const Dish& second_dish) const;
    bool operator>=(const Dish& second_dish) const;
    Dish& operator++();
    Dish operator++(int);
    Dish& operator--();
    Dish operator--(int);

    bool operator==(Dish& second_dish);

    friend std::ostream& operator<<(std::ostream& os, Dish& d);
};

#endif
