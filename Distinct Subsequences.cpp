/*
Distinct Subsequences
Medium

113

4

Add to favorites
Asked In:
GOOGLE
Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= length(A), length(B) <= 700
Example :

Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1

Explanation 1:
    Both the strings are equal.

Input 2:
    A = "rabbbit" 
    B = "rabbit"

Output 2:
    3

Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"
        
    Note: "_" marks the removed character.
*/


#define ll long long int
const ll n = 7e2+3;
ll dp[n][n];
int go(string &A, string &B, ll i, ll j){
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i == 0 && j == 0)
        return 1;
    if(i == 0)
        return 0;
    if(j == 0)
        return 1;
    if(A[i-1]!=B[j-1]){
        return dp[i][j] = go(A,B,i-1,j);
    } else{
        return dp[i][j] = go(A,B,i-1,j-1) + go(A,B,i-1,j);
    }
}
int Solution::numDistinct(string A, string B) {
    if(A==B)
        return 1;
    else{
        memset(dp,-1,sizeof(dp));
        return go(A,B,A.size(),B.size());
    }
}
