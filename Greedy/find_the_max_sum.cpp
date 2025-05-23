#include<iostream>
using namespace std;

// FIND THE MAXIMUM SUM OF NODE VALUES (LEETCODE 3068)
// USING GREEDY ALGORITHM - TC=O(N), SC=O(1)

// Steps:
// 1. Try flipping each number with XOR `k`: nums[i] ^ k.
// 2. If flipping increases value, keep flipped version and increment `count`.
// 3. Track total `idealSum` after flips.
// 4. Track `minLoss`: minimum difference if we undo one beneficial flip to make `count` even.
// 5. If `count` is even → return `idealSum`.
// 6. If `count` is odd → subtract `minLoss` to make flips even, ensuring maximum even-parity subset.

long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    int n=nums.size();
    long long idealSum=0;
    int count=0;
    int minLoss=INT_MAX;
    for(int i=0;i<n;i++){
        if((nums[i]^k)>nums[i]){
            count++;
            nums[i]=nums[i]^k;
        }
        minLoss=min(minLoss, nums[i]-(nums[i]^k));
        idealSum+=nums[i];
    }
    if(count%2==0) return idealSum;
    return idealSum-minLoss;
}