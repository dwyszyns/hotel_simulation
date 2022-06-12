
#include "catch.hpp"
#include "../../room.h"
#include "../../database.h"



TEST_CASE("Getters of Room", "[Room]")
{
    SECTION("One Person Room")
    {

    OnePersonRoom o1(222, false);
    CHECK(o1.get_type() == '1');
    CHECK(o1.get_price() == 105);
    CHECK(o1.get_area() == 45);
    CHECK(o1.get_number() == 222);
    CHECK(o1.is_high_standard() == false);
    CHECK(o1.is_family() == false);
    }
    SECTION("Apartment")
    {
    Apartment a(576);
    CHECK(a.get_type() == 'a');
    CHECK(a.get_price() == 210);
    CHECK(a.get_area() == 75);
    CHECK(a.get_number() == 576);
    CHECK(a.is_high_standard() == true);
    CHECK(a.is_family() == true);
    }

    SECTION("Four Person Room")
    {
    FourPersonRoom f1(255, true, true);
    CHECK(f1.get_type() == '4');
    CHECK(f1.get_price() == 150);
    CHECK(f1.get_area() == 60);
    CHECK(f1.get_number() == 255);
    CHECK(f1.is_high_standard() == true);
    CHECK(f1.is_family() == true);
    }
}

TEST_CASE("Booking the room", "[Room]")
{
    OnePersonRoom o1(222, false);
    o1.add_reserved_day(Date(19, 10, 2020));
    o1.add_reserved_day(Date(19, 10, 2020));
    o1.add_reserved_day(Date(19, 10, 2020));
    o1.add_reserved_day(Date(19, 10, 2020));
    CHECK(o1.get_reserved_days().size() == 1);
    o1.add_reserved_day(Date(22,10,2020));
    o1.add_reserved_day(Date(23,10,2020));
    o1.add_reserved_day(Date(24,10,2020));
    CHECK(o1.get_reserved_days().size() == 4);
    o1.remove_reserved_day(Date(15,10,2020));
    CHECK(o1.get_reserved_days().size() == 4);
    o1.remove_reserved_day(Date(22,10,2020));
    CHECK(o1.get_reserved_days().size() == 3);
}

TEST_CASE("Polymorphism", "[Database]")
{

    Data_room database;
    CHECK(database.add_room('s',325));
    CHECK(database.add_room('1',125, false));
    CHECK(database.add_room('2',225, true, true));

    CHECK(database.add_room('3',125, true, true) == false);

    CHECK(database.remove_room(125));
    CHECK(database.remove_room(225));
    CHECK(database.remove_room(125) == false);

    CHECK(database.is_room_free(325, std::make_pair<Date,Date>(Date(15,10,2020), Date(22,10,2020))));
    database.book_room(325, std::make_pair<Date,Date>(Date(15,10,2020), Date(22,10,2020)));
    CHECK(database.is_room_free(325, std::make_pair<Date,Date>(Date(15,10,2020), Date(22,10,2020))) == false);

}

