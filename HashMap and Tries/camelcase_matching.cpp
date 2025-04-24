#include<iostream>
using namespace std;

// CAMELCASE MATCHING (LEETCODE 1023)
// USING TRIE - TC=O(N*L), SC=O(L)

// Steps:
// 1. Define a TrieNode class to represent each node in the trie with 58 children (to account for both uppercase and lowercase letters).
// 2. Initialize each node's children to NULL and set a boolean flag 'isTerminal' to mark the end of a word.
// 3. In the insertWord function, recursively insert each character of the word into the trie. Calculate the index based on 'A' for uppercase letters and store the word into the trie structure.
// 4. In the searchWord function, recursively search through the trie to match the pattern. If the character in the query is lowercase, skip it in the search.
//    - If the character is uppercase, search it in the trie based on its index. If no matching character is found, return false.
//    - If the entire pattern is matched, return true when the terminal node is reached.
// 5. In the camelMatch function, create a Trie object, insert the pattern into it, and for each query, use the search function to check if it matches the pattern.
// 6. Return a vector of booleans indicating whether each query matches the pattern.

class TrieNode
{
public:
    char value;
    TrieNode *children[58];
    bool isTerminal;
    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 58; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};
void insertWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'A';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    insertWord(child, word.substr(1));
}
bool searchWord(TrieNode *root, string &word, int i)
{
    if (i >= word.length())
    {
        return root->isTerminal;
    }
    char ch = word[i];
    int index = ch - 'A';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
        return searchWord(child, word, i + 1);
    }
    else if (islower(word[i]))
    {
        return searchWord(root, word, i + 1);
    }
    else
    {
        return false;
    }
}
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insert(string word)
    {
        insertWord(root, word);
    }
    bool search(string word)
    {
        return searchWord(root, word, 0);
    }
};
class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> ans;
        Trie t;
        t.insert(pattern);
        for (auto query : queries)
        {
            ans.push_back(t.search(query));
        }
        return ans;
    }
};