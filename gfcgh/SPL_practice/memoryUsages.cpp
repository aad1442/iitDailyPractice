#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

// Function to parse memory information from /proc/meminfo
void parse_memory_info(long& total_memory, long& free_memory, long& total_swap, long& free_swap) {
    std::ifstream meminfo("/proc/meminfo");

    if (!meminfo) {
        std::cerr << "Failed to open /proc/meminfo" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(meminfo, line)) {
        std::istringstream iss(line);
        std::string key;
        long value;

        if (iss >> key >> value) {
            if (key == "MemTotal:") {
                total_memory = value;
            } else if (key == "MemFree:") {
                free_memory = value;
            } else if (key == "SwapTotal:") {
                total_swap = value;
            } else if (key == "SwapFree:") {
                free_swap = value;
            }
        }
    }

    meminfo.close();
}

// Function to log memory usage to a file
void log_memory_usage() {
    const std::string filename = "memeroUsages.txt"; // Change the filename
    
    long total_memory, free_memory, total_swap, free_swap;

    parse_memory_info(total_memory, free_memory, total_swap, free_swap);

    std::ofstream logfile(filename, std::ios::app); // Open the file in append mode
    if (logfile) {
        std::time_t current_time = std::time(nullptr);
        logfile << "Timestamp: " << std::asctime(std::localtime(&current_time));
        logfile << "Total Memory: " << total_memory << " kB" << std::endl;
        logfile << "Free Memory: " << free_memory << " kB" << std::endl;
        logfile << "Total Swap: " << total_swap << " kB" << std::endl;
        logfile << "Free Swap: " << free_swap << " kB" << std::endl << std::endl;
        logfile.close();
        std::cout << "Memory usage logged to " << filename << std::endl;
    } else {
        std::cerr << "Failed to open the log file for writing" << std::endl;
    }
}

int main() {
    // Call the function to log memory usage
    log_memory_usage();

    return 0;
}

