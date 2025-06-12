#include<iostream>
using namespace std;

// MAXIMAL RECTANGLE (LEETCODE 85)
// USING MONOTONIC STACK - TC=O(N*M), SC=O(N*M)

// Steps:
// 1. Initialize a `histogram` array of size `m` to represent heights of bars in a histogram for each row.
// 2. Traverse each row in `matrix`:
//      - Update `histogram`: if the cell has '1', increase the height at `histogram[j]` by 1, otherwise reset `histogram[j]` to 0.
//      - Calculate the largest rectangle area in the updated `histogram` using `largestRectangleArea` function.
//      - Update `maxRectangle` with the maximum area found for the current histogram.
// 3. Return `maxRectangle` as the largest rectangle area found in the matrix.

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
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> histogram(m, 0);
    int maxRectangle = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                histogram[j]++;
            }
            else
            {
                histogram[j] = 0;
            }
        }
        maxRectangle = max(maxRectangle, largestRectangleArea(histogram));
    }
    return maxRectangle;
}