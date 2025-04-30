#include<iostream>
using namespace std;

// K CLOSEST POINTS TO ORIGIN (LEETCODE 973)
// USING MINHEAP AND CUSTOM COMPARATOR - TC=O(NLOGN), SC=O(N)

// Steps:
// 1. Define a custom comparator `mycomp` for the priority queue (min-heap) to sort pairs based on their Euclidean distance from the origin. 
//    - Calculate distance as `x^2 + y^2` for each point.
//    - Return true if the distance of `a` is greater than `b` (so the smaller distance comes on top).
// 2. Push all points into the min-heap. Each point is represented as a pair (x, y).
// 3. Pop `k` closest points from the heap and add them to the result `ans`.
// 4. Return `ans` which contains the `k` closest points.

class mycomp
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        int distA = a.first * a.first + a.second * a.second;
        int distB = b.first * b.first + b.second * b.second;
        return distA > distB;
    }
};
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp> minHeap;
    for (auto point : points)
    {
        int x = point[0];
        int y = point[1];
        minHeap.push({x, y});
    }
    while (k > 0 && !minHeap.empty())
    {
        auto top = minHeap.top();
        ans.push_back({top.first, top.second});
        minHeap.pop();
        k--;
    }
    return ans;
}