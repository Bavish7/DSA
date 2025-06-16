#include<iostream>
using namespace std;

// IMPLEMENT QUEUE USING STACKS (LEETCODE 232)
// USING 2 STACKS - PUSH IN TC=O(1), ELSE TC=O(N), SC=O(N)

// Steps:
// 1. `push(int x)`:
//    - Push elements directly onto stack `s1`, simulating enqueueing into the queue.
//
// 2. `pop()`:
//    - If `s2` (used for dequeuing) is not empty, simply pop the top element of `s2`.
//    - If `s2` is empty, transfer all elements from `s1` to `s2`, reversing their order. Then, pop the top of `s2`.
//    - Return the popped element.
//
// 3. `peek()`:
//    - If `s2` is not empty, the front of the queue is the top of `s2`.
//    - If `s2` is empty, transfer elements from `s1` to `s2`, then return the top of `s2` (this is the front of the queue).
//
// 4. `empty()`:
//    - Return true if both `s1` and `s2` are empty, meaning the queue is empty.

stack<int> s1, s2;
MyQueue()
{
}
void push(int x)
{
    s1.push(x);
}
int pop()
{
    int element = -1;
    if (!s2.empty())
    {
        element = s2.top();
    }
    else
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        element = s2.top();
    }
    s2.pop();
    return element;
}
int peek()
{
    int front = -1;
    if (!s2.empty())
    {
        front = s2.top();
    }
    else
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        front = s2.top();
    }
    return front;
}
bool empty()
{
    return s1.empty() && s2.empty();
}
