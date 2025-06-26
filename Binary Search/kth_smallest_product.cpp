#include<iostream>
using namespace std;

// KTH SMALLEST PRODUCT OF TWO SORTED ARRAYS (LEETCODE 2040)
// USING BINARY SEARCH ON PRODUCTS - TC=O(LOG(RANGE)*N*LOG(M)), SC=O(1)

// Steps:
// 1. Initialize binary search range for the product value from -1e10 to 1e10.
// 2. For a mid value, count how many pairs (i,j) have product <= mid using two binary searches:
//    - If nums1[i] >= 0: binary search for largest index in nums2 such that product <= mid.
//    - If nums1[i] < 0: binary search for smallest index in nums2 such that product <= mid.
// 3. If the count is less than k, search in the right half (increase mid).
// 4. If count >= k, store mid as potential answer and move to the left half.
// 5. Return the smallest value for which at least k products are ≤ that value.

long long countProducts(long long num, vector<int>&nums1, vector<int>&nums2){
    long long count=0;
    for(int i=0;i<nums1.size();i++){
        if(nums1[i]>=0){
            int left=0, right=nums2.size()-1;
            int total=-1;
            while(left<=right){
                int mid=(left+right)/2;
                long long product=1LL*nums1[i]*nums2[mid];
                if(product<=num){
                    total=mid;
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            count+=total+1;
        }
        else{
            int left=0, right=nums2.size()-1;
            int total=nums2.size();
            while(left<=right){
                int mid=(left+right)/2;
                long long product=1LL*nums1[i]*nums2[mid];
                if(product<=num){
                    total=mid;
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            count+=(nums2.size()-total);
        }
    }
    return count;
}
long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
    int n=nums1.size();
    int m=nums2.size();
    long long left=-1e10;
    long long right=1e10;
    long long ans=0;
    while(left<=right){
        long long mid=(left+right)/2;
        long long count=countProducts(mid,nums1,nums2);
        if(count<k){
            left=mid+1;
        }
        else{
            ans=mid;
            right=mid-1;
        }
    }
    return ans;
}