#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// CHECK ARRAY IS SORTED OR NOT
// USING RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Base Case: If the size of the array `n` is less than or equal to 1, the array is considered sorted. Return `true`.
// 2. Recursive Case: Call `isSorted` on the subarray starting from the second element, i.e., `arr + 1`, with size `n - 1`.
// 3. Check Current Elements: After the recursive call, check if the first two elements `arr[0]` and `arr[1]` are in ascending order (`arr[0] < arr[1]`).
//    - Return `true` if both the current check is true and the rest of the array (from recursive call) is sorted.
//    - Return `false` otherwise.

bool isSorted(int arr[],int n){
    if(n<=1){
        return true;
    }
    bool rest = isSorted(arr + 1, n - 1);
    return (arr[0]<arr[1] && rest);
}
int main(){
    int n;
    cout<<"Enter no. of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << isSorted(arr, n);
}