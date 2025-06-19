#include<iostream>
using namespace std;

// SUM OF SUBARRAY MINIMUMS (LEETCODE 907)
// USING MONOTONIC STACK - TC=O(N), SC=O(N)

// Steps:
// 1. The problem is to find the sum of the minimum elements of all subarrays of an array `arr`.
// 2. Use a monotonic stack to find the next smaller element (NSE) and the previous smaller or equal element (PSE) for each element.
// 3. The NSE and PSE help in calculating the number of subarrays in which the current element is the minimum element.
// 4. The total sum is calculated by multiplying the number of subarrays with the current element.
// 5. The sum of the minimum elements of all subarrays is the sum of the products of the current element with the number of subarrays.
// 6. Return the total sum modulo 10^9 + 7.

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
int sumSubarrayMins(vector<int> &arr)
{
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSEE(arr);
    int total = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < arr.size(); i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;
        total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
    }
    return total;
}