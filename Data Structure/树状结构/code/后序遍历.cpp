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

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 

// 后序遍历(前序改)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root == nullptr)
        {
            return result;
        }
        else
        {
            st.push(root);
        }
        while(!st.empty())
        {
            TreeNode* node = st.top();
            result.push_back(node->val);
            st.pop();
            if(node->left)
            {
                st.push(node->left);
            }
            if(node->right)
            {
                st.push(node->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

