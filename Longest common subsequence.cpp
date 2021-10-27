/*
Longest Common Subsequence
Easy

106

3

Add to favorites
Asked In:
AJIO
Problem Description

Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.



Problem Constraints
1 <= |A|, |B| <= 1005



Input Format
First argument is an string A.

Second argument is an string B.



Output Format
Return the length of such longest common subsequence between string A and string B.



Example Input
Input 1:

 A = "abbcdgf"
 B = "bbadcgf"


Example Output
Output 1:

 5


Example Explanation
Explanation 1:

 The longest common subsequence is "bbcgf", which has a length of 5
*/


int Solution::solve(string A, string B) {
    int row = A.size();
    int col = B.size();
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
                char uc = B[j];
                if(lc==uc){
                    dp[i][j] = dp[i+1][j+1] + 1;
                } else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
    }
    return dp[0][0];
}
