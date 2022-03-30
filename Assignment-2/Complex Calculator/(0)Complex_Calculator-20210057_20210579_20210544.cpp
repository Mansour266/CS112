//FCAI – Programming 1 – 2022 - Assignment 2
//Program Name:Complex Number Calculator
/*
Program Description:This program should take the real and imaginary parts of the two numbers along with the operand and make operations on them and print the result in format (a+bi)
*/
//Last Modification Date: 23/03/2022
//Author1 and ID and Group:Adham Wael Mansour-20210057-Group A
//Author2 and ID and Group:Yousif Mostafa mohamed (20210544)
//Author3 and ID and Group:Mohamed Essam El-Deen (20210579)

#include <iostream>
#include <string>
#include <complex>

int main() {
    double first_real, first_imag, second_real, second_image;//this should define each part of the numbers
    std::string operation;

    std::cout << "Please enter the number in order first-real first-imaginary operation second-real second-imaginary\n";
    std::cout << "For example: 1 2 * 2 4.\n";
    std::cout << "equation: ";

    std::cin >> first_real >> first_imag >> operation >> second_real >> second_image;
    std::complex<double> first_complete(first_real, first_imag), second_complete(second_real, second_image);
    //now we will deal with operations
    if (operation == "+") {
        std::complex<double> result{ first_complete + second_complete };
        std::cout << "(" << result.real() << ", " << result.imag() << "i)" << "\n";
    }
    else if (operation == "-") {
        std::complex<double> result{ first_complete - second_complete };
        std::cout << "(" << result.real() << ", " << result.imag() << "i)" << "\n";
    }
    else if (operation == "*") {
        std::complex<double> result{ first_complete * second_complete };
        std::cout << "(" << result.real() << ", " << result.imag() << "i)" << "\n";
    }
    else if (operation == "/") {
        std::complex<double> result{ first_complete / second_complete };
        std::cout << "(" << result.real() << ", " << result.imag() << "i)" << "\n";
    }
}
