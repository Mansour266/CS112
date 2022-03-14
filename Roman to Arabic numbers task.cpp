// FCAI - Programming 1 - 2022 - Assignment 2
// Program Name: Roman Encryption
// Program description: This program should take input roman Symbols capital letter and convert them to numbers
// Last modification date: 13/3/2022
// Created by Adham Mansour(20210057) Group A

#include <iostream>
#include <string>

using namespace std;

int main(){
    string roman_num;
    int arabic_number {0}; // this should be the converted number at the end
    cin >> roman_num;
    while (true){
        if(roman_num[0] == 'M'){
            arabic_number += 1000;
            roman_num.erase(0,1);
            continue;
        }
        else if(roman_num[0] == 'D'){
            if(roman_num[1] == 'M'){ //this should check if the roman number after it is bigger so subtract its value
                arabic_number -= 500; // for example: IV = 5 - 1. we subtract the value instead of adding it.
            }
            else {
                arabic_number += 500;
            }
            roman_num.erase(0, 1);
        }
        else if(roman_num[0] == 'C'){
            if(roman_num[1] == 'M' || roman_num[1] == 'D'){
                arabic_number -= 100;
            }
            else{
           arabic_number += 100;
            }
            roman_num.erase(0,1);
        }
        else if(roman_num[0] == 'L'){
            if(roman_num[1] == 'M' || roman_num[1] == 'D' || roman_num[1] == 'C'){
                arabic_number -= 50;
            }
            else {
                arabic_number += 50;
            }
            roman_num.erase(0,1);
        }
        else if(roman_num[0] == 'X'){
            if(roman_num[1] == 'M' || roman_num[1] == 'D' || roman_num[1] == 'C' || roman_num[1] == 'L'){
                arabic_number -= 10;
            }
            else {
                arabic_number += 10;
            }
            roman_num.erase(0,1);
        }
        else if(roman_num[0] == 'V'){
            if(roman_num[1] == 'M' || roman_num[1] == 'D' || roman_num[1] == 'C' || roman_num[1] == 'L' || roman_num[1] == 'X'){
                arabic_number -= 5;
            }
            else {
                arabic_number += 5;
            }
            roman_num.erase(0,1);
        }
        else if(roman_num[0] == 'I'){
            if(roman_num[1] == 'M' || roman_num[1] == 'D' || roman_num[1] == 'C' || roman_num[1] == 'L' || roman_num[1] == 'X' || roman_num[1] == 'V'){
                arabic_number -= 1;
            }
            else {
                arabic_number += 1;
            }
            roman_num.erase(0,1);
        }
        else if(roman_num.empty()){ //this should check if all the roman symbols are converted to quit the while loop.
            break;
        }
    }
    cout << arabic_number;
}
