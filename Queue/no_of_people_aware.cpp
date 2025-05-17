#include<iostream>
using namespace std;

// NUMBER OF PEOPLE AWARE OF A SECRET (LEETCODE 2327)
// USING 2 QUEUES - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize MOD for modulo operations and required variables:
//    - `curr`: Tracks the current number of people who can share the secret.
//    - `ans`: Tracks the total number of people who know the secret.
//    - Two queues `forgetQ` and `delayQ` to track when people forget and when they can start sharing the secret.
//
// 2. For each day `i` from 1 to `n`:
//    - Remove people from `forgetQ` if they've forgotten the secret (day > first day they knew it + forget).
//    - Remove people from `delayQ` if they are eligible to start sharing (day > first day they knew it + delay).
//
// 3. If there are people who can share the secret (`curr > 0`):
//    - Add them to `ans`.
//    - Add these people to both `forgetQ` and `delayQ` for future tracking.
//
// 4. Return the final count of people who know the secret at the end of day `n`.

int peopleAwareOfSecret(int n, int delay, int forget)
{
    const int MOD = 1e9 + 7;
    int curr = 0;
    int ans = 1;
    queue<pair<int, int>> forgetQ, delayQ;
    delayQ.push({1, 1});
    forgetQ.push({1, 1});
    for (int i = 1; i <= n; i++)
    {
        if (!forgetQ.empty() && forgetQ.front().first + forget <= i)
        {
            auto front = forgetQ.front();
            forgetQ.pop();
            int no = front.second;
            ans = (ans - no + MOD) % MOD;
            curr = (curr - no + MOD) % MOD;
        }
        if (!delayQ.empty() && delayQ.front().first + delay <= i)
        {
            auto front = delayQ.front();
            delayQ.pop();
            curr = (curr + front.second) % MOD;
        }
        if (curr > 0)
        {
            ans = (ans + curr) % MOD;
            forgetQ.push({i, curr});
            delayQ.push({i, curr});
        }
    }
    return ans;
}