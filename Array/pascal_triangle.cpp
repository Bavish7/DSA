#include<iostream>
using namespace std;

// PASCAL'S TRIANGLE (LEETCODE 118)
// USING COMBINATORICS - TC=O(N^2), SC=O(N^2)

// Steps:
// 1. Initialize a 2D vector to store rows of Pascal's Triangle.
// 2. For each row, compute elements using the formula:
//    current_element = previous_element * (row - column) / column.
// 3. Append each row to the result vector.
// 4. Return the complete triangle after generating all rows.
vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int row = 1; row <= numRows; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}