/*
Longest Palindromic Subsequence
Medium

76

3

Add to favorites
Asked In:
LINKEDIN
Problem Description

Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.

NOTE:

Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.


Problem Constraints
 1 <= |A| <= 1005



Input Format
First and only argument is an string A.



Output Format
Return a integer denoting the length of longest palindromic subsequence in A.



Example Input
Input 1:

 A = "bebeeed"


Example Output
Output 1:

 4


Example Explanation
Explanation 1:

 The longest common pallindromic subsequence is "eeee", which has a length of 4
*/


int Solution::solve(string A) {
    int n = A.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g==0){
                dp[i][j] = 1;
            } else if(g==1){
                if(A[i]==A[j])
                    dp[i][j] = 2;
                else
                    dp[i][j] = 1;
            } else{
                if(A[i]==A[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    return dp[0][n-1];
}
