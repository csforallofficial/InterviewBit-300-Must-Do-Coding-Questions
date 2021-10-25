/*
Max Rectangle in Binary Matrix
Medium

54

2

Add to favorites
Asked In:
GOOGLE
MICROSOFT
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

*/


int largestRectangleArea(vector<int>& heights) {
    int rb[heights.size()];
    stack<int> st;
    rb[heights.size()-1] = heights.size();
    st.push(heights.size()-1);
    for(int i = heights.size()-2; i >= 0; i--){
        while(st.size()>0 && heights[i] <= heights[st.top()])
            st.pop();
        if(!st.size())
            rb[i] = heights.size();
        else
            rb[i] = st.top();
        st.push(i);
    }
        
    int lb[heights.size()];
    stack<int> s;
    lb[0] = -1;
    s.push(0);
    for(int i = 1; i < heights.size(); i++){
        while(s.size()>0 && heights[i] <= heights[s.top()])
            s.pop();
        if(!s.size())
            lb[i] = -1;
        else 
            lb[i] = s.top();
        s.push(i);
    }
        
    int width, area = 1, maxi = 0;
    for(int i = 0; i <= heights.size()-1; i++){
        width = rb[i]-lb[i]-1;
        area = width*heights[i];
        if(area > maxi)
            maxi = area;
    }
    return maxi;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    if(A.size()==0 || A.front().empty())
        return 0;
    vector<int> currow;
    for(int i = 0; i < A[0].size(); i++)
        currow.push_back(A[0][i]);
    int maxi = largestRectangleArea(currow);
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); j++){
            if(A[i][j] == 1)
                currow[j] += 1;
            else
                currow[j] = 0;
        }
        maxi = max(maxi,largestRectangleArea(currow));
    }
    return maxi;
}
