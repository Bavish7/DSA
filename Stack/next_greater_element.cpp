#include<iostream>
using namespace std;

// NEXT GREATER ELEMENT I (LEETCODE 496)
// USING MONOTONIC STACK - TC=O(N+M), SC=O(M)

// Steps:
// 1. Use a stack to find the next greater element for each number in `nums2` in reverse order.
// 2. Traverse `nums2` from right to left:
//    - Pop elements from the stack until the top is greater than the current number or the stack is empty.
//    - If the stack is empty, there is no greater element, so map the current number to -1.
//    - Otherwise, map the current number to the stack's top element (next greater element).
//    - Push the current number onto the stack.
// 3. Use the map to look up the next greater elements for `nums1` and construct the result vector.

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums2.size(), n = nums1.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    stack<int> st;
    st.push(-1);
    for (int i = m - 1; i >= 0; i--)
    {
        while (!st.empty() && nums2[i] > st.top())
        {
            st.pop();
        }
        if (st.empty())
        {
            mp[nums2[i]] = -1;
        }
        else
        {
            mp[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
}

// NEXT GREATER ELEMENT II (LEETCODE 503)
// USING MONOTONIC STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Traverse the array `nums` twice to handle the circular nature of the array.
// 2. Use a stack to find the next greater element for each number in `nums` in reverse order.
// 3. Traverse `nums` from right to left:
//    - Pop elements from the stack until the top is greater than the current number or the stack is empty.
//    - If the stack is empty, there is no greater element, so map the current number to -1.
//    - Otherwise, map the current number to the stack's top element (next greater element).
//    - Push the current number onto the stack.
// 4. Use the map to look up the next greater elements for `nums` and construct the result vector.

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[i % n] >= st.top())
        {
            st.pop();
        }
        if (!st.empty() && i < n)
        {
            ans[i] = st.top();
        }
        st.push(nums[i % n]);
    }
    return ans;
}