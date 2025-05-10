#include<iostream>
using namespace std;

// ODD EVEN LINKED LIST(LEETCODE 328)
// REARRANGING LINKED LIST - TC=O(N), SC=O(1)

// Steps:
// 1. **Handle Edge Cases:** If the list is empty or has only one node, return it as-is.
// 2. **Initialize Pointers:** Use two pointers, `h1` for odd nodes and `h2` for even nodes.
// 3. **Rearrange Nodes:** Iterate through the list, adjusting pointers to segregate odd and even nodes.
// 4. **Connect Lists:** Finally, connect the end of the odd list to the start of the even list.

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *h1 = head;
    ListNode *h2 = head->next;
    ListNode *evenHead = h2;
    while (h2 != NULL && h2->next != NULL)
    {
        h1->next = h2->next;
        h2->next = h2->next->next;
        h1 = h1->next;
        h2 = h2->next;
    }
    h1->next = evenHead;
    return head;
}