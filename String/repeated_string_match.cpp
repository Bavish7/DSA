#include<iostream>
using namespace std;

// REPEATED STRING MATCH (LEETCODE 686)
// USING STRING MATCHING - TC=O(N*M), SC=O(M)

// Steps:
// 1. Initialize `ans = 1` and `tmp = a`.  
// 2. Repeatedly append `a` to itself until its size is at least `b.size()`, updating `ans` accordingly.  
// 3. Check if `b` is a substring of the current `a` using a helper function `check()`.  
// 4. If `b` is found, return `ans`.  
// 5. Append `a` once more and check again. If found, return `ans + 1`.  
// 6. If `b` is still not found, return `-1`.

bool check(string &a, string &b)
{
    int m = a.size();
    int n = b.size();

    for (int i = 0; i <= m - n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (a[i + j] != b[j])
                break;
        }
        if (j == n)
            return true;
    }
    return false;
}

int repeatedStringMatch(string a, string b)
{
    int m = a.size();
    int n = b.size();

    int ans = 1;
    string tmp = a;
    while (a.size() < b.size())
    {
        a += tmp;
        ans++;
    }

    if (check(a, b))
    {
        return ans;
    }
    a += tmp;
    if (check(a, b))
    {
        return ans + 1;
    }
    return -1;
}

// USING RABIN KARP ALGORITHM - TC=O(M+N), SC=O(M)
// Steps:
// 1. Compute the hash value of string `B` using polynomial rolling hash.  
// 2. Precompute prefix hash values and powers of `p` for `A`.  
// 3. Use a sliding window approach to compare hash values for substrings of `A` with `B`.  
// 4. If a match is found, return `1`. Otherwise, continue checking by appending `A` until its size exceeds `B`.  
// 5. Append `A` iteratively and check again using Rabin-Karp.  
// 6. If `B` is found as a substring, return the count of `A` used.  
// 7. If `B` is still not found, return `-1`.

int Rabin_Karp(string s1, string s2)
{
    long long m = s1.size();
    long long n = s2.size();
    long long p = 31;
    long long pow = 1;
    long long mod = 1e9 + 7;
    long long targetHashVal = 0;
    for (long long i = 0; i < n; i++)
    {
        targetHashVal = (targetHashVal + (s2[i] - 'a' + 1) * pow) % mod;
        pow = (pow * p) % mod;
    }
    vector<long long> pha(m);
    vector<long long> pa(m);
    pha[0] = s1[0] - 'a' + 1;
    pa[0] = 1;
    pow = p;
    for (long long i = 1; i < m; i++)
    {
        pha[i] = (pha[i - 1] + (s1[i] - 'a' + 1) * pow) % mod;
        pa[i] = pow;
        pow = (pow * p) % mod;
    }
    long long sp = 0, ep = n - 1;
    while (ep < m)
    {
        long long win = pha[ep];
        if (sp > 0)
            win = (win - pha[sp - 1] + mod) % mod;
        if (win == (targetHashVal * pa[sp]) % mod)
        {
            return 1;
        }
        sp++, ep++;
    }
    return 0;
}
int repeatedStringMatch(string A, string B)
{
    if (A == B)
        return 1;
    int count = 1;
    string source = A;
    while (source.size() < B.size())
    {
        source += A;
        count++;
    }
    if (source == B)
        return count;

    if (Rabin_Karp(source, B) == 1)
        return count;

    if (Rabin_Karp(source + A, B) == 1)
        return count + 1;
    return -1;
}

// USING KMP ALGORITHM - TC=O(M+N), SC=O(M)
// Steps:
// 1. Construct the LPS (Longest Prefix Suffix) array for pattern `B` to enable efficient string matching.  
// 2. Use the KMP algorithm to search for `B` in `A`, leveraging the LPS array to skip unnecessary comparisons.  
// 3. Append `A` iteratively to `source` until its size is at least `B`'s size.  
// 4. If `B` matches `source`, return the count of `A` used.  
// 5. If `B` is not found, append `A` one more time and recheck using KMP.  
// 6. If `B` is still not found, return `-1`.  

int KMP_search(string s, string p)
{
    int m = s.size();
    int n = p.size();
    vector<int> lps(n, 0);
    int len = 0, i = 1;
    while (i < n)
    {
        if (p[len] == p[i])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) 
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    i = 0;
    int j = 0;
    while (i < m and j < n)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
            if (j == n)
            { 
                return true;
            }
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return false;
}
int repeatedStringMatch(string A, string B)
{
    if (A == B)
        return 1;
    int count = 1;
    string source = A;
    while (source.size() < B.size())
    {
        source += A;
        count++;
    }
    if (source == B)
        return count;
    if (KMP_search(source, B) == 1)
        return count;
    if (KMP_search(source + A, B) == 1)
        return count + 1;
    return -1;
}