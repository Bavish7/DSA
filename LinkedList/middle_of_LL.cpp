#include<iostream>
using namsespace std;

// MIDDLE OF THE LINKED LIST(LEETCODE 876)
// USING LENGTH METHOD - TC=O(N)

// Steps:
// 1. **Calculate Length:** Traverse the list to determine its length.
// 2. **Find Middle Node:** Traverse the list again to reach the middle node.

int getLength(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
ListNode *middleNode(ListNode *head)
{
    int length = getLength(head);
    ListNode *temp = head;
    int count = 0;
    while (count < length / 2)
    {
        temp = temp->next;
        count++;
    }
    return temp;
}

// USING TWO POINTERS (HARE AND TORTOISE ALGORITHM) - TC=O(N)
// Steps:
// 1. **Initialize Pointers:** Use two pointers, `slow` and `fast`. Both start at the head of the list.
// 2. **Traverse List:** Move `fast` pointer two steps and `slow` pointer one step at a time.
// 3. **Find Middle:** When `fast` reaches the end of the list, `slow` will be at the middle.

ListNode *middleNode(ListNode *head){
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}