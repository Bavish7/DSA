#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

// FINDING SQUARE ROOT
// USING BINARY SEARCH - TC=O(LOGN), SC=O(1)

// Steps:
// 1. Initialize start (s) to 0 and end (e) to n.
// 2. Compute mid as the average of s and e.
// 3. Use binary search:
//    a. If mid*mid equals n, return mid.
//    b. If mid*mid is less than n, update ans to mid and move s to mid+1.
//    c. If mid*mid is greater than n, move e to mid-1.
// 4. Repeat until s is less than or equal to e.
// 5. Return ans as the integer square root of n.

long long int squareRoot(int n){
    int s=0;
    int e=n;
    long long int mid=(s+e)/2;
    long long int ans=-1;
    while(s<=e){
        long long int square=mid*mid;
        if(square==n){
            return mid;
        }
        else if(square<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return ans;
}

// Steps:
// 1. Initialize factor to 1 and ans to temp.
// 2. Iterate precision number of times:
//    a. Reduce factor by dividing it by 10 to increase precision.
//    b. Perform nested loop:
//       i. Starting from current ans, increment by factor until j*j is less than n.
//       ii. Update ans with j in each iteration.
// 3. Return ans with the desired precision.

double morePrecision(int n, int precision, int temp){
    double factor=1;
    double ans=temp;
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}
