#include "processor.h"

#include <fstream>
#include <string>

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() 
{ 
  std::string key;
  float user, nice, system, idle, wait, irq, softirq, steal, guest, guest_nice;
  
  std::ifstream in_file("/proc/stat");
  if(in_file.is_open())
  {
   	in_file >> key >> user >> nice >> system >> idle >> wait >> irq >> softirq >> steal >> guest >> guest_nice; 
  }
  in_file.close();
  
  float total_cpu = user + nice + system + idle + wait + irq + softirq + steal + guest + guest_nice;
  float idle_cpu = idle + wait;
  float cpu_usage = total_cpu - idle_cpu;
  
  return (cpu_usage/total_cpu); 
}