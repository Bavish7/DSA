#include<iostream>
#include<queue>
using namespace std;

// MAX HEAP
// int main(){
//     priority_queue<int> pq;
//     pq.push(10);
//     pq.push(20);
//     pq.push(30);
//     pq.push(25);
//     pq.push(40);
//     pq.pop();
//     cout << "Top element of heap is: " << pq.top()<<endl;
//     cout << "Size of heap is: " << pq.size() << endl;
// }

// MIN HEAP
int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(100);
    pq.push(70);
    pq.push(80);
    cout << "Top element is: " << pq.top();
}