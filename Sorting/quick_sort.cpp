#include<iostream>
using namespace std;

// TC=O(N^2), SC=O(N)
int partition(int arr[], int l, int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void QuickSort(int arr[], int l, int r){
    if(l<r){
        int pi=partition(arr, l, r);
        QuickSort(arr, l, pi-1);
        QuickSort(arr, pi+1, r);
    }
}
int main(){
    int n;
    cout<<"Enter no. of terms : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    QuickSort(arr,0,n-1);
    cout << "Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}