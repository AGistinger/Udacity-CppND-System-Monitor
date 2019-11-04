#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>
#include <iostream>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// TODO: Return the system's CPU
Processor& System::Cpu() 
{ 
  return cpu_;
}

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() 
{ 
  vector<int> process_ids = LinuxParser::Pids();
  for(auto &id : process_ids)
  {
   	 processes_.emplace_back(Process(id));
  }
  return processes_; 
}

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() 
{ 
  string kernel = LinuxParser::Kernel();
  return kernel; 
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() 
{ 
  float mem_util = LinuxParser::MemoryUtilization();
  return mem_util; 
}

// TODO: Return the operating system name
std::string System::OperatingSystem() 
{ 
  string opsys = LinuxParser::OperatingSystem();
  return opsys; 
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() 
{ 
  int running_procs = LinuxParser::RunningProcesses();
  return running_procs;
}

// TODO: Return the total number of processes on the system
int System::TotalProcesses() 
{ 
  int processes = LinuxParser::TotalProcesses();
  return processes;
}

// TODO: Return the number of seconds since the system started running
long int System::UpTime() 
{ 
  long int total_uptime {LinuxParser::UpTime()};
  return total_uptime; 
}