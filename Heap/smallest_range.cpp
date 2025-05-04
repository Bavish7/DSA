#include<iostream>
using namespace std;

// SMALLEST RANGE COVERING ELEMENTS FROM K LISTS (LEETCODE 632)
// Create a min - heap of size K and insert the first element of all the lists into the heap.TC = O(N * K * LOG(K)), SC = O(K)

// Steps:
// 1. Initialize a min-heap and push the first element of each list into the heap.
//    - Keep track of the maximum value among the first elements of the lists.
// 2. Initialize `mini` and `maxi` to keep track of the current smallest and largest values in the heap.
//    - Set `mini` to the minimum of all the first elements and `maxi` to the maximum.
// 3. Continue processing until the heap is empty:
//    - Extract the minimum element from the heap (this is the smallest element in the current window).
//    - Update the range `[mini, maxi]` if the new range is smaller than the previous one.
//    - If the extracted element's list has more elements, push the next element from the same list into the heap.
//    - Update `maxi` to the maximum of the current `maxi` and the newly added element.
// 4. Return the smallest range `[ansStart, ansEnd]` found during the process.

class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;
    Info(int data, int rowIndex, int colIndex)
    {
        this->data = data;
        this->rowIndex = rowIndex;
        this->colIndex = colIndex;
    }
};
class Compare
{
public:
    bool operator()(Info *first, Info *second)
    {
        return first->data > second->data;
    }
};
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<Info *, vector<Info *>, Compare> pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int element = nums[i][0];
            Info *temp = new Info(element, i, 0);
            pq.push(temp);
            maxi = max(element, maxi);
            mini = min(element, mini);
        }
        int ansStart = mini;
        int ansEnd = maxi;
        while (!pq.empty())
        {
            Info *topNode = pq.top();
            int topData = topNode->data;
            int topRow = topNode->rowIndex;
            int topCol = topNode->colIndex;
            pq.pop();
            mini = topData;
            int oldRangeDistance = ansEnd - ansStart;
            int newRangeDistance = maxi - mini;
            if (newRangeDistance < oldRangeDistance)
            {
                ansStart = mini;
                ansEnd = maxi;
            }
            if (topCol + 1 < nums[topRow].size())
            {
                int newElement = nums[topRow][topCol + 1];
                Info *newNode = new Info(newElement, topRow, topCol + 1);
                maxi = max(newElement, maxi);
                pq.push(newNode);
            }
            else
            {
                break;
            }
        }
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};