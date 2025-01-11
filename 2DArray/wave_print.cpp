#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// WAVE PRINT
// USING NESTED FOR LOOP - TC=O(ROW*COL), SC=O(ROW*COL)

// Steps:
// 1. Initialize an empty vector 'ans' to store wave printed elements.
// 2. Iterate through each row of the matrix:
//    a. If the row index 'i' is even, append elements from left to right.
//    b. If the row index 'i' is odd, append elements from right to left.
// 3. Return the vector 'ans' containing wave printed elements.

vector<int> rowWaveForm(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    vector<int> ans;
    for (int i = 0; i < row; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < col; j++)
            {
                ans.push_back(mat[i][j]);
            }
        }
        else
        {
            for (int j = col - 1; j >= 0; j--)
            {
                ans.push_back(mat[i][j]);
            }
        }
    }
    return ans;
}
