#include <string>
#include <sstream>
#include <iomanip>

#include "format.h"


using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) 
{ 
  int time = seconds;
  int hour, min, sec;

  hour = time / 3600;
  time = time % 3600;
  min = time / 60;
  time = time % 60;
  sec = time;
  
  std::stringstream ss;
  
  ss << std::setfill('0') << std::setw(2) << std::to_string(hour) << ":" << std::setfill('0') << std::setw(2) << std::to_string(min)
    << ":" << std::setfill('0') << std::setw(2) << std::to_string(sec);
  
  return ss.str(); 
}