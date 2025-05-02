#include<iostream>
using namespace std;

// MERGE K SORTED LISTS (LEETCODE 23)
// Create a min-heap of size K and insert the first element of all the lists into the heap. TC=O(N*K*LOG(K)), SC=O(K)

// Steps:
// 1. Create a comparator class `Compare` to order the heap based on the value of `ListNode` objects.
// 2. Initialize a min-heap (priority queue) and push the head of each linked list into the heap.
// 3. Create a dummy head node and a tail pointer to build the merged linked list.
// 4. While the heap is not empty:
//    a. Extract the node with the smallest value from the heap.
//    b. Add this node to the merged linked list.
//    c. If the extracted node has a next node, push the next node into the heap.
// 5. Return the next node of the dummy head, which is the head of the merged linked list.

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, Compare> pq;
    for (int i = 0; i < lists.size(); i++)
    {
        ListNode *listHead = lists[i];
        if (listHead != NULL)
        {
            pq.push(listHead);
        }
    }
    ListNode *head = NULL;
    ListNode *tail = NULL;
    while (!pq.empty())
    {
        ListNode *topNode = pq.top();
        pq.pop();
        if (head == NULL)
        {
            head = topNode;
            tail = topNode;
            if (tail->next != NULL)
            {
                pq.push(tail->next);
            }
        }
        else
        {
            tail->next = topNode;
            tail = topNode;
            if (tail->next != NULL)
            {
                pq.push(tail->next);
            }
        }
    }
    return head;
}