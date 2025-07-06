#include<iostream>
#include<vector>
using namespace std;

// INSERTION IN A SEGMENT TREE - TC=O(4*N), SC=O(2*N)
void buildTree(vector<int>&arr, int index, int left, int right, vector<int>&tree){
    if(left==right){
        tree[index] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    buildTree(arr, 2 * index + 1, left, mid, tree);
    buildTree(arr, 2 * index + 2, mid + 1, right, tree);
    tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
}

// SINGLE UPDATION IN A SEGMENT TREE - TC=O(LOGN), SC=O(1)
void updateTree(int index, int value, int root, int left, int right, vector<int>&tree){
    if(left==right){
        tree[root] = value;
        return;
    }
    int mid = (left + right) / 2;
    if(index<=mid){
        updateTree(index, value, 2 * root + 1, left, mid, tree);
    }
    else{
        updateTree(index, value, 2 * root + 2, mid + 1, right, tree);
    }
    tree[root] = tree[2 * root + 1] + tree[2 * root + 2];
}

// RANGE UPDATION IN A SEGMENT TREE OR LAZY PROPAGATION- TC=O(LOGN), SC=O(4*N)
void updateRange(int start, int end, int i, int left, int right, int val, vector<int>&tree, vector<int>&lazy){
    if(lazy[i]!=0){
        tree[i] += lazy[i] * (right - left + 1);
        if(left!=right){
            lazy[2 * i + 1] = lazy[i];
            lazy[2 * i + 2] = lazy[i];
        }
        lazy[i] = 0;
        return;
    }
    if(left>end || right<start || left>right){
        return;
    }
    if(start<=left && end>=right){
        tree[i] += (right - left + 1)*val;
        if(left!=right){
            lazy[2 * i + 1] = val;
            lazy[2 * i + 2] = val;
            return;
        }
    }
    int mid = (left + right) / 2;
    updateRange(start, end, 2 * i + 1, left, mid, tree, lazy);
    updateRange(start, end, 2 * i + 2, mid + 1, right, tree, lazy);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    return;
}

// QUERY IN A SEGMENT TREE - TC=O(LOGN), SC=O(1)
int sumQuery(int index,int start, int end, int left, int right, vector<int>&tree){
    if(left>end || right<start){
        return 0;
    }
    else if(start<=left && end>=right){
        return tree[index];
    }
    else{
        int mid = (left + right) / 2;
        return sumQuery(2 * index + 1, start, end, left, mid, tree)+ sumQuery(2*index+2,start,end,mid+1,right,tree);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    vector<int> tree(4*n, 0);
    buildTree(arr, 0, 0, n-1, tree);
    for (int i = 0; i < 4*n;i++){
        cout << tree[i] << " ";
    }
    cout << endl;
    updateTree(1, 2, 0, 0, n - 1, tree);
    for (int i = 0; i < 4*n; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    int sum = sumQuery(0, 1, 2, 0, n - 1, tree);
    cout << sum << endl;
}