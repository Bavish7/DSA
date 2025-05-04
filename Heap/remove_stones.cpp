#include<iostream>
using namespace std;

// REMOVE STONES TO MINIMIZE THE TOTAL (LEETCODE 1962)
// CREATING MAX HEAP AND MINIMIZING THE STONE PILES. TC=O(N*LOG N), SC=O(N)

// Steps:
// 1. Initialize a max-heap (priority queue) and push all elements from the piles into it.
// 2. Perform k iterations:
//    a. Extract the maximum element from the heap.
//    b. Reduce the extracted element by half (integer division).
//    c. Push the reduced element back into the heap.
// 3. Calculate the total sum of elements left in the heap by extracting each element and adding it to the sum.
// 4. Return the computed sum.

int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < piles.size(); i++)
    {
        pq.push(piles[i]);
    }
    while (k--)
    {
        int element = pq.top();
        pq.pop();
        element = element - floor(element / 2);
        pq.push(element);
    }
    int sum = 0;
    while (!pq.empty())
    {
        int top = pq.top();
        sum += top;
        pq.pop();
    }
    return sum;
}