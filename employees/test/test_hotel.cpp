#include <iostream>
#include <string>
#include <vector>
#include "../../hotel.h"
#include "catch.hpp"

TEST_CASE("class hotel simple tests", "[hotel]") 
{
    Hotel hotel("Motel", 4, 3000000);

    SECTION("checking getters") 
    {
        CHECK(hotel.get_name() == "Motel");
        
        CHECK(hotel.get_stars() == 4);
        
        CHECK(hotel.get_budget() == 3000000);
    }

    SECTION("checking current date")
    {
        Date date(1,1,1);
        
        Date new_date(2,2,2002);
        
        CHECK(hotel.get_current_date() == date);
        
        hotel.set_date(new_date);
        
        CHECK(hotel.get_current_date() == new_date);
        
        hotel.increment_current_date();
        
        CHECK(hotel.get_current_date() == new_date + 1);
    }

    SECTION("checking employees' database")
    {
        CHECK(hotel.add_employee("waiter", "Eryk", "Gol", "eg@wp.pl", "98071800001", 41) == true);
        
        CHECK(hotel.add_employee("maid", "Magda", "Gol", "maa@wp.pl", "980718001", 241) == false);
        
        CHECK(hotel.add_employee("waiter", "Eryk", "Gol", "eg@wp.pl", "98071800001", 41) == false);
    }

    SECTION("checking employees' database")
    {
        CHECK(hotel.get_number_of_employees() == 0);
        
        hotel.add_employee("maid", "Magda", "Mada", "eg@wp.pl", "98071800001", 41);
        
        hotel.add_employee("waiter", "Eryk", "Gol", "eg@wp.pl", "88071800001", 41);
        
        CHECK(hotel.get_number_of_employees() == 2);
    }

    SECTION("checking budget modification")
    {
        CHECK(hotel.get_budget() == 3000000);
        
        hotel.increase_budget(200);
        
        CHECK(hotel.get_budget() == 3000200);
        
        hotel.decrease_budget(100);
        
        CHECK(hotel.get_budget() == 3000100);
    }

    SECTION("checking more methods")
    {
        hotel.add_employee("maid", "Magda", "Mada", "eg@wp.pl", "98071800001", 41);
        
        hotel.add_employee("waiter", "Eryk", "Gol", "eg@wp.pl", "88071800001", 41);
        
        CHECK(int(hotel.handing_out_salary()) == 9284);
        
        CHECK(hotel.paying_the_bills() == 0);
    }
}