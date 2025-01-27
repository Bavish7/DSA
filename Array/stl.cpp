#include<iostream>
using namespace std;

// ARRAY
// #include<array>
// int main(){
//     array<int, 4> a = {1, 2, 3, 4};
//     int n = a.size();
//     for (int i = 0; i < n;i++){
//         cout << a[i] << " ";
//     }
//     cout << "Element at index 2 is: " << a.at(2) << endl;
//     cout << "Empty or not: " << a.empty() << endl;
//     cout << "First element is: " << a.front() << endl;
//     cout << "Last element is: " << a.back() << endl;
// }

// VECTOR
// #include<vector>
// int main(){
//     vector<int> v;
//     for (int i = 0; i < 5;i++){
//         v.push_back(i);
//     }
//     cout << "Capecity is: " << v.capacity() << endl;
//     cout << "Size is: " << v.size() << endl;
//     cout << "Element at 2nd index is: " << v.at(2) << endl;
//     v.pop_back();
//     v.clear();
//     cout << "New size is: " << v.size() << endl;
//     cout << "New capacity is: " << v.capacity() << endl;
// }

// DEQUE
// #include<deque>
// int main(){
//     deque<int> d;
//     d.push_front(1);
//     d.push_back(2);
//     cout << "Element at index 1 is: " << d.at(1) << endl;
//     cout << "Empty or not: " << d.empty() << endl;
//     cout << "Front element is: " << d.front() << endl;
//     cout << "Back element is: " << d.back() << endl;
//     d.pop_back();
//     d.pop_front();
// }

// LIST
// #include<list>
// int main(){
//     list<int> l;
//     l.push_back(1);
//     l.push_front(2);
//     l.erase(l.begin());
//     for(int i:l){
//         cout << i << " ";
//     }
//     cout << "Size is: " << l.size() << endl;
// }

// STACK
// #include<stack>
// int main(){
//     stack<int> s;
//     s.push(1);
//     s.push(2);
//     cout << "Top element is: " << s.top() << endl;
//     s.pop();
//     s.pop();
//     cout << "Empty or not: " << s.empty() << endl;
// }

// QUEUE
// #include<queue>
// int main(){
//     queue<int> q;
//     q.push(1);
//     q.push(2);
//     cout << "First element is: " << q.front() << endl;
//     q.pop();

// }

// PRIORITY QUEUE
// #include<queue>
// int main(){
//     // max heap
//     priority_queue<int> maxi;
//     maxi.push(1);
//     maxi.push(2);
//     int n = maxi.size();
//     for (int i = 0; i < n;i++){
//         cout << maxi.top() << " ";
//         maxi.pop();
//     }
//     cout << endl;
//     // min heap
//     priority_queue<int, vector<int>, greater<int>> mini;
//     mini.push(1);
//     mini.push(2);
//     int m = mini.size();
//     for (int i = 0; i < m; i++)
//     {
//         cout << mini.top() << " ";
//         mini.pop();
//     }
//     cout << endl;
// }

// SET
// #include<set>
// int main(){
//     set<int> s;
//     s.insert(5);
//     s.insert(1);
//     s.insert(2);
//     s.insert(6);
//     for(auto i:s){
//         cout << i << endl;
//     }
//     cout << "5 is present or not: " << s.count(5) << endl;
//     set<int>::iterator it = s.find(5);
//     for (auto itr = it; itr != s.end();itr++){
//         cout << *itr << " ";
//     }
// }

// MAP
// #include<map>
// int main(){
//     map<int, string> m;
//     m[1] = "bavish";
//     m[2] = "kumar";
//     for(auto i:m){
//         cout << i.first << " ";
//         cout << i.second << " ";    
//     }
//     cout << endl;
//     cout << "1 is present or not: " << m.count(1) << endl;
//     m.erase(2);
// }

// ALGORITHMS
#include<algorithm>
#include<vector>
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    cout << "Finding 3: "<<binary_search(v.begin(), v.end(),3) << endl;
    cout << "Lower bound of 3 is: " << lower_bound(v.begin(), v.end(), 3) - v.begin() << endl;
    cout << "Upper bound of 3 is: " << upper_bound(v.begin(), v.end(), 3) - v.begin() << endl;
    string a = "abcd";
    reverse(a.begin(), a.end());
    cout << a << endl;
    rotate(v.begin(), v.begin() + 2, v.end());
    for(int i:v){
        cout << i << " ";
    }
}