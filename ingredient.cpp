#include "ingredient.h"

Ingredient::Ingredient(std::string name, int quantity)
{
    this->set_name(name);
    this->set_quantity(quantity);
}

std::string Ingredient::get_name()
{
    return name;
}

int Ingredient::get_quantity()
{
    return quantity;
}

void Ingredient::set_name(std::string new_name)
{
    this->name = new_name;
}

void Ingredient::set_quantity(int new_quantity)
{
    if(new_quantity >= 0)   this->quantity = new_quantity;
    else throw std::out_of_range("Ingredient's mass cannot be negative");
}

Ingredient& Ingredient::operator++()
{
    quantity += 10;
    return *this;
}

Ingredient Ingredient::operator++(int)
{
    Ingredient old_value = *this;
    ++(*this);
    return old_value;
}

Ingredient& Ingredient::operator--()
{
    if(quantity >= 10)   quantity -= 10;
    else quantity = 0;
    return *this;
}

Ingredient Ingredient::operator--(int)
{
    Ingredient old_value = *this;
    --(*this);
    return old_value;
}

Ingredient& Ingredient::operator+=(int n)
{
    quantity += n;
    return *this;
}

Ingredient& Ingredient::operator-=(int n)
{
    quantity -= n;
    if(quantity < 0) quantity = 0;
    return *this;
}


std::ostream& operator<<(std::ostream& os, const Ingredient& i)
{
    os << i.name << " " << i.quantity << 'g';
    return os;
}
