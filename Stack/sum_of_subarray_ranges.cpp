#include<iostream>
using namespace std;

// SUM OF SUBARRAY RANGES (LEETCODE 2104)
// USING MONOTONIC STACK - TC=O(N), SC=O(N)

// Steps:
// 1. The problem is to find the sum of the maximum elements of all subarrays minus the sum of the minimum elements of all subarrays of an array `nums`.
// 2. Use a monotonic stack to find the next greater element (NGE) and the previous greater or equal element (PGEE) for each element.
// 3. The NGE and PGEE help in calculating the number of subarrays in which the current element is the maximum element.
// 4. The total sum of maximum elements is calculated by multiplying the number of subarrays with the current element.
// 5. The sum of the maximum elements of all subarrays is the sum of the products of the current element with the number of subarrays.
// 6. Similarly, calculate the sum of the minimum elements of all subarrays using the previous approach.
// 7. Return the difference between the sum of maximum elements and the sum of minimum elements.

vector<int> findNSE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPSEE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}
long long sumSubarrayMins(vector<int> &arr)
{
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSEE(arr);
    long long total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;
        total = total + (right * left * 1LL * arr[i]);
    }
    return total;
}
vector<int> findNGE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPGEE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}
long long sumSubarrayMaxs(vector<int> &arr)
{
    vector<int> nse = findNGE(arr);
    vector<int> pse = findPGEE(arr);
    long long total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;
        total = total + (right * left * 1LL * arr[i]);
    }
    return total;
}
long long subArrayRanges(vector<int> &nums)
{
    return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
}
