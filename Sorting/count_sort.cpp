#include<iostream>
using namespace std;

void CountSort(int arr[], int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }
    int count[100]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
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
    CountSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}