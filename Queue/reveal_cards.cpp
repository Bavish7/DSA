#include<iostream>
using namespace std;

// REVEAL CARDS IN INCREASING ORDER (LEETCODE 950)
// USING QUEUE AND SORTING - TC=O(NLOGN), SC=O(N)

// Steps : 
// 1. Sort the deck in increasing order.
// 2. Create a queue to store indices from 0 to deck.size() - these represent the positions in the final arrangement.
// 3. Initialize an empty vector `ans` to store the final answer, with the same size as the deck.
// 4. For each card in the sorted deck : -Assign the card to the index at the front of the queue.- Remove the front of the queue(since that position is now filled).- If the queue is not empty, move the next front of the queue to the back to simulate the "reveal and move" process.
// 5. Return the final arranged deck in `ans`.

vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    sort(deck.begin(), deck.end());
    queue<int> q;
    vector<int> ans(deck.size());
    for (int i = 0; i < deck.size(); i++)
    {
        q.push(i);
    }
    for (int i = 0; i < deck.size(); i++)
    {
        ans[q.front()] = deck[i];
        q.pop();
        if (!q.empty())
        {
            q.push(q.front());
            q.pop();
        }
    }
    return ans;
}