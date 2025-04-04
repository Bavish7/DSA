#include<iostream>
using namespace std;

// ACCOUNTS MERGE (LEETCODE 721)
// USING DISJOINT SET - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Initialize a Union-Find structure (parent and rank arrays) for `n` accounts.
// 2. For each account, associate each email with its account using a map. If an email has been seen in another account, union the two accounts.
// 3. Create a map to group emails by their ultimate parent account representative using Union-Find.
// 4. Construct the final result by sorting and organizing emails for each account, starting with the account name, followed by all associated unique emails.

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    parent[node] = findParent(parent, parent[node]);
    return parent[node];
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        auto account = accounts[i];
        for (int j = 1; j < account.size(); j++)
        {
            string mail = account[j];
            if (mp.find(mail) != mp.end())
            {
                unionSet(i, mp[mail], parent, rank);
            }
            else
            {
                mp[mail] = i;
            }
        }
    }
    unordered_map<int, set<string>> preAns;
    for (auto it : mp)
    {
        int accountNo = it.second;
        string mail = it.first;
        accountNo = findParent(parent, accountNo);
        preAns[accountNo].insert(mail);
    }
    vector<vector<string>> ans;
    for (auto it : preAns)
    {
        int accountNo = it.first;
        auto st = it.second;
        vector<string> v;
        v.push_back(accounts[accountNo][0]);
        for (auto mail : st)
        {
            v.push_back(mail);
        }
        ans.push_back(v);
    }
    return ans;
}