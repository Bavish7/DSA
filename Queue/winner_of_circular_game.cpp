#include<iostream>
using namespace std;

// FIND THE WINNER OF CIRCULAR GAME (LEETCODE 1823)
// USING QUEUE - TC=O(N*K), SC=O(N)

// Steps:
// 1. Initialize a queue `q` to hold the players numbered from 1 to n.
// 2. For each player, push them into the queue.
// 3. While there's more than one player left:
//    - For `k-1` times, take the player at the front, move them to the back of the queue (rotate the queue).
//    - Pop the player at the front of the queue after rotation (i.e., they are eliminated).
// 4. Once only one player remains, they are the winner. Return the winner's number.

queue<int> q;
int findTheWinner(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (q.size() > 1)
    {
        for (int i = 1; i < k; i++)
        {
            int element = q.front();
            q.pop();
            q.push(element);
        }
        q.pop();
    }
    return q.front();
}

// USING JOSEPHUS FORMULA - TC=O(N), SC=O(1)

// Steps : 
// 1. Initialize the winner as 1 since there's only one person initially. 
// 2. Iterate through 2 to n(number of people), simulating the Josephus problem.
// 3. In each iteration, calculate the new winner position using the Josephus formula : -Update winner = (winner + (k - 1)) % i + 1 - This ensures the correct circular counting.
// 4. Once the loop completes, return the final winner.int findTheWinner(int n, int k)

int findTheWinner(int n, int k)
{
    int winner = 1;
    for (int i = 2; i <= n; i++)
    {
        winner = (winner + (k - 1)) % i + 1;
    }
    return winner;
}