#include<iostream>
using namespace std;

// COMPLETE STRING 
// USING PREFIX TRIE - TC=O(N*L), SC=O(L)

// Steps:
// 1. Define `TrieNode` class with a `children` array for 26 lowercase alphabets and a `isTerminal` flag to mark end-of-word nodes.
// 2. `insert(word, root)`: 
//    - Traverse each character of the word.  
//    - Create new nodes as needed and mark the terminal node for each complete word.
// 3. `compareString(word, root)`:
//    - Check if every prefix of the word is a complete word in the Trie. Return `false` if any prefix is missing or incomplete.
// 4. `completeString(n, a)`:
//    - Insert all words into the Trie.
//    - Traverse the words and check if they qualify as complete strings using `compareString()`
//    - Track the lexicographically smallest word with the longest length as the answer.

class TrieNode
{
public:
    TrieNode *children[26];
    bool isTerminal;
};
void insert(string &word, TrieNode *root)
{
    TrieNode *node = root;
    for (char ch : word)
    {
        int index = ch - 'a';
        if (node->children[index] == NULL)
        {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isTerminal = true;
}
bool compareString(string &word, TrieNode *root)
{
    TrieNode *node = root;
    for (char ch : word)
    {
        int index = ch - 'a';
        if (node->children[index] == NULL)
            return false;
        node = node->children[index];
        if (node->isTerminal == false)
            return false;
    }
    return true;
}
string completeString(int n, vector<string> &a)
{
    TrieNode *root = new TrieNode();
    for (auto word : a)
    {
        insert(word, root);
    }
    string ans = "";
    for (auto word : a)
    {
        if (compareString(word, root))
        {
            if (ans.length() <= word.length())
            {
                ans = ans.length() == word.length() ? min(ans, word) : word;
            }
        }
    }
    return ans.length() == 0 ? "None" : ans;
}