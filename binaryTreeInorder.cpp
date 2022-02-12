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
 
//// recursion
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &result)
    {
        if (root != NULL)
        {
           inorder(root->left, result);
           result.push_back(root->val);
           inorder(root->right, result);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};


//// stack iteration
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        while(root != nullptr || !stk.empty())
        {
            while (root!= nullptr)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            result.push_back(root->val);
            root = root->right;
            stk.pop();
        }
        return result;
    }
};


////Morris inorder
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* predecessor;
        while(root != nullptr)
        {
            predecessor = root->left;
            if( predecessor != nullptr)
            {
                while(predecessor->right != nullptr && predecessor->right != root)
                    predecessor = predecessor->right;
                
                if(predecessor->right == nullptr)
                {
                    predecessor->right = root;
                    root = root->left;
                }
                else
                {
                    result.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            else
            {
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};