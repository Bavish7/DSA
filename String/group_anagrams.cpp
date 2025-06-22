#include<iostream>
using namespace std;

// GROUP ANAGRAMS (LEETCODE 49)
// USING MAP AND SORTING - TC=O(N*KLOGK), SC=O(N*K)

// Steps:
// 1. Create an unordered_map to store sorted words as keys and corresponding anagram groups as values.
// 2. Iterate through each string in the input vector.
// 3. Sort the string to find its canonical form and use it as a key in the map.
// 4. Add the original string to the map under the sorted string key.
// 5. Collect all the grouped anagrams from the map into the result vector.
// 6. Return the result vector.

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (auto str : strs)
    {
        string word = str;
        sort(word.begin(), word.end());
        mp[word].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}