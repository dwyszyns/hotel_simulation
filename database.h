#include <iostream>
#include <vector>
#include <memory>
#include "room.h"
#include <cstdlib>
#pragma once

class Data_room
{
    std::vector<int> numbers_of_rooms;
    std::vector<std::unique_ptr<Room_Interface>> rooms;
public:
    std::vector<std::unique_ptr<Room_Interface>> get_rooms();
    std::vector<int> get_rooms_numbers();
    bool add_room(char type, int number, bool family=false, bool high_standard=false);
    bool remove_room(int number);
    bool book_room(int room_number, std::pair<Date, Date>);
    bool is_room_free(int room_number, std::pair<Date, Date>);
    std::vector<std::unique_ptr<Room_Interface>>::iterator begin();
    std::vector<std::unique_ptr<Room_Interface>>::iterator end();
};
