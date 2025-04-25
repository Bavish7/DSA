#include<iostream>
#include<unordered_map>
using namespace std;

// INSERTION,DELETION,SEARCHING IN TC=O(1)
// ORDERED MAP IS BASED ON THE IMPLEMENTATION OF BST. TC=O(LOGN)
int main(){
    unordered_map<string, int> m;
    pair<string, int> p = make_pair("Scorpio", 9);
    m.insert(p);
    pair<string, int> p2("alto", 2);
    m.insert(p2);
    m["fortuner"] = 10;
    cout << m.at("alto") << endl;
    cout << m["Scorpio"] << endl;
    cout << m.count("alto") << endl;
    for(auto i:m){
        cout << i.first << "->" << i.second << endl;
    }
}