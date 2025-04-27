#include<iostream>
using namespace std;

// PALINDROME PAIRS (LEETCODE 336)
// USING TRIE - TC=O(N*K^2), SC=O(N*K)

// Steps:
// 1. Define a TrieNode class to represent each node of the Trie, storing a character, children pointers, terminal status, and the index of the word that ends at this node.
// 2. Implement insertWord function to insert the reverse of each word into the Trie, storing the word's index at the terminal node.
// 3. Implement isPalindrome function to check if a substring is a palindrome, used to identify valid palindrome pairs.
// 4. Implement searchCase2 function to handle searching for potential palindrome pairs by checking remaining Trie nodes for possible palindrome completions.
// 5. Implement search function*to traverse the Trie while checking if the remaining portion of the word is a palindrome, recording valid palindrome pairs when found.
// 6. In the Trie class, insert each word's reverse into the Trie and perform the palindrome pair search by checking if the word itself, or its suffix, matches with any reversed word already in the Trie.
// 7. In the Solution class, iterate through each word in the input list, inserting the reversed word into the Trie and searching for matching palindrome pairs.
// 8. For each valid pair found during the search, add the indices of the two words (original and matched) to the result list, avoiding pairs of the same word.
// 9. Return the final list of palindrome pairs.

class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    int stringNumber;
    bool isTerminal;

    TrieNode(char val)
    {
        this->value = val;
        this->stringNumber = -1;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode *root, const string &word, int stringNumber, int index = 0)
{
    if (index == word.length())
    {
        root->stringNumber = stringNumber;
        root->isTerminal = true;
        return;
    }

    char ch = word[index];
    int childIndex = ch - 'a';

    if (root->children[childIndex] == NULL)
    {
        root->children[childIndex] = new TrieNode(ch);
    }

    insertWord(root->children[childIndex], word, stringNumber, index + 1);
}

bool searchWord(TrieNode *root, const string &word, int index)
{
    if (root->isTerminal)
        return true;

    if (index >= word.length())
    {
        return root->isTerminal;
    }

    char ch = word[index];
    int childIndex = ch - 'a';

    if (root->children[childIndex] == NULL)
    {
        return false;
    }

    return searchWord(root->children[childIndex], word, index + 1);
}

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(const string &word, int stringNumber)
    {
        insertWord(root, word, stringNumber);
    }

    bool isPalindrome(const string &s, int low, int high)
    {
        while (low < high)
        {
            if (s[low] != s[high])
            {
                return false;
            }
            low++, high--;
        }
        return true;
    }

    void searchCase2(TrieNode *root, vector<int> &myPalindrome, const string &s)
    {
        if (root->stringNumber != -1 && isPalindrome(s, 0, s.size() - 1))
        {
            myPalindrome.push_back(root->stringNumber);
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                searchCase2(root->children[i], myPalindrome, s + char(i + 'a'));
            }
        }
    }

    void search(const string &word, vector<int> &myPalindrome)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';

            if (curr->stringNumber != -1 && isPalindrome(word, i, word.size() - 1))
            {
                myPalindrome.push_back(curr->stringNumber);
            }

            if (curr->children[index])
            {
                curr = curr->children[index];
            }
            else
            {
                return;
            }
        }

        searchCase2(curr, myPalindrome, "");
    }
};

class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> ans;
        Trie t;

        for (int i = 0; i < words.size(); i++)
        {
            string reverseWord = words[i];
            reverse(reverseWord.begin(), reverseWord.end());
            t.insert(reverseWord, i);
        }

        for (int i = 0; i < words.size(); i++)
        {
            vector<int> myPalindrome;
            t.search(words[i], myPalindrome);

            for (auto it : myPalindrome)
            {
                if (it != i)
                {
                    ans.push_back({i, it});
                }
            }
        }

        return ans;
    }
};
