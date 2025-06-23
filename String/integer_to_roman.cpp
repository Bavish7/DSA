#include<iostream>
using namespace std;

// INTEGER TO ROMAN (LEETCODE 12)
// USING MAPPING APPROACH - TC=O(1), SC=O(1)

// Steps:
// 1. Define arrays for Roman symbols and their corresponding values.
// 2. Initialize an empty string ans to store the result.
// 3. Iterate through the values array and append the corresponding Roman symbol to ans while decrementing num accordingly.
// 4. Return the final Roman numeral string.

string intToRoman(int num)
{
    string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans = "";
    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            ans += romanSymbols[i];
            num -= values[i];
        }
    }
    return ans;
}