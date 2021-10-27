/*
Length of Longest Subsequence
Medium

83

5

Add to favorites
Asked In:
MICROSOFT
Problem Description

Given an 1D integer array A of length N, find the length of longest subsequence which is first increasing then decreasing.



Problem Constraints
0 <= N <= 3000

 -107 <= A[i] <= 107



Input Format
The first and the only argument contains an integer array A.



Output Format
Return an integer representing the answer as described in the problem statement.



Example Input
Input 1:

 A = [1, 2, 1]
Input 2:

 A = [1, 11, 2, 10, 4, 5, 2, 1]


Example Output
Output 1:

 3
Output 2:

 6


Example Explanation
Explanation 1:

 [1, 2, 1] is the longest subsequence.
Explanation 2:

 [1 2 10 4 2 1] is the longest subsequence.
*/


int Solution::longestSubsequenceLength(const vector<int> &A) {
    vector<int> dp(A.size());
    for(int i = 0; i < A.size(); i++){
        int maxi = 0;
        for(int j = 0; j < i; j++){
            if(A[j] <= A[i])
                if(dp[j] > maxi)
                    maxi = dp[j];
        }
        dp[i] = maxi+1;
    }
    vector<int> pd(A.size());
    for(int i = A.size()-1; i >= 0; i--){
        int maxii = 0;
        for(int j = A.size()-1; j > i; j--){
            if(A[i] <= A[j])
                if(dp[j] > maxii)
                    maxii = dp[j];
        }
        pd[i] = maxii+1;
    }
    int ans = 0;
    for(int i = 0; i < A.size(); i++)
        ans = max(ans,dp[i]+pd[i]-1);
    return ans;
}
