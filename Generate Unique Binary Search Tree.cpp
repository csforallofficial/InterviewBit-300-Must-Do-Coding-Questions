/*
Unique Binary Search Trees
Easy

24

28

Add to favorites
Asked In:
AMAZON
TWITTER
Given A, generate all structurally unique BST’s (binary search trees) that store values 1…A.

Input Format:

The first and the only argument of input contains the integer, A.
Output Format:

Return a list of tree nodes representing the generated BST's.
Constraints:

1 <= A <= 15
Example:

Input 1:
    A = 3

Output 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode*> generateTree(int st, int end){
    if(st>end){
        vector<TreeNode*> ans;
        ans.push_back(NULL);
        return ans;
    }
    vector<TreeNode*> ans;
    for(int i = st; i <= end; i++){
        vector<TreeNode*> l = generateTree(st,i-1);
        vector<TreeNode*> r = generateTree(i+1,end);
        for(int j = 0; j < l.size(); j++){
            for(int k = 0; k < r.size(); k++){
                TreeNode* res = new TreeNode(i);
                res->left = l[j];
                res->right = r[k];
                ans.push_back(res);
            }
        }
    }
    return ans;
}
vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return generateTree(1,A);
}
