#include<iostream>
using namespace std;

// MINIMIZE THE MAXIMUM DIFFERENCE OF PAIRS (LEETCODE 2616)
// USING BINARY SEARCH ON ANSWER - TC=O(N*LOG(MAX)), SC=O(1)

// Steps:
// 1. Sort the nums array to make adjacent differences meaningful.
// 2. Use binary search on the possible values of max difference (from 0 to max(nums)).
// 3. For each mid (max allowed difference), call totalPairs():
//    - Greedily count how many disjoint pairs (i, i+1) can be formed with difference <= mid.
//    - If count >= p, we can try for smaller max difference.
//    - Otherwise, we need a larger allowed difference.
// 4. The minimum such mid that allows at least p pairs is the answer.

int totalPairs(vector<int>&nums,int mid){
    int count=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]-nums[i-1]<=mid){
            count++;
            i++;
        }
    }
    return count;
}
int minimizeMax(vector<int>& nums, int p) {
    int n=nums.size();
    if(p==0) return 0;
    sort(nums.begin(), nums.end());
    int maxEle=0;
    for(int i=0;i<n;i++){
        maxEle=max(maxEle,nums[i]);
    }
    int left=0, right=maxEle;
    while(left<right){
        int mid=(left+right)/2;
        if(totalPairs(nums,mid)>=p){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return left;
}