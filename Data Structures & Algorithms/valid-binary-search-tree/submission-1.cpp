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
    bool isValidBST(TreeNode* root) {
        return fun(root, INT_MAX, INT_MIN);
    }

    bool fun(TreeNode* root, int max, int min){
        if (root == nullptr){
            return true;
        }

        if (root->val >= max || root->val <= min){
            return false;
        }

        bool l = true, r = true;
        if (root->left != nullptr){
            l = root->val > root->left->val;
        }
        if (root->right != nullptr){
            r = root->val < root->right->val;
        }
        if (l && r){
            return (fun(root->left, root->val, min) && fun(root->right, max, root->val));
        }
        return false;
    }
};
