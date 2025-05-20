#include<iostream>
using namespace std;

// INTEGER TO ENGLISH WORDS (LEETCODE 273)
// USING RECURSION - TC=O(LOG10(N)), SC=O(N)

// Steps:
// 1. Initialize a vector of pairs `mp` containing number-to-word mappings in descending order of magnitude.
// 2. If `num` is 0, return "Zero".
// 3. Iterate through the map to find the largest key `it.first` less than or equal to `num`.
// 4. Divide `num` by `it.first` to get the corresponding word representation and recursively call `numberToWords` for the quotient.
// 5. Append the word representation of `it.first` to the result.
// 6. If there's a remainder (`num % it.first`), recursively call `numberToWords` for the remainder and append the result.
// 7. Combine and return the final result.

vector<pair<int, string>> mp = {{1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

string numberToWords(int num)
{
    if (num == 0)
    {
        return "Zero";
    }
    for (auto it : mp)
    {
        if (num >= it.first)
        {
            string a = "";
            if (num >= 100)
            {
                a = numberToWords(num / it.first) + " ";
            }
            string b = it.second;
            string c = "";
            if (num % it.first != 0)
            {
                c = " " + numberToWords(num % it.first);
            }
            return a + b + c;
        }
    }
    return "";
}