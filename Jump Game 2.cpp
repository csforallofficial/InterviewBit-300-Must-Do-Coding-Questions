/*
Jump Game II
Medium

6130

228

Add to List

Share
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
*/

//DP - O(N^2) Approach

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            if(nums[i]==0)
                continue;
            else{
                int mini = INT_MAX;
                for(int j = 1; j <= nums[i] && (i+j)<n; j++){
                    if(nums[i+j]==0 && (i+j)!=n-1)
                        continue;
                    else
                        mini = min(mini,dp[i+j]);
                }
                if(mini!=INT_MAX)
                    dp[i] = mini+1;
                else
                    nums[i] = 0;
            }
        }
        return dp[0];
    }
};


//Greedy Approch - O(N)


class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, res = 0, flag = 0;
        while(r < nums.size()-1){
            int farthest = 0;
            for(int i = l; i <= r; i++)
                farthest = max(farthest,i+nums[i]);
            l = r+1;
            r = farthest;
            if(l>r){
                flag = 1;
                break;
            }
            res += 1;
        }
        if(flag == 1)
            return -1;
        else
            return res;
    }
};
