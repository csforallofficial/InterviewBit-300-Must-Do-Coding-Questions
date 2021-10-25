/*
Palindrome Partitioning II
Hard

2715

70

Add to List

Share
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lower-case English letters only.
*/


class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size()));
        for(int g = 0; g < s.size(); g++){
            for(int i = 0, j = g; j < dp.size(); i++, j++){
                if(g==0){
                    dp[i][j] = true;
                } else if(g==1){
                    if(s[i]==s[j])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                } else{
                    if(s[i]==s[j] && dp[i+1][j-1]==true)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
            }
        }
        vector<int> dpf(s.size());
        dpf[0] = 0;
        for(int j = 1; j < s.size(); j++){
            if(dp[0][j])
                dpf[j] = 0;
            else{
                int mini = INT_MAX;
                for(int i = j; i>=1; i--){
                    if(dp[i][j]){
                        if(dpf[i-1]<mini)
                            mini = dpf[i-1];
                }
            }
            dpf[j] = mini+1;    
            }
            
        }
        return dpf[s.size()-1];
    }
};
