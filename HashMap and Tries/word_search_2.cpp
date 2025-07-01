#include<iostream>
using namespace std;

// WORD SEARCH II (LEETCODE 212)
// USING TRIE AND DFS TRAVERSAL - TC=O(M*N*4^L), SC=O(N*L+M*N)

// Steps:
// 1. Construct a Trie from the input list of words.
//    - Each node represents a character.
//    - Mark the end of each word with a terminal flag and store the full word.
// 2. Traverse the board. For each cell:
//    a. If the character is the start of any word in the Trie, start DFS from there.
//    b. Use visited matrix to avoid revisiting cells in the same path.
//    c. Move in all 4 directions (up, down, left, right).
//    d. If a Trie terminal node is reached, add the word to result and mark it as visited in Trie to avoid duplicates.
// 3. Backtrack after exploring a path (unmark visited).
// 4. Return all collected valid words from the board.

class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    bool isTerminal;
    string word;
    TrieNode(char val)
    {
        value = val;
        isTerminal = false;
        word = "";
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};
class Solution
{
public:
    void insertWord(TrieNode *root, const string &word)
    {
        TrieNode *curr = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
            {
                curr->children[index] = new TrieNode(ch);
            }
            curr = curr->children[index];
        }
        curr->isTerminal = true;
        curr->word = word;
    }
    void dfs(int i, int j, TrieNode *root, vector<vector<char>> &board, vector<string> &ans, vector<vector<bool>> &vis)
    {
        if (root->isTerminal)
        {
            ans.push_back(root->word);
            root->isTerminal = false;
        }
        int m = board.size();
        int n = board[0].size();
        vis[i][j] = true;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; ++k)
        {
            int newRow = i + dx[k];
            int newCol = j + dy[k];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !vis[newRow][newCol])
            {
                char newCh = board[newRow][newCol];
                int index = newCh - 'a';
                if (root->children[index] != nullptr)
                {
                    dfs(newRow, newCol, root->children[index], board, ans, vis);
                }
            }
        }
        vis[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = new TrieNode('\0');
        for (const string &word : words)
        {
            insertWord(root, word);
        }
        int m = board.size();
        int n = board[0].size();
        vector<string> ans;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                char ch = board[i][j];
                int index = ch - 'a';
                if (root->children[index] != nullptr)
                {
                    dfs(i, j, root->children[index], board, ans, vis);
                }
            }
        }
        return ans;
    }
};
