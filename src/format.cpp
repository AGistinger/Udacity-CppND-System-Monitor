#include <string>

#include "format.h"


using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) 
{ 
    int time = seconds;
    int hour, min;

    hour = time / 3600;
    time = time & 3600;
    min = time / 60;
    time = time % 60;

    string time_seconds = std::to_string(hour) + ":" + std::to_string(min) + ":" + std::to_string(time);
    return time_seconds; 
}