#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LARGEST ROW SUM

// Steps:
// 1. Initialize variables 'maxi' to track the maximum sum found and 'rowIndex' to store the index of the row with the maximum sum.
// 2. Iterate through each row of the 2D array using variable 'i'.
//    - Initialize 'sum' to accumulate the sum of elements in the current row.
//    - Iterate through each column of the current row using variable 'j', adding each element to 'sum'.
//    - Compare 'sum' with 'maxi'. If 'sum' is greater than 'maxi':
//      - Update 'maxi' with the value of 'sum'.
//      - Update 'rowIndex' with the current row index 'i'.
// 3. After completing the iteration through all rows, 'rowIndex' will contain the index of the row with the largest sum.
// 4. Return 'rowIndex'.

int largestRowSum(int arr[][3], int row, int col)
{
    int maxi = -1;
    int rowIndex = -1;
    for (int i = 0; i < row;i++){
        int sum = 0;
        for (int j = 0; j < col;j++){
            sum += arr[i][j];
        }
        if(sum>maxi){
            maxi = sum;
            rowIndex = i;
        }
    }
    return rowIndex;
}
int main(){
    int row, col;
    cin >> row >> col;
    int arr[100][3];
    for (int i = 0; i < row;i++){
        for (int j = 0; j < col;j++){
            cin >> arr[i][j];
        }
    }
    cout << largestRowSum(arr, row, col);
}