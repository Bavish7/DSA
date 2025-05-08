#include<iostream>
using namespace std;

// LINKED LIST CYCLE(LEETCODE 141)
// USING ITERATION AND MAP - TC=O(N), SC=O(N)

// Steps:
// 1. Define a `map` to keep track of visited nodes in the linked list.
// 2. Traverse through the linked list starting from the head.
//    - For each node, check if it is already present in the `map`.
//      - If it is not present, add the node to the `map`.
//      - If it is present, return `true` as it indicates a cycle (node revisited).
// 3. If traversal completes without revisiting any node, return `false` indicating no cycle.

bool hasCycle(ListNode *head){
    map<ListNode*, bool> visited;
    ListNode *temp = head;
    while(temp!=NULL){
        if(visited[temp]==false){
            visited[temp] = true;
        }
        else{
            return true;
        }
        temp = temp->next;
    }
    return false;   
}

// USING TWO POINTERS (FLOYD'S CYCLE DETECTION ALGORITHM) - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize two pointers, `slow` and `fast`, both pointing to the head of the linked list.
// 2. Traverse the list using the `fast` pointer moving two steps at a time and the `slow` pointer moving one step at a time.
//    - If the `fast` pointer catches up to the `slow` pointer, it indicates the presence of a cycle.
// 3. If the `fast` pointer reaches the end of the list (i.e., becomes `NULL`), then there is no cycle.

bool hasCycle(ListNode *head){
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast==slow){
            return true;
        }
    }
    return false;
}