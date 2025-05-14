#include<iostream>
using namespace std;

// SORT LIST(LEETCODE 148) 
// USING MERGE SORT - TC=O(NLOGN), SC=O(LOGN)

// Steps:
// 1. **Find the Middle Node:**
//    - Use the fast and slow pointer technique to find the middle node of the list.
//    - The middle node will be used to divide the list into two halves.
// 2. **Merge Two Sorted Lists:**
//    - Compare the nodes of two sorted lists and merge them into a single sorted list.
// 3. **Sort the List:**
//    - Recursively divide the list into two halves until each sublist has a single node.
//    - Merge the sorted sublists to get the final sorted list.

ListNode *getMid(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
ListNode *merge(ListNode *left, ListNode *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    ListNode *ans = new ListNode(-1);
    ListNode *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->val <= right->val)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if (left != NULL)
    {
        temp->next = left;
    }
    if (right != NULL)
    {
        temp->next = right;
    }
    return ans->next;
}
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *mid = getMid(head);
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = NULL;
    left = sortList(left);
    right = sortList(right);
    ListNode *ans = merge(left, right);
    return ans;
}