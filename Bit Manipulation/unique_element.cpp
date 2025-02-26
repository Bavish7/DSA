#include<iostream>
using namespace std;

//FIND UNIQUE NUMBER IN AN ARRAY
int unique(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum^arr[i];
    }
    return sum;
}
int main(){
    int n;
    cout<<"enter no. of terms : ";
    cin>>n;
    int arr[n];
    cout<<"enter elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<unique(arr,n);
}




