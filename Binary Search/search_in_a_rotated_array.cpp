#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

// SEARCH IN ROTATED SORTED ARRAY (LEETCODE 33)
// USING BINARY SEARCH - TC=O(LOGN), SC=O(1)

// Steps:
// 1. Define a function getPivot(arr, n) to find the pivot index where the rotation starts:
//    - Binary search to find the index where arr[mid] >= arr[0].
//    - Returns the pivot index.

// 2. Define a function binarySearch(arr, s, e, key) to perform binary search:
//    - Regular binary search on a sorted rotated array segment.
//    - Returns the index of key if found, otherwise -1.

// 3. Define a function findPosition(arr, n, k) to find the position of element k:
//    - Use getPivot to get the pivot index.
//    - Depending on where k lies relative to the pivot, use binarySearch on the appropriate segment.
//    - Returns the index of k if found, otherwise -1.

int getPivot(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while (s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int binarySearch(int arr[], int s, int e, int key){
    int start=s;
    int end=e;
    int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return -1;
}
int findPosition(int arr[], int n, int k){
    int pivot=getPivot(arr,n);
    if(k>=arr[pivot] && k<=arr[n-1]){
        return binarySearch(arr, pivot, n-1, k);
    }
    else{
        return binarySearch(arr, 0, pivot-1,k);
    }
}

// SEARCH IN A ROTATED SORTED ARRAY II (LEETCODE 81)
// USING BINARY SEARCH - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize two pointers, `left` (start of array) and `right` (end of array).
// 2. Use a loop to perform binary search while `left <= right`:
//    - Calculate `mid` as the middle index.
//    - If `nums[mid]` equals `target`, return true.
//    - If the left half is sorted (`nums[left] < nums[mid]`):
//        - Check if `target` lies in the left half and update `right`, otherwise update `left`.
//    - If the left and mid elements are equal (`nums[left] == nums[mid]`), increment `left` to handle duplicates.
//    - Otherwise, the right half is sorted:
//        - Check if `target` lies in the right half and update `left`, otherwise update `right`.
// 3. If the loop ends without finding the `target`, return false.

bool search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target == nums[mid])
        {
            return true;
        }
        if (nums[left] < nums[mid])
        {
            if (target >= nums[left] && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if (nums[left] == nums[mid])
        {
            left++;
        }
        else
        {
            if (target > nums[mid] && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return false;
}
