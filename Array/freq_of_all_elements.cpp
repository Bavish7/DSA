#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// COUNT NO. OF TIMES OF ALL ELEMENTS
// USING NESTED FOR LOOP - TC=O(N^2), SC=O(N)

// Steps:
// 1. Read the number of elements 'n' from the user.
// 2. Read 'n' elements into the array 'arr'.
// 3. Initialize an auxiliary array 'a' to keep track of visited elements.
// 4. Iterate through the array and for each element, count its occurrences.
// 5. Mark visited elements in the auxiliary array to avoid recounting.
// 6. Print the count of occurrences for each unique element.

int main(){
    int n;
    cout<<"enter no. of terms : ";
    cin>>n;
    int arr[n],a[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]!=1){
            int count=1;
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    count++;
                    a[j]=1;
                }
            }
            cout<<arr[i]<<" occurs "<<count<<" times "<<endl;
        }
    }
}