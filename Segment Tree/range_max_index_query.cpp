#include<iostream>
using namespace std;

// RANGE MAX INDEX QUERY 
// USING SEGMENT TREE - TC=O(N+QLOGN), SC=O(N)

// Steps:
// 1. buildTree(): Recursively builds a segment tree where each node stores the index of
//    the maximum value in the corresponding range.
//    - Base case: if left == right, store the index itself.
//    - Recursive case: build left and right subtrees, then store the index of the max value
//      between the two children using the input array `arr`.

// 2. rangeMaxIndexQuery(): Returns the index of the maximum element in the given query range.
//    - If the current node's range is completely outside the query range, return -1.
//    - If it's fully within, return the stored index.
//    - Else, recurse on both children and return the index of the larger value.

void buildTree(int i, int left, int right, vector<int>&arr, vector<int>&tree){
    if(left==right){
        tree[i] = left;
        return;
    }
    int mid = (left + right) / 2;
    buildTree(2 * i + 1, left, mid, arr, tree);
    buildTree(2 * i + 2, mid + 1, right, arr, tree);
    if(arr[tree[2*i+1]]>=arr[tree[2*i+2]]){
        tree[i] = tree[2 * i + 1];
    }
    else{
        tree[i] = tree[2 * i + 2];
    }
}
int rangeMaxIndexQuery(int i, int left, int right, int start, int end, vector<int>&tree, vector<int>&arr){
    if(left>end || right<start){
        return -1;
    }
    if(start<=left && right<=end){
        return tree[i];
    }
    int mid = (left + right) / 2;
    int leftIndex = rangeMaxIndexQuery(2 * i + 1, left, mid, start, end, tree, arr);
    int rightIndex = rangeMaxIndexQuery(2 * i + 2, mid + 1, right, start, end, tree, arr);
    if(leftIndex==-1){
        return rightIndex;
    }
    if(rightIndex==-1){
        return leftIndex;
    }
    return (arr[leftIndex] >= arr[rightIndex]) ? leftIndex : rightIndex;
}