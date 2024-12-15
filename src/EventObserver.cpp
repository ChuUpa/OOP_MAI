#include "EventObserver.h"
#include <iostream>
#include <fstream>

// Реализация ConsoleLogger
void ConsoleLogger::onEvent(const std::string& event) {
    std::cout << "ConsoleLogger: " << event << std::endl; // Вывод события в консоль
}

// Реализация FileLogger
void FileLogger::onEvent(const std::string& event) {
    std::ofstream logFile("log.txt", std::ios::app); // Открываем файл в режиме добавления
    if (logFile.is_open()) {
        logFile << "FileLogger: " << event << std::endl; // Записываем событие в файл
        logFile.close(); // Закрываем файл
    } else {
        std::cerr << "Error: Could not open log file." << std::endl; // Обработка ошибки
    }
}
