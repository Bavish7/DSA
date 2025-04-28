#include<iostream>
using namespace std;

// REPLACE WORDS (LEETCODE 648)
// USING TRIES - TC=O(N+M), SC=O(M)

// Steps:
// 1. Define a TrieNode class to represent each node of the Trie, storing a character, children pointers, and terminal status.
// 2. Implement insertWord function to recursively insert words into the Trie.
// 3. Implement searchWord function to find a prefix in the Trie, returning the length of the match if found.
// 4. Implement startsWith function to check if a prefix exists in the Trie.
// 5. In the Trie class, use the above methods to handle insertion and search operations.
// 6. In the Solution class, initialize a Trie and insert all dictionary words.
// 7. Split the sentence into words, search each word in the Trie, and replace it with the root if found.
// 8. Return the updated sentence with the replaced words.

class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
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
    int index = ch - 'a';
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
bool searchWord(TrieNode *root, string &word, int &i)
{
    if (root->isTerminal)
        return true;
    if (i >= word.length())
    {
        return root->isTerminal;
    }
    char ch = word[i++];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }
    bool ans = searchWord(child, word, i);
    return ans;
}
bool startFunc(TrieNode *root, string word, int i)
{
    if (i >= word.size())
    {
        return true;
    }
    int index = word[i] - 'a';
    if (root->children[index])
    {
        return startFunc(root->children[index], word, i + 1);
    }
    return false;
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
    int search(string word)
    {
        int i = 0;
        bool gotWord = searchWord(root, word, i);
        return gotWord ? i : -1;
    }
    bool startsWith(string prefix)
    {
        return startFunc(root, prefix, 0);
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        string ans;
        Trie t;
        for (auto root : dictionary)
        {
            t.insert(root);
        }
        int start = 0, end = 0, n = sentence.size();
        while (end < n)
        {
            if (sentence[end] == ' ' || end == n - 1)
            {
                int len = end == n - 1 ? n : end - start;
                string word = sentence.substr(start, len);
                int trieMatchIndex = t.search(word);
                ans += trieMatchIndex != -1 ? word.substr(0, trieMatchIndex) : word;
                if (sentence[end] == ' ')
                {
                    ans += " ";
                }
                start = end + 1;
            }
            end++;
        }
        return ans;
    }
};