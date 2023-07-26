///////////////////////////////////////////////////////////////////
// Student Name: Dayo Lawal
// Course: COSC 3503 - Operating Systems
// Assignment: #1 - Using a Command Shell
// Source Code File Name: Lawal1
// Program's Purpose: Find the square value of the base number and two numbers after
// Program's Limitations: None known
// Development Computer: Dayo's PC
// Operating System: Windows 10
// Compiler: Gnu g++
// Program's Operational Status: Fully Operational 
/////////////////////////////////////////////////////////////////// 

#include <iostream>
#include <iomanip> 
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    int value;
    std::cout << "Input a value between 1 and 20." << std::endl;
    std::cin >> value;

    if (value < 1 || value > 20) {
        throw invalid_argument("Value must be between 1 and 20.");
    } else {
        string x = to_string(value);
        string y = to_string(value + 1);
        string z = to_string(value + 2);    
        string x2 = to_string((int) pow(value, 2));
        string y2 = to_string((int) pow((value + 1), 2));
        string z2 = to_string((int) pow((value + 2), 2));

        cout << "BASE SQUARED" << std::endl;
        cout << "-------- ---------------" << std::endl;
        cout << std::setw(3) << x << std::setw(6) << x2 << "\n" << std::setw(3) << y << std::setw(6) << y2 << "\n" << std::setw(3) << z << std::setw(6) << z2 << std::endl;
        return 0;
    }
} // End main