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
 
 
////recursion
class Solution {
public:
    bool check(TreeNode* L, TreeNode* R)
    {
        if (!L && !R)
            return true;
        if (L==nullptr || R==nullptr)
            return false;
        
        return L->val == R->val
               && check(L->left, R->right)
               && check(L->right, R->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};


//// queue iteration
class Solution {
public:
    bool check(TreeNode* L, TreeNode* R)
    {
        queue<TreeNode*> q;
        q.push(L); 
        q.push(R);
        while (!q.empty())
        {
            L = q.front(); q.pop();
            R = q.front(); q.pop();
            if (!L && !R) 
                continue;
            if (!L || !R || L->val != R->val) 
                return false;

            q.push(L->left);
            q.push(R->right);

            q.push(L->right);
            q.push(R->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};