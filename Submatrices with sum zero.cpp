/*
Sub Matrices with sum Zero
Medium

45

2

Add to favorites
Asked In:
GOOGLE
Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note:  elements might be negative).

Example:

Input

-8 5  7
3  7 -8
5 -8  9
Output

2

Explanation

-8 5 7

3 7 -8

5 -8 9

-8 5 7

3 7 -8

5 -8 9
*/


int subarraySum(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == 0)
                count++;
            if(mp.find(sum)!=mp.end())
                count += mp[sum];
            mp[sum] += 1;
        }
        return count;
    }

int Solution::solve(vector<vector<int> > &A) {
    if(A.size()==0)
        return 0;
    int row = A.size();
    int col = A[0].size();
    int ans = 0;
    for(int i = 0; i < row; i++){
        vector<int> vec(col,0);
        for(int j = i; j < row; j++){
            for(int k = 0; k < col; k++){
                vec[k] += A[j][k];
            }
            ans += subarraySum(vec);
        }
    }
    return ans;
}
