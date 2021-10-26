/*
Edit Distance
Medium

116

5

Add to favorites
Asked In:
GOOGLE
LINKEDIN
MICROSOFT
AMAZON
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
*/


int Solution::minDistance(string A, string B) {
    int row = A.size();
    int col = B.size();
    vector<vector<int>> dp(row+1,vector<int>(col+1));
    for(int i = 0; i <= row; i++){
        for(int j = 0; j <= col; j++){
            if(i == 0){
                dp[i][j] = j;
            } else if(j == 0){
                dp[i][j] = i;
            } else{
                if(A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
            }
        }
    }
    return dp[row][col];
}
