/*
94. 二叉树的中序遍历

*/


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

/*
思路；
    中序遍历：
        遍历顺序：左->根->右
        节点处理：
            如果当前节点不为空，则当前节点入栈，去访问左节点。
            如果当前节点为空，则回退到栈顶结点(即上一个结点)，将当前结点值放入遍历结果，当前结点出栈，去访问右节点。
        中止条件：
            栈为空，遍历结点也为空


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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(!st.empty() || cur != nullptr) // 栈为空且cur指针也为空，则结束遍历循环
        // 保证栈不为空，或者访问结点不为空。即结束标志为：栈为空且cur指针也为空，则结束遍历循环!(st.empty && cur == nullptr)
        {
            if(cur != nullptr) // 如果不为空，则去访问左节点
            {
                st.push(cur);
                cur = cur->left;
            }
            else // 如果当前访问节点为空
            {
                cur = st.top(); // 则访问回退到栈顶节点
                result.push_back(cur->val);
                st.pop();
                cur = cur->right;
            }
        }
        return result;
    }
};