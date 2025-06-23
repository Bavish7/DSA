#include<iostream>
using namespace std;

// LARGEST NUMBER (LEETCODE 179)
// USING STRING AND CUSTOM SORT - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Convert each integer in the input vector to a string.
// 2. Define a custom comparator to sort strings such that the concatenation of two strings results in the larger number.
// 3. Sort the vector of strings using the custom comparator.
// 4. If the largest number is '0', return "0" to handle the edge case where all numbers are zeros.
// 5. Concatenate all sorted strings to form the final answer and return it.

static bool comp(string a, string b)
{
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2;
}
string largestNumber(vector<int> &nums)
{
    vector<string> snums;
    for (auto n : nums)
    {
        snums.push_back(to_string(n));
    }
    sort(snums.begin(), snums.end(), comp);
    if (snums[0] == "0")
    {
        return "0";
    }
    string ans = "";
    for (auto str : snums)
    {
        ans += str;
    }
    return ans;
}