#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter no. of terms: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    for (int i = 1; i < n;i++){
        int j = i - 1;
        int current = arr[i];
        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// FIND INDEX OF ELEMENTS IN SORTED ARRAY
// int main(){
//     int n;
//     cout << "Enter no. of terms: ";
//     cin >> n;
//     int arr[n],arr2[n],arr1[n];
//     cout << "Enter elements: ";
//     for (int i = 0; i < n;i++){
//         cin >> arr[i];
//     }
//     for(int i=0;i<n;i++){
//         arr1[i] = arr[i];
//     }
//     for (int i = 1; i < n;i++){
//         int j = i - 1;
//         int current = arr[i];
//         while(arr[j]>current && j>=0){
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = current;
//     }
//     for (int i = 0; i < n;i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < n;i++){
//         for (int j = 0; j < n;j++){
//             if(arr1[i]==arr[j]){
//                 arr2[i] = j;
//             }
//         }
//     }
//     for (int i = 0; i < n;i++){
//         cout << arr2[i] << " ";
//     }
//     cout << endl;
// }

// SEARCH INDEX OF THE ELEMENTS IN THE SORTED ARRAY USING BINARY SEARCH
// int binarySearch(int arr[],int s, int e, int key){
//     int start = s;
//     int end = e;
//     int mid = (start + end) / 2;
//     while(start<=end){
//         if(arr[mid]==key){
//             return mid;
//         }
//         else if(arr[mid]<key){
//             start=mid+1;
//         }
//         else{
//             end=mid-1;
//         }
//         mid=(start+end)/2;
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cout << "Enter no. of terms: ";
//     cin >> n;
//     int arr[n],arr2[n],arr1[n];
//     cout << "Enter elements: ";
//     for (int i = 0; i < n;i++){
//         cin >> arr[i];
//     }
//     for(int i=0;i<n;i++){
//         arr1[i] = arr[i];
//     }
//     for (int i = 1; i < n;i++){
//         int j = i - 1;
//         int current = arr[i];
//         while(arr[j]>current && j>=0){
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = current;
//     }
//     cout << "Sorted array is: ";
//     for (int i = 0; i < n;i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < n;i++){
//         arr2[i]=binarySearch(arr, 0, n - 1, arr1[i]);
//     }
//     cout << "Index found at position: ";
//     for (int i = 0; i < n;i++){
//         cout << arr2[i] << " ";
//     }
//     cout << endl;
// }