#include<iostream>
using namespace std;

// FIND MEDIAN FROM DATA STREAM (LEETCODE 295)
// CREATE MAXHEAP FOR STORING LOWER VALUES AND MINHEAP FOR STORING HIGHER VALUES. TC=O(LOGN), SC=O(N)

// Steps:
// 1. Use two heaps: maxHeap (stores smaller half) and minHeap (stores larger half).
// 2. Insert `num` into maxHeap if it's smaller than maxHeap's top, otherwise into minHeap.
// 3. Balance heaps if their sizes differ by more than 1 by moving elements between them.
// 4. If sizes are equal, median is the average of both tops; otherwise, it's the top of maxHeap.

class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.empty() || num < maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        if (abs((int)maxHeap.size() - (int)minHeap.size()) > 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
        {
            return (double)(minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {
            return maxHeap.top();
        }
    }
};