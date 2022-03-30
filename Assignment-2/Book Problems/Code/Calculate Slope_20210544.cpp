// FCAI - Programming 1 - 2022 - Assignment 2
// Program Name: Slope Calculator.cpp
// Program Description: Program for calculating the slope from tow given points.
// Last Modification Date: 03/23/2022
// Author: Yousef Kilany , ID: 20210544 , S25
// T.A.: N/A	
// Purpose: To help reduce the pain of calculating the slope by hand.

#include <iostream>

using namespace std;

void calcSlope();

int main()
{
	string userInput;

	// Main menu
	while (true) {
		cout << "Ahlan ya Habibi, type SLOPE to calculate slope or QUIT to exit.\n";
		cin >> userInput;
		if (userInput == "QUIT") {
			break;
		}
		else if (userInput == "SLOPE") {
			calcSlope();
		}
		else {
			cout << "Unrecognized Input!\n";
		}
	}

	cout << "Thank you for using KILANY Apps";
}


void calcSlope()
{
	double x1, x2, y1, y2, m, c;
	// take input
	cout << "Hello User Habibi! Enter x1, y1, x2, y2. in this order: \n";
	cin >> x1 >> y1 >> x2 >> y2;
	
	m = (y2 - y1) / (x2 - x1); // calculate the slope (m)
	cout << "The slope is " << m << endl;
	c = x1 * m - y1;  // calculate (c); y = mx + c
	cout << "Equation of the line: y = " << m << "x " << (c > 0 ? "+ " : "- ") << abs(c) << endl;
}