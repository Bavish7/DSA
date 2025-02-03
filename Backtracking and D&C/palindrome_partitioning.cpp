#include<iostream>
using namespace std;

// PALINDROME PARTITIONING (LEETCODE 131)
// USING RECURSION AND BACKTRACKING - TC=O(N*2^N), SC=O(N)

// Steps:
// 1. Use a recursive function `partitionHelper` to find all possible partitions of the string.
//    - Base Case: If the index reaches the end of the string, add the current partition to the result.
//    - For each substring starting from the current index, check if it is a palindrome.
//    - If palindrome, add the substring to the current partition and recursively call `partitionHelper` for the next index.
//    - Backtrack by removing the substring after recursion.
// 2. Call the `partitionHelper` function with the initial index as 0.
// 3. Return the list of all possible partitions.

void partitionHelper(int index, string s, vector<string> &path, vector<vector<string>> &res)
{
    if (index == s.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = index; i < s.size(); ++i)
    {
        if (isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            partitionHelper(i + 1, s, path, res);
            path.pop_back();
        }
    }
}
bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> path;
    partitionHelper(0, s, path, res);
    return res;
}