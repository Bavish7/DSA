#include<iostream>
using namespace std;

// MAXIMUM CANDIES YOU CAN GET (LEETCODE 1298)
// USING BFS TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a queue for BFS, and sets to track visited and found boxes.
// 2. Add all initial boxes to the found set. If a box is open, enqueue it and add its candies.
// 3. While the queue is not empty, do the following for each box:
//    - Add all contained boxes to the found set.
//    - If a contained box is open and not visited, enqueue it and add its candies.
//    - For each key found in the box, mark the corresponding box as open (status = 1).
//      If that box is already found and not visited, enqueue it and add its candies.
// 4. Return the total number of candies collected.

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    unordered_set<int>visited;
    unordered_set<int>found;
    queue<int>q;
    int totalCandies=0;
    for(int &box: initialBoxes){
        found.insert(box);
        if(status[box]==1){
            q.push(box);
            visited.insert(box);
            totalCandies+=candies[box];
        }
    }
    while(!q.empty()){
        int box=q.front();
        q.pop();
        for(int &insideBox: containedBoxes[box]){
            found.insert(insideBox);
            if(status[insideBox]==1 && !visited.count(insideBox)){
                q.push(insideBox);
                visited.insert(insideBox);
                totalCandies+=candies[insideBox];
            }
        }
        for(int &boxKey: keys[box]){
            status[boxKey]=1;
            if(found.count(boxKey) && !visited.count(boxKey)){
                q.push(boxKey);
                visited.insert(boxKey);
                totalCandies+=candies[boxKey];
            }
        }
    }
    return totalCandies;
}