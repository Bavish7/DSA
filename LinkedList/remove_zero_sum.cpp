#include<iostream>
using namespace std;

// REMOVE ZERO SUM CONSECUTIVE NODES FROM LINKED LIST (LEETCODE 1171)
// USING PREFIX SUM AND UNORDERED MAP - TC=O(N), SC=O(N)

// Steps:
// 1. Traverse the linked list, maintaining a cumulative sum (csum) at each node.
// 2. If csum equals 0, reset the head to the next node, as all nodes up to the current one sum to zero.
// 3. If csum is found in the map, it indicates that the sum of nodes between the previously encountered csum and the current node is zero. Call sanitizeMap to remove all nodes between them and adjust pointers.
// 4. If csum is not found in the map, add the current node to the map with csum as the key.
// 5. Continue the traversal until the end of the list, returning the modified list.

void sanitizeMap(ListNode *curr, unordered_map<int, ListNode *> &mp, int csum)
{
    int temp = csum;
    while (true)
    {
        temp += curr->val;
        if (temp == csum)
        {
            break;
        }
        mp.erase(temp);
        curr = curr->next;
    }
}
ListNode *removeZeroSumSublists(ListNode *head)
{
    if (!head || (!head->next && head->val == 0))
        return 0;
    unordered_map<int, ListNode *> mp;
    ListNode *current = head;
    int csum = 0;
    while (current)
    {
        csum += current->val;
        if (csum == 0)
        {
            head = current->next;
            mp.clear();
        }
        else if (mp.find(csum) != mp.end())
        {
            sanitizeMap(mp[csum]->next, mp, csum);
            mp[csum]->next = current->next;
        }
        else
        {
            mp[csum] = current;
        }
        current = current->next;
    }
    return head;
}