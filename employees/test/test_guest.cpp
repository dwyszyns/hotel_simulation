#include "catch.hpp"
#include "../../guest.h"


TEST_CASE("Getters and setters of Guest", "[Guest]")
{
    Guest g1("Jan", "Kowalski", "jk@onet.pl", "02234566619", 3400);

    CHECK(g1.get_first_name() == "Jan");
    
    CHECK(g1.get_last_name() == "Kowalski");
    
    CHECK(g1.get_email_adress() == "jk@onet.pl");
    
    CHECK(g1.get_PESEL() == "02234566619");
    
    CHECK(g1.get_money() == 3400);

    g1.set_name("Kasia", "Cerekwicka");
    
    g1.get_email_adress() == "berbberb@wp.pl";
    
    g1.get_PESEL() == "22310144517";
    
    g1.add_money(140);
    
    g1.subtract_money(200);

    CHECK(g1.get_first_name() == "Kasia");
    
    CHECK(g1.get_last_name() == "Cerekwicka");
    
    CHECK(g1.get_email_adress() == "jk@onet.pl");
    
    CHECK(g1.get_PESEL() == "02234566619");
    
    CHECK(g1.get_money() == 3340);
}

TEST_CASE("Spending money", "[Guest]")
{
    Guest g1("Jan", "Kowalski", "jk@onet.pl", "02234566619", 3000);
    
    Guest g2("Kasia", "Cerekwicka", "kc@wp.pl", "0223366619", 50);
    
    CHECK(g1.order_taxi());
    
    CHECK(g1.get_receipt() == 100);
    
    CHECK(g2.order_taxi() == false);
    
    CHECK(g2.get_money() == 50);

    g2.add_money(50);
    
    CHECK(g2.order_taxi());
    
    CHECK(g2.order_taxi() == false);

    CHECK(g1.order_waking_up(12));
    
    CHECK(g2.order_waking_up(11) == false);
}
