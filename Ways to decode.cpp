/*
Ways to Decode
Medium

42

12

Add to favorites
Asked In:
FACEBOOK
AMAZON
Problem Description

A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.



Problem Constraints
1 <= |A| <= 105



Input Format
The first and the only argument is a string A.



Output Format
Return a single integer denoting the total number of ways to decode it modulo 109 + 7.



Example Input
Input 1:

 A = "8"
Input 2:

 A = "12"


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 Given encoded message "8", it could be decoded as only "H" (8).
 The number of ways decoding "8" is 1.
Explanation 2:

 Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).
 The number of ways decoding "12" is 2.
*/


const int mod = 1000000007;
int Solution::numDecodings(string A) {
    vector<int> dp(A.size());
    if(A[0]!='0')
        dp[0] = 1;
    else
        dp[0] = 0;
    for(int i = 1; i < A.size(); i++){
        if(A[i-1]=='0' && A[i]=='0'){
            dp[i] = 0;
        } else if(A[i-1]=='0' && A[i]!='0'){
            dp[i] = dp[i-1]%mod;
        } else if(A[i-1]!='0' && A[i]=='0'){
            if(A[i-1]=='1' || A[i-1]=='2'){
                dp[i] = (i>2?dp[i-2]:1)%mod;
            } else
                dp[i] = 0;
        } else{
            if(stoll(A.substr(i-1,2))<=26){
                dp[i] = dp[i-1]%mod + (i>2?dp[i-2]:1)%mod;
            }
            else
                dp[i] = dp[i-1]%mod;
        }
    }
    return dp[A.size()-1]%mod;
}
