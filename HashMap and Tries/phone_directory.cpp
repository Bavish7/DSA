#include<iostream>
using namespace std;

// IMPLEMENT A PHONE DIRECTORY 
// USING TRIE - TC=O(N*(S^2)), SC=O(N*S), S=AVG LENGTH OF STRING

// Steps:
// 1. Create a Trie Root Node:
//    - Initialize a root node for the Trie with a dummy character.
// 2. Insert All Contacts into the Trie:
//    - For each contact in the contact list, insert the word into the Trie character by character.
//    - If a character node already exists, move to the next character; otherwise, create a new node.
//    - Mark the end of a word by setting the isTerminal flag.
// 3. Get Suggestions for Each Prefix of the Query String:
//    - Traverse the Trie based on the query string character by character.
//    - For each character in the query string, collect all words that start with the current prefix by performing a depth-first search (DFS) from the current node.
//    - If a node corresponding to a character in the query string does not exist, break the loop as no further suggestions can be made.

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
void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
{
    if (curr->isTerminal)
    {
        temp.push_back(prefix);
    }
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        TrieNode *next = curr->children[ch - 'a'];
        if (next != NULL)
        {
            prefix.push_back(ch);
            printSuggestions(next, temp, prefix);
            prefix.pop_back();
        }
    }
}
vector<vector<string>> getSuggestions(TrieNode *root, string &queryStr)
{
    TrieNode *prev = root;
    TrieNode *curr;
    vector<vector<string>> output;
    string prefix = "";
    for (int i = 0; i < queryStr.length(); i++)
    {
        char lastChar = queryStr[i];
        prefix.push_back(lastChar);
        int index = lastChar - 'a';
        curr = prev->children[index];
        if (curr == NULL)
        {
            break;
        }
        vector<string> temp;
        printSuggestions(curr, temp, prefix);
        output.push_back(temp);
        temp.clear();
        prev = curr;
    }
    return output;
}
vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    TrieNode *root = new TrieNode('-');
    for (int i = 0; i < contactList.size(); i++)
    {
        insertWord(root, contactList[i]);
    }
    return getSuggestions(root, queryStr);
}