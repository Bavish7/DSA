#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

// BINARY SEARCH
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;=
        }
    }
    return -1;
}
int main() {
    int size, target;
    cout << "Input no. of elements in an array: ";
    cin >> size;
    int arr[size];
    cout << "Input " << size << " values in ascending order:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Input the value to be searched: ";
    cin >> target;
    int position = binarySearch(arr, size, target);
    if (position != -1) {
        cout << "The target value " << target << " was found at position " << position << endl;
    } else {
        cout << "The target value " << target << " was not found in the array." << endl;
    }
    return 0;
}

// BINARY SEARCH USING RECURSION
// bool binarySearch(int *arr, int s, int e, int k){
//     if(s>e){
//         return false;
//     }
//     int mid = s + (e - s) / 2;
//     if(arr[mid]==k){
//         return true;
//     }
//     else if(arr[mid]<k){
//         return binarySearch(arr, mid + 1, e, k);
//     }
//     else{
//         return binarySearch(arr, s, mid - 1, k);
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     for (int i = 0; i < n;i++){
//         cin >> arr[i];
//     }
//     int k;
//     cin >> k;
//     cout << binarySearch(arr, 0, n, k);
//     delete[] arr;
// }