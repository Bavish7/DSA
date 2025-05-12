#include<iostream>
using namespace std;

// REVERSE LINKED LIST(LEETCODE 206)
// USING ITERATION - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize Pointers: Start with `prev` as NULL and `curr` as the head of the list.
// 2. Iterate Through List: For each node, save the next node, reverse the `next` pointer of the current node to point to `prev`, update `prev` to the current node, and move `curr` to the next node.
// 3. Return New Head: When the iteration completes, `prev` will be the new head of the reversed list.

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

// USING RECURSION - TC=O(N), SC=O(N)
// Steps:
// 1. Base Case: If `curr` is NULL, return `prev` as the new head of the reversed list.
// 2. Reverse Current Node: Reverse the `next` pointer of `curr` to point to `prev`.
// 3. Recursive Call: Recursively call the function with the next node and updated pointers.
// 4. Return the Result: Return the result from the recursive call.
ListNode *reverseUsingRecursion(ListNode *prev, ListNode *curr){
    if(curr==NULL){
        return prev;
    }
    ListNode *newNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = newNode;
    ListNode *ans= reverseUsingRecursion(prev, curr);
    return ans;
}
ListNode *reverseList(ListNode *head){
    ListNode *prev = NULL;
    ListNode *curr = head;
    return ListNode * reverseUsingRecursion(prev, curr);
}
