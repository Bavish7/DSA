#include<iostream>
using namespace std;

// CANDY (LEETCODE 135)
// USING GREEDY APPROACH - TC=O(3N), SC=O(2N)

// Steps:
// 1. Initialize two vectors `left` and `right` to store the number of candies to be given to each child.
// 2. Initialize the `left` vector with 1 for all children.
// 3. Iterate from left to right and update the `left` vector based on the ratings of the children.
// 4. Iterate from right to left and update the `right` vector based on the ratings of the children.
// 5. Initialize a variable `totalCandies` to store the total number of candies.
// 6. Iterate through the `left` and `right` vectors and add the maximum of the two values to `totalCandies`.
// 7. Return `totalCandies`.

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> left(n, 1), right(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
            left[i] = left[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            right[i] = right[i + 1] + 1;
    }
    int totalCandies = 0;
    for (int i = 0; i < n; i++)
    {
        totalCandies += max(left[i], right[i]);
    }
    return totalCandies;
}

// USING SLOPE APPROACH - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize the `sum` variable to 1 and the `i` variable to 1.
// 2. Iterate through the ratings array:
//    - If the current rating is equal to the previous rating, increment the `sum` and move to the next child.
//    - Find the peak of the current child:
//      - Increment the `sum` by the peak value.
//      - Move to the next child.
//    - Find the down of the current child:
//      - Increment the `sum` by the down value.
//      - Move to the next child.
//    - If the down value is greater than the peak value, increment the `sum` by the difference between the down and peak values.
// 3. Return the `sum`.

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    int sum = 1, i = 1;
    while (i < n)
    {
        if (ratings[i] == ratings[i - 1])
        {
            sum++;
            i++;
            continue;
        }
        int peak = 1;
        while (i < n && ratings[i] > ratings[i - 1])
        {
            peak++;
            sum += peak;
            i++;
        }
        int down = 1;
        while (i < n && ratings[i] < ratings[i - 1])
        {
            sum += down;
            down++;
            i++;
        }
        if (down > peak)
        {
            sum += down - peak;
        }
    }
    return sum;
}
