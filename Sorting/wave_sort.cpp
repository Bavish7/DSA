#include<iostream>
using namespace std;

void swap(int arr[],int i, int j){
    int temp=arr[j];
    arr[j]=arr[i];
    arr[i]=temp;
}
void WaveSort(int arr[], int n){
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr,i,i-1);
        }
        if(arr[i]>arr[i+1] && i<=n-2){
            swap(arr,i,i+1);
        }
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
    WaveSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}