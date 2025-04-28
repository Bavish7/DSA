#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode *children[26];
        bool isTerminal;
        TrieNode(char val){
            this->value = val;
            for (int i = 0; i < 26;i++){
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};
void insertWord(TrieNode* root,string word){
    if(word.length()==0){
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    insertWord(child, word.substr(1));
}
bool searchWord(TrieNode *root, string word){
    if(word.length()==0){
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        return false;
    }
    bool ans=searchWord(child, word.substr(1));
    return ans;
}
void deleteWord(TrieNode *root,string word){
    if(word.length()==0){
        root->isTerminal = false;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        return;
    }
    deleteWord(child, word.substr(1));
}
void storeString(TrieNode *root, vector<string> &suffix, string &input,string &prefix){
    if(root->isTerminal){
        suffix.push_back(prefix+input);
    }
    for (char ch = 'a'; ch <= 'z';ch++){
        int index = ch - 'a';
        TrieNode *next = root->children[index];
        if(next!=NULL){
            input.push_back(ch);
            storeString(next, suffix, input,prefix);
            input.pop_back();
        }
    }
} 
void findPrefixString(TrieNode *root, string input, vector<string> &ans,string prefix)
{
    if(input.length()==0){
        TrieNode *lastChar = root;
        storeString(lastChar, ans, input,prefix);
        return;
    }
    char ch = input[0];
    int index = ch - 'a';
    TrieNode *child;
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        return;
    }
    findPrefixString(child, input.substr(1), ans,prefix);
}
int main(){
    TrieNode *root = new TrieNode('-');
    insertWord(root,"bavish");
    insertWord(root, "care");
    insertWord(root, "code");
    insertWord(root, "codehelp");
    insertWord(root, "dove");
    insertWord(root, "dovey");
    insertWord(root, "love");
    insertWord(root, "lovely");
    insertWord(root, "super");

    // bool search=searchWord(root, "bavish");
    // cout << search << endl;

    // deleteWord(root, "bavish");

    // search = searchWord(root, "bavish");
    // cout << search << endl;

    string input = "co";
    string prefix = "co";
    vector<string> ans;
    findPrefixString(root, input, ans,prefix);
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
}