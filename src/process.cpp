#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "process.h"
#include "system.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() 
{ 
  return this->pid_; 
}

float Process::To_Float(string &s)
{
  std::istringstream ss {s};
  float data;
  ss >> data;
  return data;
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() 
{ 
  string file_name {"/proc/" + to_string(this->Pid()) + "/stat"};
  string line;
  vector<string> data;

  std::ifstream in_file(file_name);
  if(in_file.is_open())
  {
    while(!in_file.eof())
    {
      in_file >> line;
      data.emplace_back(line);
    }
  }
  in_file.close();
  
  long sys_uptime {LinuxParser::UpTime()};
  float utime {To_Float(data.at(13))};
  float stime {To_Float(data.at(14))};
  float cutime {To_Float(data.at(15))};
  float cstime {To_Float(data.at(16))};
  float start_time {To_Float(data.at(21))};
  long hertz {sysconf(_SC_CLK_TCK)};

  float total_time = utime + stime;
  total_time += cutime + cstime;
  float seconds = sys_uptime - (start_time / hertz);
  float cpu_usage = (total_time / hertz) / seconds;

  return cpu_usage; 
}

// TODO: Return the command that generated this process
string Process::Command() 
{ 
  string command = LinuxParser::Command(this->Pid());
  return command; 
}

// TODO: Return this process's memory utilization
string Process::Ram() 
{ 
  string ram = LinuxParser::Ram(this->Pid());
  return ram; 
}

// TODO: Return the user (name) that generated this process
string Process::User() 
{ 
  string value = LinuxParser::Uid(this->Pid());
  return Find_User(value); 
}

string Process::Find_User(string &s)
{
  string file_name {"/etc/passwd"};
  string user, mid, value, line;

  std::ifstream in_file(file_name);
  if(in_file.is_open())
  {
    while(value != s)
    {
      getline(in_file, user, ':');
      getline(in_file, mid, ':');
      getline(in_file, value, ':');
      getline(in_file, line);
    }
  }
  in_file.close();
  return user;
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() 
{ 
  string file_name {"/proc/" + to_string(this->Pid()) + "/stat"};
  string line;
  vector<string> data;

  std::ifstream in_file(file_name);
  if(in_file.is_open())
  {
    while(!in_file.eof())
    {
      in_file >> line;
      data.emplace_back(line);
    }
  }
  in_file.close();

  float start_time {To_Float(data.at(21))};
  float uptime = start_time / sysconf(_SC_CLK_TCK);

  return uptime; 
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const 
{ 
  if(this->pid_ < a.pid_)
  {
    return true; 
  }
  else
  {
    return false;
  }
}