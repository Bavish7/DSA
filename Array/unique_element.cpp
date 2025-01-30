#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// FIND UNIQUE ELEMENT IN AN ARRAY
void uniqueElement(int arr[],int n){
    int ans = 0;
    for (int i = 0; i < n;i++){
        ans = ans ^ arr[i];
    }
    cout << "Unique element in an array is : " << ans;
}
int main(){
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    uniqueElement(arr, n);
}