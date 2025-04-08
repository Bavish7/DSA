#include<iostream>
using namespace std;

// CLONE GRAPH (LEETCODE 133)
// USING DFS TRAVERSAL - TC=O(V+E), SC=O(V)

// Steps:
// 1. Use a hash map to track cloned nodes and avoid cycles.
// 2. Start DFS from the original node, creating a clone and mapping it.
// 3. For each neighbor:
//    - If not visited, create a clone, map it, and recurse.
//    - Otherwise, connect the cloned node to the existing clone in the map.
// 4. Return the cloned graph's starting node.

void dfs(Node *node, Node *clone_node, unordered_map<Node *, Node *> &mp)
{
    for (Node *nbr : node->neighbors)
    {
        if (mp.find(nbr) == mp.end())
        {
            Node *newNode = new Node(nbr->val);
            mp[nbr] = newNode;
            clone_node->neighbors.push_back(newNode);
            dfs(nbr, newNode, mp);
        }
        else
        {
            clone_node->neighbors.push_back(mp[nbr]);
        }
    }
}
Node *cloneGraph(Node *node)
{
    if (!node)
        return NULL;
    unordered_map<Node *, Node *> mp;
    Node *clone_node = new Node(node->val);
    mp[node] = clone_node;
    dfs(node, clone_node, mp);
    return clone_node;
}

// USING BFS TRAVERSAL - TC=O(V+E), SC=O(V)
// Steps:
// 1. Use a hash map to store cloned nodes and avoid cycles.
// 2. Use a queue for BFS traversal, starting from the original node.
// 3. For each dequeued node:
//    - Clone and map unvisited neighbors, pushing them into the queue.
//    - Connect the cloned node to the already mapped neighbors.
// 4. Return the cloned graph's starting node.

void bfs(queue<Node *> &q, unordered_map<Node *, Node *> &mp)
{
    while (!q.empty())
    {
        Node *node = q.front();
        Node *clone_node = mp[node];
        q.pop();
        for (Node *nbr : node->neighbors)
        {
            if (mp.find(nbr) == mp.end())
            {
                Node *newNode = new Node(nbr->val);
                mp[nbr] = newNode;
                clone_node->neighbors.push_back(newNode);
                q.push(nbr);
            }
            else
            {
                clone_node->neighbors.push_back(mp[nbr]);
            }
        }
    }
}
Node *cloneGraph(Node *node)
{
    if (!node)
        return NULL;
    unordered_map<Node *, Node *> mp;
    Node *clone_node = new Node(node->val);
    mp[node] = clone_node;
    queue<Node *> q;
    q.push(node);
    bfs(q, mp);
    return clone_node;
}