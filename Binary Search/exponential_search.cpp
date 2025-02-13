#include<iostream>
using namespace std;

// EXPONENTIAL SEARCH
// USING EXPONENTIAL AND BINARY SEARCH - TC=O(logN), SC=O(1)

// Steps:
// 1. Check if the first element is the target. If yes, return 0.
// 2. Initialize an index i to 1 and double it until arr[i] exceeds x or i reaches the array size.
// 3. Perform binary search between indices i/2 and min(i, n-1) to find the target element.

int binarySearch(vector<int>&arr, int start, int end, int x){
    while(start<=end){
        int mid = (start + end) / 2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            mid = end - 1;
        }
        else{
            mid = start + 1;
        }
        return -1;
    }
}
int expSearch(vector<int>&arr, int x, int x){
    if(arr[0]==x){
        return 0;
    }
    int i = 1;
    while(i<n && a[i]<=x){
        i *= 2;
    }
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}