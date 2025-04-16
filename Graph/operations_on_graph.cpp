#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// GRAPH WITHOUT WEIGHTS
// CREATION - TC=O(V+E), SC=O(V+E)
class Graph{
    public:
        unordered_map<int, list<int>> adjList;
        void addEdge(int u, int v, bool direction){
            if(direction==1){
                adjList[u].push_back(v);
            }
            else{
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }
        void printGraph(){
            for(auto i:adjList){
                cout << i.first << "->{";
                for(auto j:i.second){
                    cout << j << ", ";
                }
                cout << "}" << endl;
            }
        }
};

// GRAPH WITH WEIGHTS
template<typename T>
class Graph1{
    public:
        unordered_map<T, list<pair<T, int>>> adjList;
        void addEdge(T u, T v, int wt, bool direction){
            if (direction==1){
                adjList[u].push_back({v, wt});
            }
            else{
                adjList[u].push_back({v, wt});
                adjList[v].push_back({u, wt});
            }
        }
        void printGraph(){
            for(auto i:adjList){
                cout << i.first << ": { ";
                for(pair<T,int>p:i.second){
                    cout << "{" << p.first << ", " << p.second << "}, ";
                }
                cout <<"}"<< endl;
            }
        }
        void bfsTraversal(T src, unordered_map<T, bool> &visited)
        {
            queue<T> q;
            q.push(src);
            visited[src] = true;
            while(!q.empty()){
                T frontNode = q.front();
                cout << frontNode << " ";
                q.pop();
                for(auto neighbour:adjList[frontNode]){
                    T neighbourData = neighbour.first;
                    if(!visited[neighbourData]){
                        q.push(neighbourData);
                        visited[neighbourData] = true;
                    }
                }
            }
        }
        void dfsTraversal(T src, unordered_map<T, bool>&visited){
            visited[src] = true;
            cout << src << " ";
            for(auto neighbour: adjList[src]){
                T neighbourData = neighbour.first;
                if(!visited[neighbourData]){
                    dfsTraversal(neighbourData, visited);
                }
            }
        }
};
int main(){ 
    // Graph G;
    // G.addEdge(0, 1, 1);
    // G.addEdge(1, 2, 1);
    // G.addEdge(1, 3, 1);
    // G.printGraph();

    Graph1<int> G;
    G.addEdge(0, 1, 5,1);
    G.addEdge(1, 2, 10,1);
    G.addEdge(3, 2, 15,1);
    G.printGraph();
    unordered_map<int, bool> visited;
    // for (int i = 0; i < 4;i++){
    //     if(!visited[i]){
    //         G.bfsTraversal(i, visited);
    //     }
    // }

    for (int i = 0; i < 4;i++){
        if(!visited[i]){
            G.dfsTraversal(i, visited);
        }
    }
}