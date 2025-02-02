#include<iostream>
using namespace std;

// LETTER TILE POSSIBILITIES (LEETCODE 1079)
// USING RECURSION AND BACKTRACKING - TC=O(2^N), SC=O(N)

// Steps:
// 1. Initialize the answer count to 0.
// 2. Iterate over each letter in the frequency array.
// 3. If the letter's frequency is greater than 0, decrement its frequency and make a recursive call to continue generating combinations.
// 4. Add the number of combinations found from the recursive call to the answer count.
// 5. Restore the letter's frequency and continue to the next letter.
// 6. Return the total number of combinations found.

int solve(vector<int> &freq)
{
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            ans++;
            freq[i]--;
            int recursionAns = solve(freq);
            ans += recursionAns;
            freq[i]++;
        }
    }
    return ans;
}
int numTilePossibilities(string tiles)
{
    vector<int> freq(26, 0);
    for (auto ch : tiles)
    {
        freq[ch - 'A']++;
    }
    int ans = solve(freq);
    return ans;
}