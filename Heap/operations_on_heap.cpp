#include<iostream>
using namespace std;

// INSERTION - TC=O(LOG N), SC=O(CAPACITY)
// DELETION - TC=O(LOG N), SC=O(1)
class Heap{
    public:
    int *arr;
    int size;
    int capacity;
    Heap(int capacity){
        this->arr = new int(capacity);
        this->size = 0;
        this->capacity = capacity;
    }
    void insert(int val){
        if(size==capacity){
            cout << "Heap overflow" << endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parentIndex = index / 2;
            if(arr[index]>arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }
    void printHeap(){
        for (int i = 1; i <= size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int deleteElement(){
        int answer = arr[1];
        arr[1] = arr[size];
        size--;
        int index = 1;
        while(index<size){
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int largestIndex = index;
            if(leftIndex<=size && arr[largestIndex]<arr[leftIndex]){
                largestIndex = leftIndex;
            }
            if(rightIndex<=size && arr[largestIndex]<arr[rightIndex]){
                largestIndex = rightIndex;
            }
            if(largestIndex==index){
                break;
            }
            else{
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
        }
        return answer;
    }
};

// HEAPIFY USING RECURSION - TC=O(LOG N), SC=O(H)
void heapify(int *arr, int size, int index)
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestIndex = index;
    if (leftIndex <= size && arr[largestIndex] < arr[leftIndex])
    {
        largestIndex = leftIndex;
    }
    if (rightIndex <= size && arr[largestIndex] < arr[rightIndex])
    {
        largestIndex = rightIndex;
    }
    if (index != largestIndex)
    {
        swap(arr[index], arr[largestIndex]);
        index = largestIndex;
        heapify(arr, size, index);
    }
}

// BUILD HEAP USING ARRAY - TC=O(N)
void buildHeap(int *arr,int n){
    for (int i = n / 2; i > 0;i--){
        heapify(arr, n, i);
    }
}

// HEAP SORT - TC=O(N*LOG N)
void heapSort(int *arr, int n){
    while(n!=1){
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}
int main(){
    Heap h(20);
    h.insert(5);
    h.insert(10);
    h.insert(15);
    h.insert(6);
    h.insert(25);
    h.insert(50);
    h.printHeap();
    int ans = h.deleteElement();
    cout << "Deleted element is: "<<ans << endl;
    h.printHeap();

    int arr[] = {-1,5, 10, 15, 20, 25, 12};
    int n = 6;
    buildHeap(arr, n);
    for (int i = 1; i <= 6;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    heapSort(arr, n);
    for (int i = 1; i <= 6;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}