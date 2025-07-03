#include<iostream>
using namespace std;

// TEXT JUSTIFICATION (LEETCODE 68)
// USING GREEDY APPROACH - TC=O(N*MAXWIDTH), SC=O(N*MAXWIDTH)

// Steps:
// 1. Initialize an empty `currWords` list and `currLen` to track current line's word lengths.
// 2. Iterate over each word:
//    - If adding the word (plus gaps between words) exceeds maxWidth:
//       a. Compute total spaces needed = maxWidth - currLen.
//       b. If only one word, left-justify by appending all spaces to that word.
//       c. Otherwise, distribute spaces evenly between words.
//           - `allSpaces` = minimum spaces per gap.
//           - `extraSpaces` = leftover spaces to be distributed starting from the left.
//       d. Build the line and push it to `ans`.
//       e. Clear `currWords` and reset `currLen`.
//    - Add word to `currWords` and update `currLen`.
// 3. After the loop, handle the last line:
//    - Join words with a single space between them.
//    - Left-pad with remaining spaces at the end to meet maxWidth.
// 4. Return the fully justified lines stored in `ans`.

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n=words.size();
    vector<string>ans, currWords;
    int currLen=0;
    for(string &word: words){
        if(currLen+word.size()+currWords.size()>maxWidth){
            int spaces=maxWidth-currLen;
            int gaps=currWords.size()-1;
            if(gaps==0){
                ans.push_back(currWords[0]+string(spaces,' '));
            }
            else{
                int allSpaces=spaces/gaps;
                int extraSpaces=spaces%gaps;
                string temp="";
                for(int i=0;i<currWords.size();i++){
                    temp+=currWords[i];
                    if(i<gaps){
                        temp+=string(allSpaces,' ');
                        if(i<extraSpaces){
                            temp+=" ";
                        }
                    }
                }
                ans.push_back(temp);
            }
            currWords.clear();
            currLen=0;
        }
        currWords.push_back(word);
        currLen+=word.size();
    }
    string lastLine="";
    for(string &word:currWords){
        if(!lastLine.empty()){
            lastLine+=" ";
        }
        lastLine+=word;
    }
    lastLine+=string(maxWidth-lastLine.size(),' ');
    ans.push_back(lastLine);
    return ans;
}