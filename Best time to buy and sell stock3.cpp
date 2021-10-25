/*
Best Time to Buy and Sell Stocks III
Hard

56

6

Add to favorites
Asked In:
AMAZON
FACEBOOK
Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most 2 transactions.

Return the maximum possible profit.

Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).



Input Format:

The first and the only argument is an integer array, A.
Output Format:

Return an integer, representing the maximum possible profit.
Constraints:

1 <= length(A) <= 7e5
1 <= A[i] <= 1e7
Examples:

Input 1:
    A = [1, 2, 1, 2]

Output 1:
    2

Explanation 1: 
    Day 0 : Buy 
    Day 1 : Sell
    Day 2 : Buy
    Day 3 : Sell

Input 2:
    A = [7, 2, 4, 8, 7]

Output 2:
    6

Explanation 2:
    Day 1 : Buy
    Day 3 : Sell
*/


int Solution::maxProfit(const vector<int> &A) {
    if(A.size()==0)
        return 0;
    int least = A[0], pre_pro = 0;
    vector<int> dpl(A.size());
    for(int i = 1; i < A.size(); i++){
        if(A[i]<least)
            least = A[i];
        pre_pro = A[i] - least;
        if(pre_pro>dpl[i-1])
            dpl[i] = pre_pro;
        else
            dpl[i] = dpl[i-1];
    }
    int maxi = A[A.size()-1], post_pro = 0;
    vector<int> dpr(A.size());
    for(int i = A.size()-2; i >= 0; i--){
        if(A[i]>maxi)
            maxi = A[i];
        post_pro = maxi-A[i];
        if(post_pro>dpr[i+1])
            dpr[i] = post_pro;
        else
            dpr[i] = dpr[i+1];
    }
    int op = 0;
    for(int i = 0; i < A.size(); i++){
        op = max(op, dpl[i]+dpr[i]);
    }
    return op;
}
