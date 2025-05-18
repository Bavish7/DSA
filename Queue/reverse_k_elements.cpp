#include <iostream>
#include <queue>
using namespace std;

// REVERSE FIRST K ELEMETS OF A QUEUE - TC=O(N), SC=O(K)

// Steps to reverse the first K elements of a queue:
// 1. Create a stack to temporarily hold elements.
// 2. Pop the first K elements from the queue and push them onto the stack.
// 3. Pop elements from the stack and push them back into the queue. This reverses the order of the first K elements.
// 4. Move the remaining elements in the queue (i.e., elements after the first K) to the back of the queue to preserve their order.
// 5. Return the modified queue.

queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    for (int i = 0; i < k; i++)
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < q.size() - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}