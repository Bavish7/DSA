#include<iostream>
using namespace std;

// FRUIT INTO BASKETS (LEETCODE 904)
// USING VARIABLE SIZE WINDOW - TC=O(2N), SC=O(N)

// Steps:
// 1. Initialize `l` (left pointer), `r` (right pointer), `mp` (hashmap to count fruits), and `maxFruits` (maximum number of fruits collected).
// 2. Traverse the array with the right pointer `r`:
//    - Add `fruits[r]` to the hashmap and increment its count.
//    - If the hashmap size exceeds 2 (more than two types of fruits), slide the left pointer `l` to reduce the window size:
//        - Decrease the count of `fruits[l]` in the hashmap.
//        - Remove the fruit type from the hashmap if its count becomes 0.
// 3. Update `maxFruits` with the maximum window size (`r - l + 1`) during each step.
// 4. Return `maxFruits` as the result.

int totalFruit(vector<int> &fruits)
{
    unordered_map<int, int> mp;
    int l = 0, r = 0, maxFruits = 0;
    while (r < fruits.size())
    {
        mp[fruits[r]]++;
        while (mp.size() > 2)
        {
            mp[fruits[l]]--;
            if (mp[fruits[l]] == 0)
            {
                mp.erase(fruits[l]);
            }
            l++;
        }
        maxFruits = max(maxFruits, r - l + 1);
        r++;
    }
    return maxFruits;
}

// USING VARIABLE SIZE WINDOW - TC=O(N), SC=O(N)
// Steps:
// 1. Initialize variables: `l` (left pointer), `r` (right pointer), `mp` (hashmap to track fruit types and counts), and `maxFruits` (stores maximum length of valid subarray).
// 2. Traverse the array with the right pointer `r`:
//    - Increment the count of `fruits[r]` in the hashmap.
//    - If the size of the hashmap exceeds 2 (more than two types of fruits in the window):
//        - Reduce the count of `fruits[l]` and increment `l` to shrink the window.
//        - Remove the fruit type from the hashmap if its count becomes 0.
// 3. If the hashmap size is 2 or less, update `maxFruits` with the current window size (`r - l + 1`).
// 4. Return `maxFruits` as the result after traversing the array.

int totalFruit(vector<int> &fruits)
{
    unordered_map<int, int> mp;
    int l = 0, r = 0, maxFruits = 0;
    while (r < fruits.size())
    {
        mp[fruits[r]]++;
        if (mp.size() > 2)
        {
            mp[fruits[l]]--;
            if (mp[fruits[l]] == 0)
            {
                mp.erase(fruits[l]);
            }
            l++;
        }
        if (mp.size() <= 2)
        {
            maxFruits = max(maxFruits, r - l + 1);
        }
        r++;
    }
    return maxFruits;
}
