#include<iostream>
using namespace std;

// SINGLE NUMBER II (LEETCODE 137)
// USING BIT MANIPULATION - TC=O(N), SC=O(1)

// Steps:
// 1. Loop through each bit position `k` (0 to 31).
// 2. `temp = (1 << k)` → create mask for bit position `k`.
// 3. Count how many numbers in `nums` have this bit set.
// 4. If `countOnes % 3 == 1`, it means the single number has this bit set
//    (others appear in triplets, so their bits cancel out mod 3).
// 5. Set that bit in `ans` using bitwise OR.
// 6. Return `ans` as the unique number appearing once.

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int k = 0; k <= 31; k++)
    {
        int temp = (1 << k);
        int countOnes = 0;
        for (int &num : nums)
        {
            if (num & temp)
                countOnes++;
        }
        if (countOnes % 3 == 1)
            ans = (ans | temp);
    }
    return ans;
}