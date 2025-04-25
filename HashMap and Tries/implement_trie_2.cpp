#include<iostream>
using namespace std;

// IMPLEMENT TRIE II
// USING PREFIX TRIE - TC=O(N), SC=O(N)

// Steps:
// 1. Create a TrieNode class with `cw` to store complete word counts, `pw` for prefix counts, and a children array for 26 alphabets.
// 2. Implement the `Trie` class containing:
//    - `insert(word)`: Traverse each character, create nodes if necessary, and update `pw` for prefixes and `cw` for completed words.
//    - `countWordsEqualTo(word)`: Traverse nodes and return `cw` if the word exists; otherwise, return 0.
//    - `countWordsStartingWith(prefix)`: Traverse nodes and return `pw` for the prefix path.
//    - `erase(word)`: Traverse and decrement prefix counts, then decrease the complete word count at the last node.

class TriNode
{
public:
    int cw, pw;
    TriNode *children[26];
    TriNode()
    {
        cw = 0;
        pw = 0;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};
class Trie
{
public:
    TriNode *root;
    Trie()
    {
        root = new TriNode();
    }
    void insert(string &word)
    {
        TriNode *node = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == NULL)
            {
                node->children[index] = new TriNode();
            }
            node = node->children[index];
            node->pw += 1;
        }
        node->cw += 1;
    }
    int countWordsEqualTo(string &word)
    {
        TriNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (node->children[index] == NULL)
            {
                return 0;
            }
            node = node->children[index];
        }
        return node->cw;
    }
    int countWordsStartingWith(string &word)
    {
        TriNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (node->children[index] == NULL)
            {
                return 0;
            }
            node = node->children[index];
        }
        return node->pw;
    }
    void erase(string &word)
    {
        TriNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (node->children[index] == NULL)
            {
                return;
            }
            node = node->children[index];
            node->pw -= 1;
        }
        node->cw -= 1;
    }
};