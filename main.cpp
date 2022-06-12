#include <iostream>
// #include "hotel.h"
#include "simulation.h"
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

// int main(int argc, char* argv[]) {
//      if(argc != 8)
//      {
//         std::cout << "Improper program agruments";
//         exit(-1);
//      }

//  	std::string date_string = argv[1], day_str, month_str, year_str;
//  	std::stringstream date_stream(date_string);
//  	int day, month, year;
//  	try
//  	{
//  	    if(!getline(date_stream, day_str, '.')) {std::cout << "Improper program agruments"; exit(-1);}
//  	    if(!getline(date_stream, month_str, '.')) {std::cout << "Improper program agruments"; exit(-1);}
//  	    if(!getline(date_stream, year_str, '.')) {std::cout << "Improper program agruments"; exit(-1);}
//  	    day = atoi(day_str.c_str());
//  	    month = atoi(month_str.c_str());
//  	    year = atoi(year_str.c_str());
//  	}
//  	catch (...) {exit(-1);}
//  	Date date(day,month,year);
//  	if(day < 0 || day > date.get_month_length(month) || month < 0 || month > 12 || year < 0) {std::cout << "Improper program agruments"; exit(-1);}
// 	std::stringstream stream;
//  	int days;
//  	stream << argv[2];
//  	stream >> days;
//  	if(days <= 0) {std::cout << "Improper program agruments"; exit(-1);}

//     Simulation play(days, date, argv[3], argv[4], argv[5], argv[6], argv[7]);
// 	play.start();
// }
