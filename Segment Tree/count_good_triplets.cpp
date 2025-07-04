#include<iostream>
using namespace std;

// COUNT GOOD TRIPLETS IN AN ARRAY (LEETCODE 2179)
// USING SEGMENT TREE - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Map values from nums2 to their indices for quick position lookup.
// 2. Use a segment tree to keep track of elements from nums1 already seen (inserted) as per nums2's index.
// 3. For each nums1[i] (starting from i=1):
//     - Find its index in nums2 (mapped).
//     - Query how many elements before that index (in nums2) are already inserted (leftCommonCount).
//     - i - leftCommonCount gives leftUncommon elements (seen in nums1 but not on left in nums2).
//     - Total elements after current index = n - idx - 1.
//     - rightCommonCount = elementsAfterIdx - leftUncommon.
//     - Multiply leftCommonCount and rightCommonCount for count of valid triplets with nums1[i] as middle.
// 4. Update segment tree to mark current index as seen.

void updateTree(int i, int left, int right, int index, vector<long long>&segTree){
    if(left==right){
        segTree[i]=1;
        return;
    }
    int mid=(left+right)/2;
    if(index<=mid){
        updateTree(2*i+1,left,mid,index,segTree);
    }
    else{
        updateTree(2*i+2,mid+1,right,index,segTree);
    }
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}
long long queryTree(int start, int end, int i, int left, int right, vector<long long>&segTree){
    if(left>end || right<start){
        return 0;
    }
    if(left>=start && right<=end){
        return segTree[i];
    }
    int mid=(left+right)/2;
    return queryTree(start,end,2*i+1,left,mid,segTree)+queryTree(start,end,2*i+2,mid+1,right,segTree);
}
long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int>mp;
    int n=nums1.size();
    long long ans=0;
    vector<long long>segTree(4*n);
    for(int i=0;i<n;i++){
        mp[nums2[i]]=i;
    }
    updateTree(0,0,n-1,mp[nums1[0]],segTree);
    for(int i=1;i<n;i++){
        int idx=mp[nums1[i]];
        long long leftCommonCount=queryTree(0,idx,0,0,n-1,segTree);
        long long leftUncommon=i-leftCommonCount;
        long long elementsAfterIdx=n-idx-1;
        long long rightCommonCount=elementsAfterIdx - leftUncommon;
        ans+=leftCommonCount*rightCommonCount;
        updateTree(0,0,n-1,idx,segTree);
    }
    return ans;
}