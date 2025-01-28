#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// SUM OF SUBARRAYS
int main(){
    int n;
    cout<<"enter no. of terms : ";
    cin>>n;
    int arr[n];
    cout<<"enter values : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            cout<<sum<<endl;
        }
    }
}