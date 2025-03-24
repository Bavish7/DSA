#include<iostream>
using namespace std;

// MINIMUM NUMBER OF K CONSECUTIVE BIT FLIPS (LEETCODE 995)
// USING FIXED SIZE SLIDING WINDOW AND EXTRA ARRAY - TC=O(N), SC=O(N)

// Steps:
// 1. Use a boolean array `isFlipped` to track indices where flips were applied.
// 2. Maintain `pastFlips` to count active flips affecting the current index.
// 3. If `i >= k` and `isFlipped[i - k]` is true, decrement `pastFlips` as its effect ends.
// 4. If `nums[i]` needs flipping (`pastFlips % 2 == nums[i]`):
//    - If flipping exceeds array bounds, return `-1`.
//    - Increment `flips` and `pastFlips`.
//    - Mark `isFlipped[i] = true` to track the flip at index `i`.
// 5. Return total `flips` after processing all elements.

int minKBitFlips(vector<int> &nums, int k)
{
    int n = nums.size();
    int flips = 0;
    vector<bool> isFlipped(n, false);
    int pastFlips = 0;
    for (int i = 0; i < n; i++)
    {
        if (i >= k && isFlipped[i - k] == true)
        {
            pastFlips--;
        }
        if (pastFlips % 2 == nums[i])
        {
            if (i + k > n)
                return -1;
            flips++;
            pastFlips++;
            isFlipped[i] = true;
        }
    }
    return flips;
}

// USING FIXED SIZE SLIDING WINDOW AND IN-PLACE MODIFICATION - TC=O(N), SC=O(1)
// Steps:
// 1. Use `pastFlips` to track the number of flips affecting the current index.
// 2. If `i >= k` and `nums[i - k] == -1`, decrement `pastFlips` since its effect ends.
// 3. If `nums[i]` needs flipping (`pastFlips % 2 == nums[i]`):
//    - If flipping exceeds array bounds, return `-1`.
//    - Increment `flips` and `pastFlips`.
//    - Mark `nums[i]` as `-1` to track active flips.
// 4. Return total `flips` after processing all elements.

int minKBitFlips(vector<int> &nums, int k)
{
    int n = nums.size();
    int flips = 0;
    int pastFlips = 0;
    for (int i = 0; i < n; i++)
    {
        if (i >= k && nums[i - k] == -1)
        {
            pastFlips--;
        }
        if (pastFlips % 2 == nums[i])
        {
            if (i + k > n)
                return -1;
            flips++;
            pastFlips++;
            nums[i] = -1;
        }
    }
    return flips;
}

// USING FIXED SIZE SLIDING WINDOW AND DEQUE - TC=O(N), SC=O(K)
// Steps:
// 1. Use a deque `flipQ` to track flips affecting each index.
// 2. Maintain `pastFlips` to count active flips at index `i`.
// 3. If `i >= k`, remove the effect of the oldest flip (front of `flipQ`).
// 4. If `nums[i]` is incorrect (`pastFlips % 2 == nums[i]`), flip the next `k` elements:
//    - If flipping exceeds array bounds, return `-1`.
//    - Increment `flips` and `pastFlips`, and mark the flip in `flipQ`.
// 5. If no flip is needed, push `0` into `flipQ` to maintain size consistency.
// 6. Return `flips` after processing all elements.

int minKBitFlips(vector<int> &nums, int k)
{
    int n = nums.size();
    int flips = 0;
    int pastFlips = 0;
    deque<int> flipQ;
    for (int i = 0; i < n; i++)
    {
        if (i >= k)
        {
            pastFlips -= flipQ.front();
            flipQ.pop_front();
        }
        if (pastFlips % 2 == nums[i])
        {
            if (i + k > n)
                return -1;
            flips++;
            pastFlips++;
            flipQ.push_back(1);
        }
        else
        {
            flipQ.push_back(0);
        }
    }
    return flips;
}