#include<iostream>
using namespace std;

// WORD BREAK II (LEETCODE 140)
// USING RECURSION - TC=O(2^N), SC=O(N*M)

// Steps:
// 1. Base case: If `start` reaches `s.size()`, return a vector with an empty string as a valid result.
// 2. Initialize an empty vector `ans` to store all possible sentences starting from `start`.
// 3. Build `word` character by character from `start` to `s.size()`:
//    - If `word` exists in `dict`, recursively partition the remaining part of the string starting at `i+1`.
//    - For each result returned from the recursion, combine `word` with each valid partition and store it in `ans`.
// 4. Return `ans` to get all sentences that can be formed starting from `start`.

vector<string> solve(string &s, unordered_map<string, bool> &dict, int start)
{
    if (start == s.size())
    {
        return {""};
    }
    vector<string> ans;
    string word;
    for (int i = start; i < s.size(); i++)
    {
        word.push_back(s[i]);
        if (dict.find(word) != dict.end())
        {
            auto right = solve(s, dict, i + 1);
            for (auto eachPart : right)
            {
                string endPart;
                if (eachPart.size() > 0)
                    endPart = " " + eachPart;
                ans.push_back(word + endPart);
            }
        }
    }
    return ans;
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, bool> dict;
    for (auto word : wordDict)
        dict[word] = 1;
    return solve(s, dict, 0);
}

// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N*M)
// Steps:
// 1. Base case: If `start` reaches the size of `s`, return a vector with an empty string to indicate a valid partition end.
// 2. Memoization check: If solutions from `start` are already in `dp`, return them directly to avoid redundant calculations.
// 3. Initialize `ans` to collect all possible sentences starting from `start`.
// 4. Build potential words from `start` to `end` and check if they are valid using `dict`.
//    - If valid, recursively solve the rest of the string starting at `i+1` and combine each result with `word`.
// 5. Memoize the `ans` for the current `start` index in `dp` and return it.

vector<string> solve(string &s, unordered_map<string, bool> &dict, int start, unordered_map<int, vector<string>> &dp)
{
    if (start == s.size())
    {
        return {""};
    }
    if (dp.find(start) != dp.end())
    {
        return dp[start];
    }
    vector<string> ans;
    string word;
    for (int i = start; i < s.size(); i++)
    {
        word.push_back(s[i]);
        if (dict.find(word) != dict.end())
        {
            auto right = solve(s, dict, i + 1, dp);
            for (auto eachPart : right)
            {
                string endPart;
                if (eachPart.size() > 0)
                    endPart = " " + eachPart;
                ans.push_back(word + endPart);
            }
        }
    }
    dp[start] = ans;
    return dp[start];
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, bool> dict;
    for (auto word : wordDict)
        dict[word] = 1;
    unordered_map<int, vector<string>> dp;
    return solve(s, dict, 0, dp);
}