#include "function.h"
#include <string>
#include <iomanip>
// #include <sstream>


std::string translator(int a){
    int b, c;
    const char* units[] = {
        "sıfır", "bir", "iki", "üç", "dört", "beş", "altı", "yedi", "sekiz", "dokuz"
    };
    const char* tens[] = {
        "on", "yirmi", "otuz", "kırk", "elli", "altmış", "yetmiş", "seksen", "doksan"
    };
    // if (a < 0) || (a >= 100) || (){
    //     std::cout << "incorrect data" << std::endl;
    //     return 0;
    // }
    b = a / 10;
    c = a % 10;
    if (b == 0) {
        return units[c];
    }
    else {
        // std::cout << tens[b - 1] << " " << units[c] << std::endl;
        std::ostringstream result;
        result << tens[b - 1] << " " << units[c] << std::endl;

        return result.str();
    }

}
