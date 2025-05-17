#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front, rear, size;
    public:
    Queue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    bool isFull(){
        if(front==0 && rear==size-1){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(front==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int data){
        if(isFull()){
            cout << "Overflow" << endl;
        }
        else{
            if(front==-1){
                front = 0;
            }
            rear++;
            arr[rear] = data;
        }
    }
    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        else{
            int ans = arr[front];
            front++;
            return ans;
        }
    }
    void display(){
        int i;
        if(isEmpty()){
            cout << "Underflow" << endl;
        }
        else{
            for (i = front; i <= rear;i++){
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};
int main(){
    int n;
    cout << "Enter size of queue: ";
    cin >> n;
    Queue q1(n);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    cout << "Queue is: ";
    q1.display();
    cout<<"Deleted element is : "<<q1.dequeue()<<endl;
    cout << "Updated queue is: ";
    q1.display();
}

// #include <iostream>
// #include <queue>
// using namespace std;

// void findTopAndBottom(queue<int> q)
// {
//     if (q.empty())
//     {
//         cout << "Queue is empty." << endl;
//         return;
//     }
//     cout << "Top element of the queue: " << q.front() << endl;
//     while (q.size() > 1)
//     {
//         q.pop();
//     }
//     cout << "Bottom element of the queue: " << q.front() << endl;
// }

// int main()
// {
//     queue<int> myQueue;
//     myQueue.push(5);
//     myQueue.push(10);
//     myQueue.push(15);
//     myQueue.push(20);
//     findTopAndBottom(myQueue);
//     return 0;
// }
