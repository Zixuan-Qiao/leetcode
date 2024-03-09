/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) {
            return result;
        }
        
        stack<struct TreeNode*> stk;
        struct TreeNode *curr = root;
        while(1) {
            if(curr->left) {
                stk.push(curr);
                curr = curr->left;
            } else {
                result.push_back(curr->val);
                if(curr->right) {
                    curr = curr->right;
                } else if(stk.empty()){
                    return result;
                } else {
                    curr = stk.top();
                    stk.pop();
                    curr->left = NULL;
                }
            }
        }
        return result;
    }
};