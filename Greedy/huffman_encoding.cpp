#include<iostream>
using namespace std;

// MESSAGE ENCODING
// USING MIN HEAP AND GREEDY APPROACH - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Define a Node class to represent each node in the Huffman tree.
// 2. Define a comparator class to be used by the priority queue (min-heap).
// 3. Define a function to traverse the Huffman tree and generate the codes for each character.
// 4. Define the main function `huffmanCode` to generate the Huffman codes for the input array.
//    - Create a min-heap using the priority queue to store nodes based on their frequency.
//    - Build the Huffman tree by combining the two nodes with the smallest frequencies until only one node remains in the heap.
//    - Traverse the Huffman tree to generate the binary codes for each character.
// 5. Return the generated codes.

class Node
{
public:
    int data, index;
    Node *left;
    Node *right;
    Node(int d, int i)
    {
        this->data = d;
        this->index = i;
        this->left = NULL;
        this->right = NULL;
    }
};
class comp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
void traverse(Node *root, string temp, vector<string> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->index != -1)
    {
        ans[root->index] = temp;
    }
    traverse(root->left, temp + "0", ans);
    traverse(root->right, temp + "1", ans);
}
vector<string> huffmanCode(vector<int> &arr)
{
    priority_queue<Node *, vector<Node *>, comp> minHeap;
    int n = arr.size();
    if (n == 1)
    {
        return {"0"};
    }
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node(arr[i], i);
        minHeap.push(temp);
    }
    while (minHeap.size() > 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();
        Node *newNode = new Node(left->data + right->data, -1);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }
    Node *root = minHeap.top();
    vector<string> ans(n, "");
    string temp = "";
    traverse(root, temp, ans);
    return ans;
}