/*
Word Break
Medium

38

6

Add to favorites
Asked In:
IBM
GOOGLE
Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence of one or more dictionary words.

Input Format:

The first argument is a string, A.
The second argument is an array of strings, B.
Output Format:

Return 0 / 1 ( 0 for false, 1 for true ) for this problem.
Constraints:

1 <= len(A) <= 6500
1 <= len(B) <= 10000
1 <= len(B[i]) <= 20
Examples:

Input 1:
    A = "myinterviewtrainer",
    B = ["trainer", "my", "interview"]

Output 1:
    1

Explanation 1:
    Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".
    
Input 2:
    A = "a"
    B = ["aaa"]

Output 2:
    0

Explanation 2:
    Return 0 ( corresponding to false ) because "a" cannot be segmented as "aaa".
*/


class Solution {
public:
    int dp[301];
    int helper(int i, string A, unordered_set<string>& B){
        if(i==A.size())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        string temp;
        for(int j = i; j < A.size(); j++){
            temp += A[j];
            if(B.find(temp)!=B.end()){
                if(helper(j+1,A,B)) return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        unordered_set<string> st;
        for(auto it:wordDict)
            st.insert(it);
        return helper(0,s,st);
    }
};
