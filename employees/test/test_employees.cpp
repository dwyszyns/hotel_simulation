#include <iostream>
#include <string>
#include <vector>
#include "../employee.h"
#include "../barman.h"
#include "../bodyguard.h"
#include "../cook.h"
#include "../maid.h"
#include "../manager.h"
#include "../recepcionist.h"
#include "../waiter.h"
#include "catch.hpp"

TEST_CASE("class recepcionist simple tests", "[recepcionist]") 
{
    Recepcionist recep("Kasia", "Mak", "kas@wp.pl", "02301699863", 19.7);

    SECTION("checking getters") 
    {
        CHECK(recep.get_first_name() == "Kasia");
        
        CHECK(recep.get_last_name() == "Mak");
        
        CHECK(recep.get_email_adress() == "kas@wp.pl");
        
        CHECK(recep.get_PESEL() == "02301699863");
        
        CHECK(recep.get_Hourly_rate() == 19.7);
    }

    SECTION("checking setters") 
    {
        recep.set_name("Ola", "Kosa");
        
        CHECK(recep.get_first_name() == "Ola");
        
        CHECK(recep.get_last_name() == "Kosa");
        
        recep.set_email_adress("ola@wp.pl");
        
        CHECK(recep.get_email_adress() == "ola@wp.pl");
        
        recep.set_PESEL("03300303333");
        
        CHECK(recep.get_PESEL() == "03300303333");
    }

    SECTION("comparing employees")
    {
        Recepcionist second_recep("Kasia", "Mak", "kas@wp.pl", "02301699863", 19.7);
        
        CHECK((second_recep == recep) == true);
    }

}

TEST_CASE("class maid simple tests", "[maid]") 
{
    Maid maid("Magda", "Was", "wk@wp.pl", "98071800000", 20);

    SECTION("checking getters and setters - hourly rate") 
    {
        CHECK(maid.get_Hourly_rate() == 20);
        
        maid.set_Hourly_rate(30);
        
        CHECK(maid.get_Hourly_rate() == 30);
    }

    SECTION("checking virtual methods") 
    {
        Date date(15,11,2020);
        
        std::vector<std::pair<Date, int>> changes;
        
        for(int i=0; i<30; i++)
        {
            changes.push_back(std::make_pair<Date, int>(date+i,1));
        
            changes.push_back(std::make_pair<Date, int>(date+i,2));
        
            changes.push_back(std::make_pair<Date, int>(date+i,3));
        }
        
        maid.make_roster(changes);
        
        CHECK(maid.working_hours() == 252);
    }
}

TEST_CASE("class manager simple tests", "[manager]") 
{
    Manager manager("Eryk", "Gol", "eg@wp.pl", "98071800001", 41);

    SECTION("checking getters and setters - hourly rate") 
    {
        CHECK(manager.get_Hourly_rate() == 41);
        
        manager.set_Hourly_rate(50);
        
        CHECK(manager.get_Hourly_rate() == 50);
    }

    SECTION("checking virtual methods") 
    {
        Date date(15,11,2020);
        
        std::vector<std::pair<Date, int>> changes;
        
        for(int i=0; i<30; i++)
        {
            changes.push_back(std::make_pair<Date, int>(date+i,1));
        
            changes.push_back(std::make_pair<Date, int>(date+i,2));
        
            changes.push_back(std::make_pair<Date, int>(date+i,3));
        }
        
        manager.make_roster(changes);
        
        CHECK(manager.salary() == 7200);
        
        CHECK(manager.working_hours() == 144);
    }
}