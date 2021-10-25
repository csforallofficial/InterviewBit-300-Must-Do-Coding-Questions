/*
Largest Rectangle in Histogram
Hard

141

2

Add to favorites
Asked In:
GOOGLE
FACEBOOK
AMAZON
Problem Description

Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000000



Input Format
The only argument given is the integer array A.



Output Format
Return the area of largest rectangle in the histogram.



Example Input
Input 1:

 A = [2, 1, 5, 6, 2, 3]
Input 2:

 A = [2]


Example Output
Output 1:

 10
Output 2:

 2


Example Explanation
Explanation 1:

The largest rectangle has area = 10 unit. Formed by A[3] to A[4].
Explanation 2:

Largest rectangle has area 2.
*/


int Solution::largestRectangleArea(vector<int> &A) {
    int rb[A.size()];
    stack<int> st;
    st.push(A.size()-1);
    rb[A.size()-1] = A.size();
    for(int i = A.size()-2; i >= 0; i--){
        while(st.size() > 0 && A[i] <= A[st.top()])
            st.pop();
        if(!st.size())
            rb[i] = A.size();
        else
            rb[i] = st.top();
        st.push(i);
    }

    int lb[A.size()];
    stack<int> s;
    s.push(0);
    lb[0] = -1;
    for(int i = 1; i < A.size(); i++){
        while(s.size() > 0 && A[i] <= A[s.top()])
            s.pop();
        if(!s.size())
            lb[i] = -1;
        else
            lb[i] = s.top();
        s.push(i);
    }

    int area = 1, maxi = 0, width;
    for(int i = 0; i < A.size(); i++){
        width = rb[i] - lb[i] - 1;
        area = width*A[i];
        if(area>maxi)
            maxi = area;
    }
    return maxi;
}
