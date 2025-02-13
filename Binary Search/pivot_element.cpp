#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

// FIND PIVOT IN AN ARRAY
// USING BINARY SEARCH - TC=O(LOGN), SC=O(1)

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