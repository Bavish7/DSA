#include<iostream>
using namespace std;

// JUMP GAME (LEETCODE 55)
// USING GREEDY APPROACH - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize `maxIndex` to 0 and iterate through the array.
// 2. If `maxIndex` is less than the current index, return `false` (as we cannot reach the current index).
// 3. Update `maxIndex` to the maximum of `maxIndex` and the sum of the current index and the value at that index.
// 4. If `maxIndex` is greater than or equal to the last index, return `true` (as we can reach the last index).
// 5. Return `true` if the last index is reachable; otherwise, return `false`.

bool canJump(vector<int> &nums)
{
    int maxIndex = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (maxIndex < i)
        {
            return false;
        }
        maxIndex = max(maxIndex, i + nums[i]);
        if (maxIndex >= n)
        {
            return true;
        }
    }
    return true;
}

// JUMP CODE II (LEETCODE 45)
// USING GREEDY APPROACH - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize `jumps` (number of jumps), `l` (current range start), and `r` (current range end) to 0.
// 2. While `r` is less than `n-1` (end of the array):
//    - Calculate the farthest index reachable within the current range (`l` to `r`).
//    - Update `l` to `r + 1` (new range start) and `r` to `farthest` (new range end).
//    - Increment the `jumps` counter.
// 3. Return `jumps` once the loop ends (indicating the minimum number of jumps to reach the end).

int jump(vector<int> &nums)
{
    int n = nums.size();
    int jumps = 0, l = 0, r = 0;
    while (r < n - 1)
    {
        int farthest = 0;
        for (int i = l; i <= r; i++)
        {
            farthest = max(i + nums[i], farthest);
        }
        l = r + 1;
        r = farthest;
        jumps++;
    }
    return jumps;
}