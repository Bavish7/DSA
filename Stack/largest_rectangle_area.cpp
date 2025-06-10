#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// LARGEST RECTANGLE AREA IN HISTOGRAM (LEETCODE 84)
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a stack `st` to keep track of indices and a vector `ans` to store the result.
//    - Push `-1` onto the stack to handle cases where there is no smaller element to the right.
// 2. Iterate through the histogram from right to left (i.e., from the end of the array to the beginning).
// 3. For each element `curr` at index `i`:
//    - While the stack is not empty and the element at the index on the top of the stack is greater than or equal to `curr`:
//      - Pop the stack. This removes indices of elements that are not smaller than `curr`.
//    - The current top of the stack represents the index of the next smaller element to the right. Store this index in `ans[i]`.
//    - Push the current index `i` onto the stack.
// 4. After processing all elements, `ans` will contain the indices of the next smaller elements for each position.
// 5. Return the vector `ans`.

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next = nextSmallerElement(heights, n);
    for (int i = 0; i < next.size(); i++)
    {
        if (next[i] == -1)
        {
            next[i] = next.size();
        }
    }
    vector<int> prev = prevSmallerElement(heights, n);
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        int b = next[i] - prev[i] - 1;
        int area = l * b;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

// USING MONOTONIC STACK - TC=O(N), SC=O(N)
// Steps:
// 1. Traverse each bar in `heights`, using a stack to keep track of increasing indices.
// 2. For each bar, if it's shorter than the bar at the top of the stack:
//      - Pop the stack, considering the popped bar as the shortest in a rectangle.
//      - Calculate the rectangle area with this bar as height, bounded by the previous stack top (PSE) and current index (NSE).
//      - Update `maxArea` with the largest area found.
// 3. After traversal, process remaining bars in the stack as though they extend to the end of `heights` (NSE = n).
// 4. Return `maxArea` as the largest rectangle area.

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxArea = 0, n = heights.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int element = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int nse = n;
        int element = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, heights[element] * (nse - pse - 1));
    }
    return maxArea;
}
