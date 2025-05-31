#include<iostream>
using namespace std;

// SNAKES AND LADDERS (LEETCODE 909)
// USING BFS TRAVERSAL - TC=O(N^2), SC=O(N*N)

// Steps:
// 1. Flatten the 2D board into a 1D array `number[]` representing the board in Boustrophedon order (left-right, then right-left).
// 2. Use BFS to simulate the shortest path from square 1 (index 0) to square n*n (index n*n - 1).
// 3. For each square, roll a dice (1 to 6) and check reachable squares:
//    - If the destination square has a ladder/snake (i.e., number[next] != -1), move to that square instead.
//    - Track visited squares using `dist[]` array to avoid revisiting.
// 4. Return the number of moves when you reach the last square, else -1 if unreachable.

int snakesAndLadders(vector<vector<int>>& board) {
    int n=board.size();
    queue<int>q;
    vector<int>number(n*n);
    int index=0;
    bool leftToRight=true;
    for(int i=n-1;i>=0;i--){
        if(leftToRight){
            for(int j=0;j<n;j++){
                number[index++]=board[i][j];
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                number[index++]=board[i][j];
            }
        }
        leftToRight=!leftToRight;
    }
    vector<int>dist(n*n,-1);
    q.push(0);
    dist[0]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        if(curr==n*n-1){
            return dist[curr];
        }
        for(int i=1;i<=6;i++){
            int next=curr+i;
            if(next>=n*n) continue;
            if(number[next]!=-1){
                next=number[next]-1;
            }
            if(dist[next]==-1){
                dist[next]=dist[curr]+1;
                q.push(next);
            }
        }
    }
    return -1;
}