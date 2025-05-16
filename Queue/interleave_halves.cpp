#include <iostream>
#include <queue>
using namespace std;

// INTERLEAVE FIRST HALF OFF THE QUEUE WITH THE SECOND HALF
// USING QUEUE AND STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Calculate the size of the first half of the queue.
// 2. Push the first half of the elements into a stack.
// 3. Pop elements from the stack and push them back into the queue. This reverses the first half of the queue.
// 4. Move the elements in the queue (which are now in the order of the second half followed by the reversed first half) to the back of the queue. This puts the second half of the queue at the end.
// 5. Push the elements from the queue (the reversed first half) into the stack again.
// 6. Interleave the elements from the stack and the remaining elements in the queue.

void interLeaveQueue(queue<int> &q)
{
    stack<int> st;
    int half = q.size() / 2;
    for (int i = 0; i < half; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < half; i++)
    {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < half; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}