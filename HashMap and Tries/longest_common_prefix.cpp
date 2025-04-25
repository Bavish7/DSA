#include<iostream>
using namespace std;

// LONGEST COMMON PREFIX (LEETCODE 14)
// USING TRIES - TC=O(N*M), SC=O(N*M)

// Steps:
// 1. Define a TrieNode class to represent each node in the Trie.
//    - Each TrieNode contains a character value, an array of pointers to its children, a boolean indicating if it's a terminal node, and a child count.
// 2. Implement the insertWord function to insert words into the Trie.
//    - If the word is empty, mark the node as terminal.
//    - For each character in the word, find the corresponding child node or create a new one if it doesn't exist.
//    - Recursively insert the remaining substring into the Trie.
// 3. Implement the findLCP function to find the longest common prefix using the Trie.
//    - Traverse the Trie from the root.
//    - If the current node has exactly one child and is not terminal, append the child's character to the prefix and continue the traversal.
//    - If the node has more than one child or is terminal, stop the traversal.
// 4. Implement the longestCommonPrefix function to use the Trie to find the longest common prefix of the given strings.
//    - Insert each string into the Trie.
//    - Use the findLCP function to get the longest common prefix from the Trie.

class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;
    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
        this->childCount = 0;
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
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNode(ch);
        root->childCount++;
        root->children[index] = child;
    }
    insertWord(child, word.substr(1));
}
class Solution
{
public:
    void findLCP(string &ans, TrieNode *root)
    {
        if (root->isTerminal)
        {
            return;
        }
        TrieNode *child;
        if (root->childCount == 1)
        {
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                {
                    child = root->children[i];
                }
            }
            ans.push_back(child->value);
        }
        else
        {
            return;
        }
        findLCP(ans, child);
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        TrieNode *root = new TrieNode('-');
        for (int i = 0; i < strs.size(); i++)
        {
            insertWord(root, strs[i]);
        }
        string ans = "";
        string str = strs[0];
        findLCP(ans, root);
        return ans;
    }
};