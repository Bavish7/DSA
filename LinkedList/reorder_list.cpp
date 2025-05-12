#include<iostream>
using namespace std;

// REORDER LIST (LEETCODE 143)
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Use a stack to store all nodes of the linked list.
// 2. Determine the size `n` of the linked list.
// 3. Iterate `n/2` times to reorder nodes:
//    - Pop the top node from the stack.
//    - Insert it after the current node.
//    - Move to the next node in the original order.
// 4. Set `curr->next = NULL` to properly terminate the reordered list.

void reorderList(ListNode *head)
{
    stack<ListNode *> st;
    ListNode *curr = head;
    while (curr)
    {
        st.push(curr);
        curr = curr->next;
    }
    int n = st.size();
    curr = head;
    for (int i = 0; i < n / 2; i++)
    {
        ListNode *topNode = st.top();
        st.pop();
        ListNode *temp = curr->next;
        curr->next = topNode;
        topNode->next = temp;
        curr = temp;
    }
    curr->next = NULL;
}

// USING RECURSION - TC=O(N), SC=O(N)
// Steps:
// 1. Use recursion to reach the last node of the linked list.
// 2. On returning from recursion, reorder the list by:
//    - Linking `curr->next` to `head` to place the last node after the current node.
//    - Setting `head->next` to `temp` (original next node).
// 3. Handle edge cases:
//    - If `temp == NULL`, stop further modifications.
//    - If `curr == head`, mark the new end of the list by setting `curr->next = NULL`.
// 4. Update `curr` to `temp` for the next reordering step.
// 5. Initialize `curr` with `head` before calling `solve(head)`.

ListNode *curr;
void solve(ListNode *head)
{
    if (head == NULL)
        return;
    solve(head->next);
    ListNode *temp = curr->next;
    if (temp == NULL)
        return;
    else if (curr == head)
    {
        curr->next = NULL;
        return;
    }
    curr->next = head;
    head->next = (temp == head) ? NULL : temp;
    curr = temp;
}
void reorderList(ListNode *head)
{
    curr = head;
    solve(head);
}

// USING FIND MIDDLE + REVERSE + MERGE - TC=O(N), SC=O(1)
// Steps:
// 1. Use the slow and fast pointer technique to find the middle of the linked list.
// 2. Reverse the second half of the list using the `reverseList` function.
// 3. Merge the two halves alternately:
//    - Connect the first half's node to a node from the reversed second half.
//    - Update pointers to continue merging while maintaining order.
// 4. Stop merging when the reversed half is fully processed.

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *newNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = newNode;
    }
    return prev;
}
void reorderList(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *rev = reverseList(slow);
    ListNode *curr = head;
    while (rev->next != NULL)
    {
        ListNode *tempCurr = curr->next;
        curr->next = rev;
        ListNode *tempRev = rev->next;
        rev->next = tempCurr;
        curr = tempCurr;
        rev = tempRev;
    }
}