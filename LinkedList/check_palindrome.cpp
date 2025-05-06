#include<iostream>
using namespace std;

// PALINDROME LINKED LIST
// FINDING MIDDLE, REVERSING AND COMPARING - TC=O(N), SC=O(1)

// Steps:
// 1. Find the middle of the linked list:
//    - Use two pointers: `fast` and `slow`.
//    - Move `fast` two steps at a time and `slow` one step at a time.
//    - When `fast` reaches the end, `slow` will be at the middle of the list.
// 2. Reverse the second half of the list:
//    - Call a recursive function `reverse_LL` to reverse the portion of the list starting from the node after the middle.
//    - The function reverses the list in place by adjusting the `next` pointers of the nodes.
// 3. Compare the two halves of the list:
//    - Traverse both the original first half and the reversed second half of the list.
//    - Compare the values of the nodes one by one.
//    - If all values match, the list is a palindrome; otherwise, it is not.

ListNode *middle(ListNode *head)
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
ListNode *reverse_LL(ListNode *prev, ListNode *curr)
{
    if (curr == NULL)
    {
        return prev;
    }
    ListNode *newNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = newNode;
    return reverse_LL(prev, curr);
}
bool compare(ListNode *head, ListNode *head2)
{
    while (head2 != NULL)
    {
        if (head->val != head2->val)
        {
            return false;
        }
        else
        {
            head = head->next;
            head2 = head2->next;
        }
    }
    return true;
}
bool isPalindrome(ListNode *head)
{
    ListNode *mid = middle(head);
    ListNode *head2 = mid->next;
    mid->next = NULL;
    ListNode *prev = NULL;
    ListNode *curr = head2;
    head2 = reverse_LL(prev, curr);
    bool ans = compare(head, head2);
    return ans;
}