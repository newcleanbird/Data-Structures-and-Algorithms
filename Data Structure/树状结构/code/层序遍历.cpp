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
    层序遍历：广度优先算法
        使用队列，将每层的子树都加入队列，记录每层的个数，每层遍历时，依次出队，将节点的左子树与右子树加入队列，然后将遍历结果加入输出数组。


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; // 二维数组存储结果
        queue<TreeNode*> que;             // 队列用来存储每层的结点
        if(root != nullptr)
        {
            que.push(root); // 将根节点放入队列中
        }
        else
        {
            return result;
        }
        while(!que.empty()) // 队列为空，则遍历结束
        {
            int size= que.size(); // 每层的数量
            vector<int> vec;
            while(size--) // 每层遍历size个节点
            {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left)
                {
                    que.push(node->left);
                }
                if(node->right)
                {
                    que.push(node->right);
                }
            }
            result.push_back(vec); // 每一层循环完，把arr放入结果数组
        }
        return result;

    }
};


/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
*/