/*
Repeating Sub-Sequence
Medium

96

69

Add to favorites
Asked In:
GOOGLE
Problem Description

Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,

i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

NOTE: Sub-sequence length should be greater than or equal to 2.



Problem Constraints
 1 <= |A| <= 100



Input Format
The first and the only argument of input contains a string A.



Output Format
Return an integer, 0 or 1:

    => 0 : False
    => 1 : True


Example Input
Input 1:

 A = "abab"
Input 2:

 A = "abba"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 "ab" is repeated.
Explanation 2:

 There is no repeating subsequence.
*/


int Solution::anytwo(string A) {
    int row = A.size();
    int col = A.size();
    vector<vector<int>> dp(row+1,vector<int>(col+1));
    for(int i = row; i >= 0; i--){
        for(int j = col; j >= 0; j--){
            if(i==row && j==col){
                dp[i][j] = 0;
            } else if(i==row){
                dp[i][j] = 0;
            } else if(j==col){
                dp[i][j] = 0;
            } else{
                char lc = A[i];
                char uc = A[j];
                if(lc==uc){
                    if(i==j){
                        dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                    } else{
                        dp[i][j] = dp[i+1][j+1] + 1;
                    }
                } else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
    }
    if(dp[0][0] >= 2)
        return 1;
    else
        return 0;
}
