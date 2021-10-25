/*
Maximum Size Square Sub-matrix
Medium

38

1

Add to favorites
Asked In:
FLIPKART
Problem Description

Given a 2D binary matrix A of size  N x M  find the area of maximum size square sub-matrix with all 1's.



Problem Constraints
1 <= N, M <= 103

 A[i][j] = 1 or A[i][j] = 0



Input Format
First argument is an 2D matrix A of size N x M.



Output Format
Output the area of maximum size square sub-matrix in A with all 1's.



Example Input
Input 1:

 A = [

        [0, 1, 1, 0, 1],

        [1, 1, 0, 1, 0],

        [0, 1, 1, 1, 0],

        [1, 1, 1, 1, 0],

        [1, 1, 1, 1, 1],

        [0, 0, 0, 0, 0]
     ]
Input 2:

 A = [

       [1, 1],
       [1, 1]
     ]


Example Output
Output 1:

 9
Output 2:

 4


Example Explanation
Explanation 1:

  Consider the below binary matrix.
 
 The area of the square is 3 * 3 = 9
Explanation 2:

 The given matrix is the largest size square possible so area will be 2 * 2 = 4
*/


int Solution::solve(vector<vector<int> > &A) {
    int maxi = 0;
    vector<vector<int>> dp(A.size(),vector<int>(A[0].size()));
    for(int i = dp.size()-1; i >= 0; i--){
        for(int j = dp[0].size()-1; j >= 0; j--){
            if(i == dp.size()-1 && j == dp[0].size()-1){
                dp[i][j] = A[i][j];
            } else if(i == dp.size()-1){
                dp[i][j] = A[i][j];
            } else if(j == dp[0].size()-1){
                dp[i][j] = A[i][j];
            } else{
                if(A[i][j] == 0)
                    dp[i][j] = 0;
                else{
                    int mini = min(dp[i][j+1],dp[i+1][j+1]);
                    mini = min(mini,dp[i+1][j]);
                    dp[i][j] = mini + 1;
                }
            }
            if(dp[i][j]>maxi)
                maxi = dp[i][j];
        }
    }
    return maxi*maxi;
}
