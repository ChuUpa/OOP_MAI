#include "EventObserver.h"
#include <iostream>
#include <fstream>


void ConsoleLogger::onEvent(const std::string& event) {
    std::cout << "ConsoleLogger: " << event << std::endl; 
}


void FileLogger::onEvent(const std::string& event) {
    std::ofstream logFile("log.txt", std::ios::app); 
    if (logFile.is_open()) {
        logFile << "FileLogger: " << event << std::endl; 
        logFile.close(); 
    } else {
        std::cerr << "Error: Could not open log file." << std::endl; 
    }
}
