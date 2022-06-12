#ifndef CPP_PROJECT_INGREDIENT_H
#define CPP_PROJECT_INGREDIENT_H
#include <iostream>

class Ingredient
{
    std::string name;
    int quantity;

public:
    std::string get_name();
    int get_quantity();

    void set_name(std::string new_name);
    void set_quantity(int new_quantity);

    Ingredient(std::string name="fizzbuzz", int quantity=0);
    Ingredient& operator++();
    Ingredient operator++(int);
    Ingredient& operator--();
    Ingredient operator--(int);
    Ingredient& operator+=(int n);
    Ingredient& operator-=(int n);
    bool operator ==(const Ingredient i) const
    {
        if(name == i.name && quantity == i.quantity) return true;
        else return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Ingredient& i);
};

#endif