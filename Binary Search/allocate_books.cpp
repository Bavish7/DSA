#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

// ALLOCATE BOOKS, SPLIT ARRAY LARGEST SUM (LEETCODE 410), PAINTER'S PARTITION
// USING BINARY SEARCH - TC=O(M*LOG(SUM)), SC=O(1)

// Steps:
// 1. Calculate the total sum of pages in the array 'arr'.
// 2. Set the search range: 's' as 0 and 'e' as the total sum of pages.
// 3. Use binary search to find the minimum possible maximum pages 'ans' that can be allocated to any student.
// 4. Check if it's possible to allocate books such that 'm' students can be satisfied with at most 'mid' pages using 'isPossible' function.
// 5. Adjust search range based on whether it's possible to allocate books with at most 'mid' pages per student.
// 6. Return the minimum possible maximum pages 'ans'.

bool isPossible(int arr[], int n, int m, int mid){
    int studentCount=1;
    int pageSum=0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            else{
                pageSum=arr[i];
            }
        }
    }
    return true;
}
int allocateBooks(int arr[], int n, int m){
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid=(s+e)/2;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return ans;
}