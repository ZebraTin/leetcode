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
    int maxD = 0;
    int depth(TreeNode* root){
        if (root == nullptr) return 0;

        int L = depth(root->left);
        int R = depth(root->right);

        maxD = max(L+R, maxD);
        return max(L,R)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxD;

    }
};