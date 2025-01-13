#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// FIND DUPLICATE ELEMENT IN AN ARRAY
// USING XOR - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize a variable to store the result using XOR.
// 2. XOR all elements in the array to get an intermediate result.
// 3. XOR this result with all numbers from 1 to n-1.
// 4. The final result after all XOR operations will be the duplicate element.

void duplicateElement(int arr[],int n){
    int ans = 0;
    for (int i = 0; i < n;i++){
        ans = ans ^ arr[i];
    }
    for (int i = 1; i < n;i++){
        ans = ans ^ i;
        cout << ans << " ";
    }
    cout << "Duplicate element in an array is : "<<ans;
}
int main(){
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    duplicateElement(arr, n);
}