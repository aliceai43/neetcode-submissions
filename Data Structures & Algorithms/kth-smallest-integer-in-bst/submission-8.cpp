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

// left -> right DFS
class Solution {
public:
    int ans = 0;
    bool found = false;
    int kthSmallest(TreeNode* root, int k) {
        find(root, 0, k);
        return ans;
    }

    int find(TreeNode* root, int count, int k){


        if (root -> left != nullptr){
            count = find(root -> left, count, k); // add left
        }

        count += 1; // count me 

        if (count == k) ans = root -> val;

        if (root -> right != nullptr){
            count = find(root -> right, count, k); // add right
        }

        return count;
    } 

};
