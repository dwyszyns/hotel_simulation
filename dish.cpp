#include <algorithm>
#include "dish.h"

#include <iostream>


Dish::Dish(std::string name, double price, double preparation_cost, double preparation_time, std::vector<Ingredient> ingredients, std::vector<std::string> allergens)
{
    this->set_name(name);
    this->set_price(price);
    this->set_preparation_cost(preparation_cost);
    this->set_preparation_time(preparation_time);
    mass = 0;
    this->ingredients = ingredients;
    this->allergens = allergens;
    for(Ingredient i : ingredients)
    {
        mass += i.get_quantity();
    }

}

void Dish::set_name(std::string name)
{
    this->name = name;
}

void Dish::set_price(double price)
{
    if(price < 0) throw std::out_of_range("Price cannot be negative");
    else this->price = price;
}

void Dish::set_preparation_cost(double preparation_cost)
{
    if(preparation_cost < 0) throw std::out_of_range("Preparation cost must be positive");
    else this->preparation_cost = preparation_cost;
}

void Dish::set_preparation_time(double preparation_time)
{
    if(preparation_time < 0) throw std::out_of_range("Preparation time must be positive");
    else this->preparation_time = preparation_time;
}

std::string Dish::get_name()
{
    return name;
}

double Dish::get_price()
{
    return price;
}

int Dish::get_mass()
{
    this->update_mass();
    return mass;
}

void Dish::update_mass()
{
    mass = 0;
    for(Ingredient i : ingredients)
    {
        mass += i.get_quantity();
    }
}

double Dish::get_preparation_cost()
{
    return preparation_cost;
}

double Dish::get_preparation_time()
{
    return preparation_time;
}

std::vector<std::string> Dish::get_allergens()
{
    return allergens;
}

//operators
bool Dish::does_dish_contain_the_ingredient(Ingredient i)
{
    if(std::find(ingredients.begin(), ingredients.end(), i) != ingredients.end()) return true;
    else return false;
}

bool Dish::has_dish_the_allergen(std::string allergen)
{
    if(std::find(allergens.begin(), allergens.end(), allergen) != allergens.end()) return true;
    else return false;
}

void Dish::add_ingredient(Ingredient i)
{
    if(this->does_dish_contain_the_ingredient(i))
        throw std::invalid_argument("Ingredient already in set of ingredients");
    ingredients.push_back(i);
    mass += i.get_quantity();

}

void Dish::remove_ingredient(Ingredient i)
{
    if(!(this->does_dish_contain_the_ingredient(i))) throw std::invalid_argument("Cannot remove non-existing ingredient");
    ingredients.erase(std::find(ingredients.begin(), ingredients.end(), i));
    mass -= i.get_quantity();
}

void Dish::add_allergen(std::string al)
{
    if(this->has_dish_the_allergen(al)) throw std::out_of_range("Allergen already in set of allergens");
    allergens.push_back(al);
}

void Dish::remove_allergen(std::string al)
{
    if(!(this->has_dish_the_allergen(al))) throw std::invalid_argument("Cannot remove non-existing allergen");
    allergens.erase(std::find(allergens.begin(), allergens.end(), al));
}

void Dish::sort_allergens_by_alphabet()
{
    std::sort(allergens.begin(), allergens.end());
}

bool names_comparator(Ingredient i1, Ingredient i2)
{
    return (i1.get_name() < i2.get_name());
}

bool quantity_comparator(Ingredient i1, Ingredient i2)
{
    return (i1.get_quantity() < i2.get_quantity());
}

void Dish::sort_ingredients_by_name()
{
    std::sort(ingredients.begin(), ingredients.end(), names_comparator);
}

void Dish::sort_ingredients_by_quantity()
{
    std::sort(ingredients.begin(), ingredients.end(), quantity_comparator);
}

int Dish::number_of_allergens()
{
    return allergens.size();
}

int Dish::number_of_ingredients()
{
    return ingredients.size();
}

int Dish::number_of_ingredients_bigger_than(int mass)
{
    std::vector<int> masses;
    for(Ingredient i : ingredients)
    {
        masses.push_back(i.get_quantity());
    }

    int counter = std::count_if(masses.begin(), masses.end(), [&](int i){return i > mass;});
    return counter;
}

bool Dish::operator <(const Dish& second_dish) const
{
    if(mass < second_dish.mass) return true;
    else return false;
}

bool Dish::operator <=(const Dish& second_dish) const
{
    if(mass <= second_dish.mass) return true;
    else return false;
}

bool Dish::operator >(const Dish& second_dish) const
{
    if(mass > second_dish.mass) return true;
    else return false;
}

bool Dish::operator >=(const Dish& second_dish) const
{
    if(mass >= second_dish.mass) return true;
    else return false;
}

Dish& Dish::operator++()
{
    for(Ingredient i : ingredients)
    {
        i.set_quantity(i.get_quantity() + 10);
    }
    return *this;
}

Dish Dish::operator++(int)
{
    Dish old_value = *this;
    ++(*this);
    return old_value;
}

Dish& Dish::operator--()
{
    for(Ingredient i : ingredients)
    {
        if(i.get_quantity() - 10 < 0) this->remove_ingredient(i);
        else i.set_quantity(i.get_quantity() - 10);
    }
    return *this;
}

Dish Dish::operator--(int)
{
    Dish old_value = *this;
    --(*this);
    return old_value;
}

bool Dish::operator==(Dish& second_dish)
{
    if(this->mass == second_dish.get_mass() &&
       this->name == second_dish.get_name() &&
       this->price == second_dish.get_price())  return true;
    else return false;
}
