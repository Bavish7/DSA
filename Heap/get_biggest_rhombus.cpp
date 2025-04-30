#include<iostream>
using namespace std;

// GET BIGGEST THREE RHOMBUS SUMS IN A GRID (LEETCODE 1878)
// USING MAXHEAP - TC=O(M*N*K), SC=O(M*N) ; K=NO. OF RHOMBUSES

// Steps:
// 1. `checkBounds`: Check if all vertices are within the grid bounds. 
//    - Iterate through the list of points, return false if any point is out of bounds.
//    - Return true if all points are valid.
// 2. `getAllVertices`: Calculate the 4 vertices (A, B, C, D) for the current delta (distance from the center).
//    - If the vertices are within bounds, store them in the vector `v` and return true, otherwise return false.
// 3. `getAllSum`: Calculate the rhombus sums for each center `(i, j)`. 
//    - Add the center to the max heap.
//    - Increase delta to expand the rhombus, calculate the sum of the vertices and diagonals, and push the sum into the heap.
//    - Continue expanding until vertices go out of bounds.
// 4. `canPush`: Ensure that only unique values are added to the result.
//    - Check if the current top value from the heap is already in `ans`. Return false if it is, true otherwise.
// 5. `getBiggestThree`: For every cell `(i, j)`, compute all rhombus sums and store them in a max heap.
//    - Pop the top 3 unique values from the heap and return them as the result.

bool checkBounds(vector<vector<int>> &grid, vector<pair<int, int>> &v)
{
    int m = grid.size();
    int n = grid[0].size();
    for (auto point : v)
    {
        if (point.first < 0 || point.first >= m || point.second < 0 || point.second >= n)
        {
            return false;
        }
    }
    return true;
}
bool getAllVertices(vector<vector<int>> &grid, vector<pair<int, int>> &v, pair<int, int> c, int &delta)
{
    pair<int, int> A(c.first - delta, c.second);
    pair<int, int> B(c.first, c.second + delta);
    pair<int, int> C(c.first + delta, c.second);
    pair<int, int> D(c.first, c.second - delta);
    v[0] = A;
    v[1] = B;
    v[2] = C;
    v[3] = D;
    if (checkBounds(grid, v))
    {
        return true;
    }
    return false;
}
void getAllSum(vector<vector<int>> &grid, int &i, int &j, priority_queue<int> &maxHeap)
{
    maxHeap.push(grid[i][j]);
    int delta = 1;
    vector<pair<int, int>> v(4);
    int csum = 0;
    while (getAllVertices(grid, v, {i, j}, delta))
    {
        pair<int, int> &A = v[0];
        pair<int, int> &B = v[1];
        pair<int, int> &C = v[2];
        pair<int, int> &D = v[3];
        int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];
        for (int i = 1; i < (B.first - A.first); i++)
        {
            csum += grid[A.first + i][A.second + i];
        }
        for (int i = 1; i < (C.first - B.first); i++)
        {
            csum += grid[B.first + i][B.second - i];
        }
        for (int i = 1; i < (C.first - D.first); i++)
        {
            csum += grid[C.first - i][C.second - i];
        }
        for (int i = 1; i < (D.first - A.first); i++)
        {
            csum += grid[D.first - i][D.second + i];
        }
        maxHeap.push(csum);
        delta++;
    }
}
bool canPush(vector<int> &ans, int &top)
{
    for (auto value : ans)
    {
        if (value == top)
        {
            return false;
        }
    }
    return true;
}
vector<int> getBiggestThree(vector<vector<int>> &grid)
{
    vector<int> ans;
    priority_queue<int> maxHeap;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getAllSum(grid, i, j, maxHeap);
        }
    }
    while (!maxHeap.empty() && ans.size() < 3)
    {
        int top = maxHeap.top();
        maxHeap.pop();
        if (canPush(ans, top))
        {
            ans.push_back(top);
        }
    }
    return ans;
}