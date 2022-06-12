#include "database.h"
#include <iostream>
#include <algorithm>

bool Data_room::add_room(char type, int number, bool family, bool high_standard)
{
    try{
        for(auto& i : rooms)
        {
            if(i->get_number() == number)
                return false;
        }
        switch(type)
        {
        case '1':
            {
                std::unique_ptr<Room_Interface> room_ptr = std::make_unique<OnePersonRoom>(number, high_standard);
                rooms.push_back(std::move(room_ptr));
                numbers_of_rooms.push_back(number);
                break;
            }
        case '2':
            {
                std::unique_ptr<Room_Interface> room_ptr = std::make_unique<TwoPersonRoom>(number, high_standard, family);
                rooms.push_back(std::move(room_ptr));
                numbers_of_rooms.push_back(number);
                break;
            }
        case '3':
            {
                std::unique_ptr<Room_Interface> room_ptr = std::make_unique<ThreePersonRoom>(number, high_standard, family);
                rooms.push_back(std::move(room_ptr));
                numbers_of_rooms.push_back(number);
                break;
            }
        case '4':
            {
                std::unique_ptr<Room_Interface> room_ptr = std::make_unique<FourPersonRoom>(number, high_standard, family);
                rooms.push_back(std::move(room_ptr));
                numbers_of_rooms.push_back(number);
                break;
            }
        case 's':
            {
                std::unique_ptr<Room_Interface> room_ptr = std::make_unique<Studio>(number);
                rooms.push_back(std::move(room_ptr));
                numbers_of_rooms.push_back(number);
                break;
            }
        case 'a':
            {
                std::unique_ptr<Room_Interface> room_ptr = std::make_unique<Apartment>(number);
                rooms.push_back(std::move(room_ptr));
                numbers_of_rooms.push_back(number);
                break;
            }
        }

        return true;
    }
    catch(...)
    {
        return false;
    }
}

bool Data_room::remove_room(int number)
{
    try
    {
       for(auto& ptr : rooms)
       {
           if(ptr->get_number() == number)
           {
               rooms.erase(std::find(rooms.begin(), rooms.end(), ptr));
               numbers_of_rooms.erase(std::find(numbers_of_rooms.begin(), numbers_of_rooms.end(), number));
               return true;
           }
       }
       return false;
    }
    catch (...)
    {
        return false;
    }
}

std::vector<int> Data_room::get_rooms_numbers()
{
    return numbers_of_rooms;
}

bool Data_room::book_room(int room_number, std::pair<Date, Date> period)
{
    for (auto& ptr : rooms)
    {
        if(ptr->get_number() == room_number)
        {
            if (ptr->is_reserved_in_period(period))
                return false;
            for(Date d=period.first; d<=period.second; d++)
            {
                ptr -> add_reserved_day(d);
            }
            return true;
        }
    }
    return false;
}

bool Data_room::is_room_free(int room_number, std::pair<Date, Date> period)
{
    for(auto& ptr : rooms)
    {
        if(ptr -> get_number() == room_number)
        {
           for(Date d=period.first; d<=period.second; d++)
            {
                if(ptr -> is_reserved_at_day(d)) return false;
            }
        }
    }
    return true;
}

std::vector<std::unique_ptr<Room_Interface>>::iterator Data_room::begin()
{
    return rooms.begin();
}

std::vector<std::unique_ptr<Room_Interface>>::iterator Data_room::end()
{
    return rooms.end();
}
