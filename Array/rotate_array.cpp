#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// ROTATE ARRAY (LEETCODE 189)
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[(i + k) % n] = nums[i];
    }
    nums = v;
}