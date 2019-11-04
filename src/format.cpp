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
  string time_seconds;

  hour = time / 3600;
  time = time & 3600;
  min = time / 60;
  time = time % 60;
  
  if(hour < 10)
  {
    time_seconds = "0" + std::to_string(hour) + ":" + std::to_string(min) + ":" + std::to_string(time);
  }
  else if(min < 10)
  {
    time_seconds = std::to_string(hour) + ":" + "0" + std::to_string(min) + ":" + std::to_string(time);
  }
  else if(time < 10)
  {
    time_seconds = std::to_string(hour) + ":" + std::to_string(min) + ":" + "0" + std::to_string(time);
  }
  else
  {
 	 time_seconds = std::to_string(hour) + ":" + std::to_string(min) + ":" + std::to_string(time);
  }
  
  return time_seconds; 
}