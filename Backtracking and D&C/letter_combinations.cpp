#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LETTER COMBINATIONS OF A PHONE NUMBER (LEETCODE 17)
// USING RECURSION AND BACKTRACKING - TC=O(4^N), SC=O(N)

// Steps:
// 1. If the current index is equal to the length of the digits string, add the current combination (output) to the result vector.
// 2. Get the corresponding string of letters for the current digit using the mapping array.
// 3. Iterate through each letter in the mapped string, append it to the output, and recursively call the function for the next digit.
// 4. Remove the last appended letter (backtracking) to try other combinations.

void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }
    int number = digits[index] - '0';
    string value = mapping[number];
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, output, index + 1, ans, mapping);
        output.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
    {
        return ans;
    }
    string output;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, index, ans, mapping);
    return ans;
}
int main()
{
    string digits;
    cin >> digits;
    vector<string> ans;
    ans = letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}