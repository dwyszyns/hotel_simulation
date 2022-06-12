#include <iostream>
#include <string>
#include <vector>
#include "../../date.h"
#include "catch.hpp"

TEST_CASE("class date simple tests", "[date]") 
{
    Date date(15, 10, 2021);

    SECTION("checking getters") 
    {
        CHECK(date.get_day() == 15);
        
        CHECK(date.get_month() == 10);
        
        CHECK(date.get_year() == 2021);
        
        CHECK(date.get_month_length(10) == 31);
        
        CHECK(date.get_month_length(2) == 28);
    }

    SECTION("checking setters") 
    {
        date.set_day(10);
        
        CHECK(date.get_day() == 10);

        date.set_month(2);
        
        CHECK(date.get_month() == 2);

        date.set_year(2022);
        
        CHECK(date.get_year() == 2022);
    }

    SECTION("add or less days to date")
    {
        date++;
        
        CHECK(date.get_day() == 16);
        
        CHECK(date.get_month() == 10);
        
        CHECK(date.get_year() == 2021);

        Date date1(28, 2, 2020);
        
        date1+=2;
        
        CHECK(date1.get_day() == 1);
        
        CHECK(date1.get_month() == 3);
        
        CHECK(date1.get_year() == 2020);
    }

    SECTION("comparing dates")
    {
        Date date1(15, 11, 2021);
        
        CHECK((date > date1) == false);
        
        CHECK((date == date1) == false);
        
        CHECK((date <= date1) == true); 
    }
}