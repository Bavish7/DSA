#include<iostream>
using namespace std;

// REMOVE SUB-FOLDERS FROM THE FILE SYSTEM (LEETCODE 1233)
// USING UNORDERED SET AND STRING PARSING - TC=O(N*L), SC=O(N*L)

// Steps:
// 1. Insert all folder paths into an unordered_set for O(1) lookup.
// 2. For each folder, iterate backward and check if any prefix ending with '/' exists in the set.
//    - If yes, it's a subfolder → remove it from the set.
// 3. Finally, collect and return all remaining folders from the set.

vector<string> removeSubfolders(vector<string> &folder)
{
    unordered_set<string> st;
    for (string file : folder)
    {
        st.insert(file);
    }
    for (string file : folder)
    {
        int lastSlash = 0;
        for (int i = file.size() - 1; i >= 0; i--)
        {
            if (file[i] == '/')
            {
                lastSlash = i;
                if (st.find(file.substr(0, lastSlash)) != st.end())
                {
                    st.erase(file);
                    break;
                }
            }
        }
    }
    vector<string> ans;
    for (auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}

// USING SORTING AND STRING COMPARISON - TC=O(N*LOGN+N*L), SC=O(N*L)
// Steps:
// 1. Sort all folder paths lexicographically so subfolders come right after parent folders.
// 2. Initialize result with the first folder.
// 3. For each folder, check if it starts with the last added folder + '/'.
//    - If not, it's not a subfolder → add it to result.
// 4. Return the list of top-level folders.

vector<string> removeSubfolders(vector<string> &folder)
{
    sort(folder.begin(), folder.end());
    vector<string> ans;
    ans.push_back(folder[0]);
    string prev = "";
    for (int i = 1; i < folder.size(); i++)
    {
        string currFolder = folder[i];
        string lastFolder = ans.back();
        lastFolder += '/';
        if (currFolder.find(lastFolder) != 0)
        {
            ans.push_back(currFolder);
        }
    }
    return ans;
}