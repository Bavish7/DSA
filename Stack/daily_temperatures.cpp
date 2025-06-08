#include<iostream>
using namespace std;

// DAILY TEMPERATURES (LEETCODE 739)
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a result vector `ans` with zeros and a stack `st`.
// 2. Iterate through temperatures:
//    - For each temperature, pop indices from the stack until the current temperature is not warmer.
//    - Update `ans` with the difference between the current index and the popped index.
//    - Push the curre

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> ans(temperatures.size(), 0);
    stack<int> st;
    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return ans;
}