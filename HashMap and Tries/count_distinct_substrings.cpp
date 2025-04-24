#include<iostream>
using namespace std;

// COUNT DISTINCT SUBSTRINGS
// USING PREFIX TRIE - TC=O(N^2), SC=O(N^2)

// Steps:
// 1. Define `TrieNode` class containing an array of 26 pointers initialized to NULL for children nodes.
// 2. Create a `Trie` class with a root node:
//    - `insert(str)`: Traverse each character of the string.  
//      - For each character, create a new node if it doesn't exist and count it as a new node.  
//      - Return the count of newly created nodes.
// 3. `countDistinctSubstrings(s)`:
//    - For each suffix starting at index `i`, insert it into the Trie and count the new nodes.
//    - Add 1 to the final count to account for the empty substring.

class TrieNode
{
public:
    TrieNode *children[26];
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    int insert(string &str)
    {
        int newNode = 0;
        TrieNode *node = root;
        for (char ch : str)
        {
            int idx = ch - 'a';
            if (node->children[idx] == NULL)
            {
                node->children[idx] = new TrieNode();
                newNode++;
            }
            node = node->children[idx];
        }
        return newNode;
    }
};
int countDistinctSubstrings(string &s)
{
    Trie trie;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        string suffix = s.substr(i);
        count += trie.insert(suffix);
    }
    return count + 1;
}