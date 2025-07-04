#include<iostream>
using namespace std;

// MINIMUM COST TO CONNECT ALL POINTS (LEETCODE 1584)
// USING PRIM'S ALGORITHM - TC-O(N^2*LOGN), SC=O(N^2)

// Steps:
// 1. Construct a complete graph where each edge weight is the Manhattan distance between points.
// 2. Use Prim's Algorithm with a min-heap to always pick the edge with the minimum cost to connect a new point.
// 3. Avoid revisiting nodes using a visited array.
// 4. Accumulate the total weight of edges added to form the MST.

int minCostConnectPoints(vector<vector<int>>& points) {
    unordered_map<int,vector<pair<int,int>>>adjList;
    int n=points.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int xWeight=points[i][0]-points[j][0];
            int yWeight=points[i][1]-points[j][1];
            int weight=abs(xWeight)+abs(yWeight);
            adjList[i].push_back({j,weight});
            adjList[j].push_back({i,weight});
        }
    }
    vector<bool>visited(n,0);
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>minHeap;
    int ans=0;
    minHeap.push({0,{0,-1}});
    while(!minHeap.empty()){
        auto topPair=minHeap.top();
        minHeap.pop();
        int wt=topPair.first;
        int node=topPair.second.first;
        int parent=topPair.second.second;
        if(visited[node]) continue;
        visited[node]=true;
        if(parent!=-1) ans+=wt;
        for(auto &nbr: adjList[node]){
            int nbrNode=nbr.first;
            int nbrWeight=nbr.second;
            if(!visited[nbrNode]){
                minHeap.push({nbrWeight,{nbrNode,node}});
            }
        }
    }
    return ans;
}