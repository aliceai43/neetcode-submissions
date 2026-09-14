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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        findMax(root);
        return ans;
    }


    int findMax(TreeNode* root){
        if (root == nullptr) return 0;
        int myMax = root -> val;
        int left = max(0, findMax(root->left)), right = max(0, findMax(root->right));
        ans = max(ans, myMax+left+right);
        myMax += max(left, right);
        return myMax;
    }
    
    
};
