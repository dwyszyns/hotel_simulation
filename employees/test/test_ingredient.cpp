#include <iostream>
#include <string>
#include <vector>
#include "../../ingredient.h"
#include "catch.hpp"

TEST_CASE("class ingredient simple tests", "[ingredient]") 
{
    Ingredient apple("Apple", 5);
    
    Ingredient milk("Milk", 200);
    
    Ingredient flour("Flour", 100);
    
    Ingredient sugar("Sugar", 25);

    SECTION("checking getters") 
    {
        CHECK(apple.get_name() == "Apple");
    
        CHECK(apple.get_quantity() == 5);
    
        CHECK(milk.get_name() == "Milk");
    
        CHECK(milk.get_quantity() == 200);
    
        CHECK(flour.get_name() == "Flour");
    
        CHECK(flour.get_quantity() == 100);
    
        CHECK(sugar.get_name() == "Sugar");
    
        CHECK(sugar.get_quantity() == 25);
    }

    SECTION("checking setters") 
    {
        apple.set_name("Pear");
    
        CHECK(apple.get_name() == "Pear");
    
        CHECK(apple.get_quantity() == 5);

        flour.set_name("Water");
    
        flour.set_quantity(300);
    
        CHECK(flour.get_name() == "Water");
    
        CHECK(flour.get_quantity() == 300);
    }

    SECTION("checking throwing message-error")
    {
        Ingredient i("Egg", 16);
    
        CHECK_THROWS_AS(i.set_quantity(-3), std::out_of_range);
    
        CHECK_THROWS_AS(Ingredient("Fake", -8), std::out_of_range);
    
        CHECK_THROWS_AS(flour.set_quantity(-100), std::out_of_range);
    }

    SECTION("checking operators") 
    {
        sugar++;
    
        CHECK(sugar.get_quantity() == 35);

        flour--;
    
        CHECK(flour.get_quantity() == 90);

        apple--;
    
        CHECK(apple.get_quantity() == 0);
    }
}