#include<iostream>
using namespace std;

// LARGEST COLOR VALUE IN A DIRECTED GRAPH (LEETCODE 1857)
// USING TOPOLOGICAL SORT - TC=O(N+E), SC=O(N)

// Steps:
// 1. Build adjacency list `adj` and compute `indegree` of each node.
// 2. Initialize `maxColor[node][c]` to track max freq of color `c` in any path ending at `node`.
// 3. Push all nodes with indegree 0 into queue and set their color count to 1.
// 4. Do BFS (topological sort):
//    a. For each node, update the color frequency of its neighbors.
//    b. Decrement indegree; if 0, push neighbor into queue.
//    c. Track `ans` as max color frequency seen so far.
// 5. If all nodes are not visited (i.e., `count < n`), graph has a cycle → return -1.
// 6. Else, return `ans`.

int largestPathValue(string colors, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>>adj;
    int n=colors.size();
    vector<int>indegree(n,0);
    for(auto &edge: edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<vector<int>>maxColor(n, vector<int>(26,0));
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
            maxColor[i][colors[i]-'a']=1;
        }
    }
    int ans=0, count=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        ans=max(ans,maxColor[node][colors[node]-'a']);
        for(int &nbr: adj[node]){
            for(int i=0;i<26;i++){
                maxColor[nbr][i]=max(maxColor[nbr][i],maxColor[node][i]+(colors[nbr]-'a'==i));
            }
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    if(count<n) return -1;
    return ans;
}