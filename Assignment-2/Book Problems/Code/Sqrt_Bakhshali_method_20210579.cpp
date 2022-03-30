// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Sqrt_Bakhshali_method.cpp
// Program Description: square root using Bakhshali method.
// Last Modification Date: 24/3/2022
// Author: Mohamed Essam El-Din Hassan
// ID: 20210579
// Group: A
#include <iostream>
using namespace std;
// this program calculate the square root with Bakhshali method
float sqroot(float num)
{
    int nearest_perf_sq = 0; //This will be the nearest perfect square to num
    int sqrt_for_neareast_perf_sq = 0; //This is the sqrt of the nearest perfect square

    // Find the nearest perfect square to num
    for (int i = static_cast<int>(num); i > 0; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (j*j == i)
            {
                nearest_perf_sq = i;
                sqrt_for_neareast_perf_sq = j;
                break;
            }
        }
        // print the nearest perfect square
        if (nearest_perf_sq > 0)
            break;
    }

    float d = num - nearest_perf_sq;	 //calculate d
    float P = d/(2.0*sqrt_for_neareast_perf_sq); //calculate P
    float A = sqrt_for_neareast_perf_sq+P;	 //calculate A
    float sqrt_of_num = A-((P*P)/(2.0*A)); //calculate sqrt(num).
    return sqrt_of_num;
}

// now the user will enter a number to get it's sqrt
int main()
{
    float num;
    cout << "Enter a number: ";
    cin >> num;
    float sqroot_of_num ;
    sqroot_of_num = sqroot(num);
    cout << "Square root is: " << sqroot_of_num ;
    return 0;
}
