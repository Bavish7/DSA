#include<iostream>
using namespace std;

// MAJORITY ELEMENT (LEETCODE 169)
// USING UNORDERED MAP - TC=O(N), SC=O(N)
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
        if (mp[nums[i]] > n / 2)
        {
            return nums[i];
        }
    }
    return 0;
}

// USING MOORE'S VOTING ALGORITHM - TC=O(N), SC=O(1)
int majorityElement(vector<int> &nums)
{
    int count = 0, element = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            element = nums[i];
        }
        if (element == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return element;
}

// MAJORITY ELEMENT II (LEETCODE 229)
// USING UNORDERED MAP - TC=O(N), SC=O(N)
vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    vector<int> ans;
    for (auto it : mp)
    {
        if (it.second > nums.size() / 3)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

// USING MOORE'S VOTING ALGORITHM - TC=O(N), SC=O(1)
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int cnt1 = 0, ele1 = INT_MIN;
    int cnt2 = 0, ele2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && nums[i] != ele2)
        {
            cnt1 = 1;
            ele1 = nums[i];
        }
        else if (cnt2 == 0 && nums[i] != ele1)
        {
            cnt2 = 1;
            ele2 = nums[i];
        }
        else if (ele1 == nums[i])
        {
            cnt1++;
        }
        else if (ele2 == nums[i])
        {
            cnt2++;
        }
        else
        {
            cnt1--, cnt2--;
        }
    }
    vector<int> ans;
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ele1)
        {
            cnt1++;
        }
        if (nums[i] == ele2)
        {
            cnt2++;
        }
    }
    int mini = (n / 3) + 1;
    if (cnt1 >= mini)
        ans.push_back(ele1);
    if (cnt2 >= mini)
        ans.push_back(ele2);
    return ans;
}