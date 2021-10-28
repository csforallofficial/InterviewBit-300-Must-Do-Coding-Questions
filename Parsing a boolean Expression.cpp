/*
Parsing A Boolean Expression
Hard

486

29

Add to List

Share
Return the result of evaluating a given boolean expression, represented as a string.

An expression can either be:

"t", evaluating to True;
"f", evaluating to False;
"!(expr)", evaluating to the logical NOT of the inner expression expr;
"&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions expr1, expr2, ...;
"|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions expr1, expr2, ...
 

Example 1:

Input: expression = "!(f)"
Output: true
Example 2:

Input: expression = "|(f,t)"
Output: true
Example 3:

Input: expression = "&(t,f)"
Output: false
Example 4:

Input: expression = "|(&(t,f,t),!(t))"
Output: false
 

Constraints:

1 <= expression.length <= 20000
expression[i] consists of characters in {'(', ')', '&', '|', '!', 't', 'f', ','}.
expression is a valid expression representing a boolean, as given in the description.
*/


class Solution {
public:
    bool parseBoolExpr(string e) {
        stack<char> st;
        for(auto ch:e){
            if(ch==')'){
                bool hasT = false, hasF = false;
                while(st.top()=='f' || st.top()=='t'){
                    hasT |= st.top() == 't';
                    hasF |= st.top() == 'f';
                    st.pop();
                }
                auto op = st.top();
                st.pop();
                st.push(op=='!'?hasF?'t':'f':op=='&'?!hasF?'t':'f':hasT?'t':'f');
            } else if(ch!='(' && ch!=','){
                st.push(ch);
            }
        }
        return st.top()=='t'?true:false;
    }
};
