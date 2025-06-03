#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter no. of terms : ";
    cin>>n;
    int arr[n];
    cout<<"enter values : ";
    for(int a=0;a<n;a++){
        cin>>arr[a];
    }
    for(int i=0;i<n-1;i++){
        bool swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped==false){
            break;
        }
    }
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}

// BUBBLE SORT USING RECURSION
// void bubbleSort(int *arr, int n){
//     if(n<=1){
//         return;
//     }
//     for (int i = 0; i < n - 1;i++){
//         if(arr[i]>arr[i+1]){
//             swap(arr[i], arr[i + 1]);
//         }
//     }
//     bubbleSort(arr, n - 1);
// }
// int main(){
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     for (int i = 0; i < n;i++){
//         cin >> arr[i];
//     }
//     bubbleSort(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i]<<" ";
//     }
// }