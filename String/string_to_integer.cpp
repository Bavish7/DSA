#include<iostream>
using namespace std;

// STRING TO INTEGER (LEETCODE 8)
// USING STRING - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize variables num to store the result, sign to handle the sign, and i as the index pointer.
// 2. Skip leading whitespaces.
// 3. Check for optional sign and update the sign variable accordingly.
// 4. Iterate through the digits and construct the integer while handling overflow/underflow conditions.
// 5. Return the final result after applying the sign.

int myAtoi(string s)
{
    int num = 0, sign = 1, i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    if (i < s.size() && (s[i] == '-' || s[i] == '+'))
    {
        sign = s[i] == '+' ? 1 : -1;
        i++;
    }
    while (i < s.size() && isdigit(s[i]))
    {
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7'))
        {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return num * sign;
}