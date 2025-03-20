#include<iostream>
using namespace std;

// MAXIMUM HEIGHT BY STACKING CUBOIDS (LEETCODE 1691)
// SPACE OPTIMIZATION APPROACH - TC=O(N^2), SC=O(N)

// Steps:
// 1. Initialize two vectors, curr and next, each of size n+1 (where n is the number of cuboids).
//    - curr[j] will store the maximum height achievable by stacking cuboids[i...n-1] starting with cuboid j.
//    - next[j] will store the maximum height achievable by stacking cuboids[i...n-1] starting with cuboid j in the next iteration.
// 2. Iterate through cuboids from end to start (i = n-1 to 0):
//    a. Reset curr[n] to 0 for each iteration of cuboids.
//    b. Iterate through cuboids from end to start (j = i-1 to -1):
//       - If j == -1 or cuboids[i] can be placed on top of cuboids[j] (based on check function):
//         Set include = cuboids[i][2] + next[i + 1].
//       - Set exclude = 0 + next[j + 1].
//       - Store max(include, exclude) in curr[j].
// 3. Move curr to next for the next iteration of cuboids.
// 4. Return next[0], which contains the maximum height achievable by stacking all cuboids.

bool check(vector<int>& curr, vector<int>& prev)
{
    if (curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}
int solveUsingSO(vector<vector<int>> &cuboids)
{
    int n = cuboids.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int include = 0;
            if (j == -1 || check(cuboids[i], cuboids[j]))
            {
                int height = cuboids[i][2];
                include = height + next[i + 1];
            }
            int exclude = 0 + next[j + 1];
            curr[j + 1] = max(include, exclude);
        }
        next = curr;
    }
    return next[0];
}
int maxHeight(vector<vector<int>> &cuboids)
{
    for (auto &cuboid : cuboids)
    {
        sort(cuboid.begin(), cuboid.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int ans = solveUsingSO(cuboids);
    return ans;
}