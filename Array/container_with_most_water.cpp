#include<iostream>
using namespace std;

// CONTAINER WITH MOST WATER (LEETCODE 11)
// USING TWO POINTERS - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize two pointers, `i` at the start and `j` at the end of the height array.
// 2. Initialize `maxi` to 0 to keep track of the maximum area found.
// 3. While `i` is less than `j`:
//    - Calculate the minimum height between `height[i]` and `height[j]`.
//    - Calculate the width as `j - i`.
//    - Calculate the area as `minHeight * width`.
//    - Update `maxi` with the maximum of `area` and `maxi`.
//    - If `height[i]` is less than `height[j]`, increment `i` to move towards a potentially taller line.
//    - Otherwise, decrement `j` to move towards a potentially taller line.
// 4. Return `maxi` as the maximum area found.

int maxArea(vector<int>& height) {
    int n=height.size();
    int i=0, j=n-1;
    int maxi=0;
    while(i<j){
        int minHeight=min(height[i], height[j]);
        int width=j-i;
        int area=minHeight*width;
        maxi=max(area, maxi);
        if(height[i]<height[j]) i++;
        else j--;
    }
    return maxi;
}