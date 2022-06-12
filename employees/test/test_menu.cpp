#include <iostream>
#include "catch.hpp"
#include "../../dish.h"

TEST_CASE("Getters, setters and operands of ingredient", "[Ingredient]")
{
    Ingredient i("Egg", 16);

    CHECK(i.get_name() == "Egg");

    CHECK(i.get_quantity() == 16);

    i.set_name("Potato");
    
    i.set_quantity(25);
    
    CHECK(i.get_name() == "Potato");
    
    CHECK(i.get_quantity() == 25);

    i++;
    
    CHECK(i.get_quantity() == 35);
    
    i--;
    
    CHECK(i.get_quantity() == 25);
    
    i += 30;
    
    CHECK(i.get_quantity() == 55);
    
    i -= 40;
    
    CHECK(i.get_quantity() == 15);
    
    i--;
    
    i--;
    
    i -= 50;
    
    CHECK(i.get_quantity() == 0);

    i.set_quantity(25);

    ++i;

    CHECK(i.get_quantity() == 35);

    --i;

    CHECK(i.get_quantity() == 25);
}

TEST_CASE("Wrong cases of ingredient", "[Ingredient]")
{
    Ingredient i("Egg", 16);
    
    CHECK_THROWS_AS(i.set_quantity(-3), std::out_of_range);
    
    CHECK_THROWS_AS(Ingredient("Fake", -8), std::out_of_range);
}

TEST_CASE("Getters, setters and operand of Dish", "[Dish]")
{
    Ingredient i1("Egg", 100);
    
    Ingredient i2("Salt", 10);
    
    Ingredient i3("Bacon", 50);
    
    Ingredient i4("Onion", 25);

    Dish d1("Scrambled eggs", 9.80, 15, 20, {i1, i2, i3}, {"eggs"});
    
    CHECK(d1.get_name() == "Scrambled eggs");
    
    CHECK(d1.get_price() == 9.80);
    
    CHECK(d1.get_preparation_time() == 20);
    
    CHECK(d1.get_mass() == 160);
    
    CHECK(d1.number_of_ingredients_bigger_than(60) == 1);

    CHECK(d1.does_dish_contain_the_ingredient(i1) == true);
    
    CHECK(d1.does_dish_contain_the_ingredient(i2) == true);

    CHECK(d1.does_dish_contain_the_ingredient(i3) == true);

    CHECK(d1.does_dish_contain_the_ingredient(i4) == false);

    CHECK(d1.has_dish_the_allergen("eggs") == true);

    CHECK(d1.has_dish_the_allergen("milk") == false);

    CHECK(d1.number_of_ingredients_bigger_than(30) == 2);

    d1.add_ingredient(i4);

    d1.remove_ingredient(i3);

    CHECK(d1.does_dish_contain_the_ingredient(i3) == false);

    CHECK(d1.does_dish_contain_the_ingredient(i4) == true);

    CHECK(d1.get_mass() == 135);

    CHECK(d1.number_of_ingredients() == 3);

    CHECK(d1.number_of_allergens() == 1);

    d1.add_allergen("milk");

    d1.add_allergen("cacao");

    d1.remove_allergen("eggs");

    CHECK(d1.number_of_allergens() == 2);

    d1.add_allergen("random");

    d1.sort_allergens_by_alphabet();

    std::vector<std::string> expected_sorted_allergens = {"cacao", "milk", "random"};

    CHECK(d1.get_allergens() == expected_sorted_allergens);

    CHECK(d1.has_dish_the_allergen("eggs") == false);

    CHECK(d1.has_dish_the_allergen("cacao") == true);

    d1.set_name("Chocolate cake");

    d1.set_price(6.99);

    d1.set_preparation_time(45);

    CHECK(d1.get_name() == "Chocolate cake");

    CHECK(d1.get_price() == 6.99);

    CHECK(d1.get_preparation_time() == 45);

    Dish d2("Boiled onion", 9.80, 10, 5, {i2, i4});

    CHECK(d1 > d2);

    CHECK(d1 >= d2);

    CHECK(d2 <= d1);

    CHECK(d2 < d1);
}
