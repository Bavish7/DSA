#include<iostream>
using namespace std;

// MERGE NODES IN BETWEEN ZEROES (LEETCODE 2181)
// USING TWO POINTERS APPROACH - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize slow to head and fast to head->next, as the first node is always 0.
// 2. Initialize sum to 0 and lastNode to NULL (for tracking the last non-zero node).
// 3. Traverse the list using fast while it's not NULL:
//    - If fast's value is 0, set slow's value to sum, reset sum to 0, and move lastNode to slow. Move slow to slow->next.
//    - Add fast's value to sum and move fast to fast->next.
// 4. After the loop, set lastNode's next to NULL to remove extra zero nodes at the end.
// 5. Return head as the starting point of the modified list.

ListNode *mergeNodes(ListNode *head)
{
    if (!head)
    {
        return NULL;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    ListNode *lastNode = NULL;
    int sum = 0;
    while (fast)
    {
        if (fast->val == 0)
        {
            slow->val = sum;
            sum = 0;
            lastNode = slow;
            slow = slow->next;
        }
        sum += fast->val;
        fast = fast->next;
    }
    lastNode->next = NULL;
    return head;
}