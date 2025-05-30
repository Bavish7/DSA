#include<iostream>
using namespace std;

// MINIMUM SPEED TO ARRIVE ON TIME (LEETCODE 1870)
// USING BINARY SEARCH - TC=O(N*LOG(MAXSPEED)), SC=O(1)

// Steps:
// 1. Binary Search over speed range [1, 1e7] to find minimum valid speed.
// 2. For each speed `mid`, use `findTime` to compute total time required.
//    a. For all but the last segment, time = ceil(dist[i] / speed)
//    b. For the last segment, use exact time = dist[i] / speed
// 3. If total time <= hour, try to minimize speed → move `high = mid - 1`
// 4. If total time > hour, increase speed → move `low = mid + 1`
// 5. Return the smallest valid speed that satisfies the constraint.

double findTime(vector<int>&dist, int mid){
    double time=0;
    int n=dist.size();
    for(int i=0;i<n-1;i++){
        time+=ceil((dist[i]*1.0)/(mid*1.0));
    }
    time+=((dist[n-1]*1.0)/(mid*1.0));
    return time;
}
int minSpeedOnTime(vector<int>& dist, double hour) {
    int low=1, high=1e7;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        double totalTime=findTime(dist, mid);
        if(totalTime<=hour){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}