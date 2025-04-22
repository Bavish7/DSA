#include<iostream>
using namespace std;

// CHECK IF POSSIBLE TO SURVIVE
// USING GREEDY APPROACH - TC=O(1), SC=O(1)

// Steps:
// 1. If the number of days (d) is 6 or less:
//    - Check if the amount of food available each day (n) is greater than or equal to the required amount (x).
//    - If true, return true (possible to survive), otherwise return false.
// 2. If the number of days (d) is more than 6:
//    - Check if the amount of food available each day (n) is greater than or equal to the required amount (x).
//    - Additionally, check if the total food available for 6 days (6 * n) is greater than or equal to the total food required for 7 days (7 * x).
//    - If both conditions are met, return true (possible to survive), otherwise return false.

bool isPossibleToSurvive(int n, int x, int d)
{
    if (d <= 6)
    {
        if (n >= x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (n >= x && 6 * n >= 7 * x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}