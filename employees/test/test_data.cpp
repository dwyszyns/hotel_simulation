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
#include "../data.h"
#include "catch.hpp"

TEST_CASE("class data simple tests", "[data]") 
{
    Date date(15, 10, 2021);

    Data_employee data;

    std::unique_ptr<Employee_Interface> maid_ptr = std::make_unique<Maid>("Ola", "Nowa", "wp@wp.pl", "02302019023", 19.7);

    std::unique_ptr<Employee_Interface> maid_ptr1 = std::make_unique<Maid>("Magda", "Kosar", "op@wp.pl", "08302000645", 20);

    std::unique_ptr<Employee_Interface> maid_ptr2 = std::make_unique<Maid>("Maciej", "Wnuk", "up@wp.pl", "92309019006", 19.8);

    SECTION("checking unique ptr") 
    {
        CHECK(maid_ptr -> get_first_name() == "Ola");

        CHECK(maid_ptr -> get_last_name() == "Nowa");

        CHECK(maid_ptr -> get_email_adress() == "wp@wp.pl");

        CHECK(maid_ptr -> get_PESEL() == "02302019023");

        CHECK(maid_ptr -> get_Hourly_rate() == 19.7);
    }

    data.add_employee("maid", "Ola", "Nowa", "wp@wp.pl", "02302019023", 19.7);

    data.add_employee("maid", "Magda", "Kosar", "op@wp.pl", "08302000645", 20);

    data.add_employee("maid", "Maciej", "Wnuk", "up@wp.pl", "92309019006", 19.8);

    SECTION("removing and adding employees") 
    {
        CHECK(data.get_size() == 3);

        data.remove_employee("maid", "Ola", "Nowa", "wp@wp.pl", "02302019023", 19.7);

        CHECK(data.get_size() == 2);

        data.add_employee("waiter", "Magda", "Wnuk", "up@wp.pl", "93319019006", 19.8);

        CHECK(data.get_size() == 3);
    }

    SECTION("making employees' roster and checking employees' virtual methods")
    {
        Date date(15,11,2020);

        std::vector<std::pair<Date, int>> changes;

        for(int i=0; i<30; i++)
        {
            changes.push_back(std::make_pair<Date, int>(date+i,1));

            changes.push_back(std::make_pair<Date, int>(date+i,2));

            changes.push_back(std::make_pair<Date, int>(date+i,3));
        }
        data.make_employee_roster("02302019023", changes);

        data.make_employee_roster("92309019006", changes);

        data.make_employee_roster("08302000645", changes);

        CHECK(data.working_hours("02302019023") == 252);
        
        CHECK(data.working_hours("08302000645") == 252);
    }

    SECTION("checking method clear")
    {
        CHECK(data.get_size() == 3);
        
        data.clear();
        
        CHECK(data.get_size() == 0);
    }

    SECTION("checking edit employees")
    {
        data.edit_employee("02302019023", "Kasia", "Mieka", "kasiulka@wp.pl");
        
        CHECK(data.remove_employee("maid", "Kasia", "Mieka", "kasiulka@wp.pl", "02302019023", 19.7) == true);
    }

    SECTION("checking printing employee")
    {
        CHECK(data.print_employee("02020200202") == false);
    }
}