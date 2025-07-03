#include<iostream>
using namespace std;

// ZIGZAG CONVERSION (LEETCODE 6)
// USING STRING - TC=O(N), SC=O(N)

// Steps:
// 1. Handle the edge case when numRows is 1.
// 2. Initialize variables to keep track of the current character index and row.
// 3. Use a boolean flag to manage direction changes (downwards/upwards).
// 4. Traverse the string and place characters in the appropriate row in a vector of strings.
// 5. Concatenate all rows to form the final answer and return it.

string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    int i = 0, row = 0;
    bool direction = true;
    vector<string> zigzag(numRows);
    while (true)
    {
        if (direction)
        {
            while (row < numRows && i < s.size())
            {
                zigzag[row++].push_back(s[i++]);
            }
            row = numRows - 2;
        }
        else
        {
            while (row >= 0 && i < s.size())
            {
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }
        if (i >= s.size())
        {
            break;
        }
        direction = !direction;
    }
    string ans = "";
    for (int i = 0; i < zigzag.size(); i++)
    {
        ans += zigzag[i];
    }
    return ans;
}