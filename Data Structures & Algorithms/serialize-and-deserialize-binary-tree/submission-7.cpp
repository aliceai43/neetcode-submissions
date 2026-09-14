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

class Codec {
public:

    int i = 0;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return encodeToString(root);
    }

    string encodeToString(TreeNode* root){
        if (root == nullptr) return "n";
        return intToStr(root->val)+encodeToString(root->left)+encodeToString(root->right);
    }

    int strToint(const string& st){
        int len = st[i]-48;
        int ans = stoi(st.substr(i+1, len));
        i += len;
        return ans;
    }

    string intToStr(int k){
        int len = 0;
        string s = "";
        while(k > 0){
            len++;
            s = to_string(k%10) + s;
            k /= 10;
        }
        return to_string(len) + s;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[0] == 'n') return nullptr;
        i = 0;
        int num = strToint(data);
        TreeNode* root = new TreeNode(num);
        i++;
        root->left = toTree(data);
        root->right = toTree(data);
        return root;
    }
    TreeNode* toTree(const string& s){

        if (i >= s.length() || s[i] == 'n') {
            i++; 
            return nullptr;
        }
        int num = strToint(s);
        TreeNode* cur = new TreeNode(num);
        i++;
        cur -> left = toTree(s);
        cur -> right = toTree(s);
        return cur;
    }
    
};
