#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// FIND OCCURENCE OF A NUMBER
// USING RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Base Case: If the index `i` reaches the end of the array (`i == n`), return -1, indicating that the number was not found.
// 2. Check if the current element `arr[i]` is equal to the `key`.
//    - If true, return the current index `i` as the first occurrence.
// 3. Recursively call `first` with the next index `i+1` to continue searching in the rest of the array.
// 4. Return the result from the recursive call.

int first(int arr[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return first(arr,n,i+1,key);
}
int last(int arr[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    int rest=last(arr,n,i+1,key);
    if(rest!=-1){
        return rest;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}
int main(){
    int n,key;
    cout<<"Enter no. of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter no. to search : ";
    cin>>key;
    cout<<first(arr,n,0,key)<<endl;
    cout<<last(arr,n,0,key)<<endl;
}