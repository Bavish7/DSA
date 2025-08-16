#include<iostream>
using namespace std;

// SINGLE NUMBER III (LEETCODE 260)
// USING BIT MANIPULATION - TC=O(N), SC=O(1)

// Steps:
// 1. XOR all numbers → result = totalXor = a ^ b (since other numbers appear twice).
// 2. Find rightmost set bit in totalXor using (totalXor & -totalXor).
//    → This bit distinguishes a and b (they differ at this position).
// 3. Partition numbers into two groups based on this bit:
//    - Group A: Numbers with that bit set.
//    - Group B: Numbers with that bit unset.
// 4. XOR within each group → one unique number per group (a and b).
// 5. Return the two unique numbers.

vector<int> singleNumber(vector<int> &nums)
{
    long long totalXor = 0;
    for (int &num : nums)
    {
        totalXor ^= num;
    }
    int mask = totalXor & (-totalXor);
    int groupA = 0, groupB = 0;
    for (int &num : nums)
    {
        if (num & mask)
        {
            groupA ^= num;
        }
        else
        {
            groupB ^= num;
        }
    }
    return {groupA, groupB};
}