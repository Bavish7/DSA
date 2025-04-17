#include<iostream>
using namespace std;

// PATH WITH MINIMUM EFFORT (LEETCODE 1631)
// USING MIN HEAP AND GREEDY ALGORITHM - TC=O(E*LOGE), SC=O(E)

// Steps:
// 1. Initialize a priority queue (minHeap) to store cells in the format (effort, (x, y)).
//    - The priority queue will always process the cell with the minimum effort first.
// 2. Create a 2D vector `diff` to keep track of the minimum effort required to reach each cell.
//    - Initialize all cells in `diff` with INT_MAX, except the starting cell (0, 0), which is initialized to 0.
// 3. Push the starting cell (0, 0) with an effort of 0 into the minHeap.
// 4. While the minHeap is not empty:
//    - Extract the cell with the minimum effort from the heap.
//    - If the cell is the bottom-right corner of the grid, return the effort required to reach it.
//    - Otherwise, for each of the 4 possible directions (up, down, left, right):
//      - Calculate the new cell's coordinates and check if they are within grid bounds.
//      - Compute the maximum difference between the current cell and the new cell.
//      - If this maximum difference is smaller than the currently known effort to reach the new cell:
//        - Update the effort for the new cell.
//        - Push the new cell with the updated effort into the minHeap.
// 5. If the loop finishes without finding the bottom-right corner, return 0 (shouldn't happen in valid inputs).

int minimumEffortPath(vector<vector<int>> &heights)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    int row = heights.size();
    int col = heights[0].size();
    vector<vector<int>> diff(row, vector<int>(col, INT_MAX));
    diff[0][0] = 0;
    minHeap.push({0, {0, 0}});
    while (!minHeap.empty())
    {
        auto topPair = minHeap.top();
        minHeap.pop();
        int currDiff = topPair.first;
        pair<int, int> currNodeIndex = topPair.second;
        int currX = currNodeIndex.first;
        int currY = currNodeIndex.second;
        if (currX == row - 1 && currY == col - 1)
        {
            return diff[currX][currY];
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            if (newX >= 0 && newY >= 0 && newX < row & newY < col)
            {
                int maxDiff = max(currDiff, abs(heights[currX][currY] - heights[newX][newY]));
                if (diff[newX][newY] > maxDiff)
                {
                    diff[newX][newY] = maxDiff;
                    minHeap.push({diff[newX][newY], {newX, newY}});
                }
            }
        }
    }
    return 0;
}