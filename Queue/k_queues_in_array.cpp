#include <iostream>
#include <queue>
using namespace std;

// N QUEUE USING ARRAY - TC=O(1), SC=O(N)

// Steps:
// This class implements a fixed number of queues (n) using a single array of size s.
// The class maintains a free list of indices that can be used for enqueue operations.
//
// Attributes:
// - front: Array to keep track of the front indices of each queue.
// - rear: Array to keep track of the rear indices of each queue.
// - next: Array to manage the free spots and links between nodes.
// - arr: Array to store the actual elements.
// - freespot: Index of the next available spot for enqueue operations.

class NQueue
{
public:
    int freespot;
    int *front;
    int *rear;
    int *next;
    int *arr;
    NQueue(int n, int s)
    {
        front = new int[n];
        rear = new int[n];
        for (int i = 0; i < n; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[s];
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        arr = new int[s];
        next[s - 1] = -1;
        freespot = 0;
    }
    bool enqueue(int x, int m)
    {
        if (freespot == -1)
        {
            return false;
        }
        else
        {
            int index = freespot;
            freespot = next[index];
            if (front[m - 1] == -1)
            {
                front[m - 1] = index;
            }
            else
            {
                next[rear[m - 1]] = index;
            }
            next[index] = -1;
            rear[m - 1] = index;
            arr[index] = x;
            return true;
        }
    }
    int dequeue(int m)
    {
        if (front[m - 1] == -1)
        {
            return -1;
        }
        else
        {
            int index = front[m - 1];
            front[m - 1] = next[index];
            next[index] = freespot;
            freespot = index;
            return arr[index];
        }
    }
};
