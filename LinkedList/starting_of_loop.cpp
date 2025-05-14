#include <iostream>
using namespace std;

// STARTING POINT OF LOOP(LEETCODE 142)
// USING ITERATION AND MAP - TC=O(N), SC=O(N)

// Steps:
// 1. Create a hash map to keep track of visited nodes.
// 2. Traverse the linked list using a pointer.
// 3. For each node, check if it has been visited before:
//    - If it has not been visited, add it to the hash map.
//    - If it has been visited, return the current node as it is the start of the loop.
// 4. If the traversal completes without finding a loop, return NULL indicating no loop is present.

ListNode *detectCycle(ListNode *head)
{
    map<ListNode *, bool> visited;
    ListNode *temp = head;
    while(temp!=NULL){
        if(visited[temp]==false){
            visited[temp] = true;
        }
        else{
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// USING TWO POINTERS (FLOYD'S CYCLE DETECTION ALGORITHM) - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize two pointers, `slow` and `fast`, both starting at the head of the list.
// 2. Move the `slow` pointer one step at a time and the `fast` pointer two steps at a time.
// 3. If a cycle exists, `slow` and `fast` will eventually meet inside the loop.
// 4. If `fast` reaches the end of the list (`NULL`), no cycle is present, so return `NULL`.
// 5. To find the start of the cycle, reinitialize `slow` to the head of the list.
// 6. Move both `slow` and `fast` one step at a time until they meet again; the meeting point is the start of the cycle.

ListNode *detectCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            break;
        }
    }
    if (fast == NULL)
    {
        return fast;
    }
    slow = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}