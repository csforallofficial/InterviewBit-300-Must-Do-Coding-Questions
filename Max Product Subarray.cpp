/*
Max Product Subarray
Medium

98

1

Add to favorites
Asked In:
AMAZON
LINKEDIN
MICROSOFT
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]
*/


int Solution::maxProduct(const vector<int> &A) {
    int prod = 1;
    int maxi = INT_MIN;
    for(int i = 0; i < A.size(); i++){
        prod *= A[i];
        maxi = max(maxi,prod);
        if(prod==0)
            prod = 1;
    }
    prod = 1;
    for(int i = A.size()-1; i >= 0; i--){
        prod *= A[i];
        maxi = max(maxi,prod);
        if(prod==0)
            prod = 1;
    }
    return maxi;
}
