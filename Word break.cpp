/*
Word Break II
Hard

3925

455

Add to List

Share
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 

Constraints:

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/


class Solution {
public:
    vector<string> solve(string s, string ans, vector<string>& res, unordered_set<string> st){
        if(s.length()==0){
            res.push_back(ans);
            return res;
        }
        for(int i = 0; i < s.size(); i++){
            string left = s.substr(0,i+1);
            if(st.find(left)!=st.end()){
                string right = s.substr(i+1,s.size()-i);
                solve(right,ans+left+" ",res,st);
            }
        }
        return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto it:wordDict)
            st.insert(it);
        vector<string> res;
        string ans = "";
        vector<string> answer;
        vector<string> fin;
        answer = solve(s,ans,res,st);
        for(auto it:answer){
            it.resize(it.size() - 1);
            fin.push_back(it);
        }
        return fin;
    }
};
