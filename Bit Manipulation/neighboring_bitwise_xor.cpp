#include<iostream>
using namespace std;

// NEIGHBORING BITWISE XOR (LEETCODE 2683)
// USING BIT MANIPULATION - TC=O(N), SC=O(N)

// Steps:
// 1. We are given derived[], where:
//    derived[i] = original[i] ^ original[(i+1)%n].
// 2. Task → check if there exists an original[] that satisfies above relation.
// 3. Approach:
//    - Assume original[0] = 0, construct array sequentially.
//    - Verify if last condition (original[n-1] ^ original[0] == derived[n-1]) holds.
//    - If yes → valid array exists.
//    - Otherwise, repeat with original[0] = 1 (second possible case).
// 4. If either assumption is valid → return true, else false.

bool doesValidArrayExist(vector<int> &derived)
{
    int n = derived.size();
    vector<int> original(n);
    original[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        original[i + 1] = original[i] ^ derived[i];
    }
    if ((original[n - 1] ^ original[0]) == derived[n - 1])
    {
        return true;
    }
    original[0] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        original[i + 1] = original[i] ^ derived[i];
    }
    if ((original[n - 1] ^ original[0]) == derived[n - 1])
    {
        return true;
    }
    return false;
}

// USING BIT MANIPULATION - TC=O(N), SC=O(1)
// Steps:
// 1. From condition: derived[i] = original[i] ^ original[(i+1)%n].
// 2. If we XOR all derived[i] together:
//    totalXor = (original[0]^original[1]) ^ (original[1]^original[2]) ^ ... ^ (original[n-1]^original[0])
// 3. Every element original[i] appears **exactly twice** → cancels out to 0.
//    Hence totalXor must equal 0 for a valid original[] to exist.
// 4. So just check if XOR of all elements in derived[] is 0.

bool doesValidArrayExist(vector<int> &derived)
{
    int totalXor = 0;
    for (int i = 0; i < derived.size(); i++)
    {
        totalXor ^= derived[i];
    }
    return !totalXor;
}