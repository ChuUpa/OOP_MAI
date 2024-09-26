#include <iostream>
#include <string>
#include <function.h>

int main() {
    int a;
    std::cout << "enter a number: ";
    std::cin >> a;

    std::string result = translator(a);

    std::cout << "answer: " << result << std::endl;

    return 0;
}