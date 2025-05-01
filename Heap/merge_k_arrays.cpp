#include<iostream>
using namespace std;

// MERGE K SORTED ARRAYS
// Create a min-heap of size K and insert the first element of all the arrays, along with its indices, into the heap. TC=O(N*K*LOG(K)), SC=O(N*K)

// Steps:
// 1. Create a class `Info` to store the data, row index, and column index of each element in the heap.
// 2. Create a comparator class `Compare` to order the heap based on the data of `Info` objects.
// 3. Initialize a min-heap (priority queue) and push the first element of each array along with its indices into the heap.
// 4. While the heap is not empty:
//    a. Extract the top element from the heap (smallest element).
//    b. Add the data of the top element to the result array.
//    c. If the next element in the same array exists, push it into the heap with updated indices.
// 5. Return the result array containing all elements in sorted order.

class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;
    Info(int data, int rowIndex, int colIndex)
    {
        this->data = data;
        this->rowIndex = rowIndex;
        this->colIndex = colIndex;
    }
};
class Compare
{
public:
    bool operator()(Info *first, Info *second)
    {
        return first->data > second->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> ans;
    priority_queue<Info *, vector<Info *>, Compare> pq;
    for (int row = 0; row < k; row++)
    {
        int element = kArrays[row][0];
        Info *temp = new Info(element, row, 0);
        pq.push(temp);
    }
    while (!pq.empty())
    {
        Info *topNode = pq.top();
        pq.pop();
        int topData = topNode->data;
        int topRow = topNode->rowIndex;
        int topCol = topNode->colIndex;
        ans.push_back(topData);
        if (topCol + 1 < kArrays[topRow].size())
        {
            Info *newNode = new Info(kArrays[topRow][topCol + 1], topRow, topCol + 1);
            pq.push(newNode);
        }
    }
    return ans;
}

// ADD ALL THE ELEMENTS OF THE ARRAYS AND SORT THEM. TC=O(N*K*LOG(N*K)), SC=O(N*K)
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < kArrays[i].size(); j++)
        {
            ans.push_back(kArrays[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}