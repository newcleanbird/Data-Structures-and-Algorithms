#include <iostream>
#include <vector>
#include <stack>

// 树节点类，采用孩子-兄弟表示法
class TreeNode {
public:
    int data;                   // 节点数据
    TreeNode* firstChild;        // 指向第一个子节点的指针
    TreeNode* nextSibling;       // 指向下一个兄弟节点的指针

    TreeNode(int val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}

    // 前序遍历
    void PreOrderTraversal() const {
        std::cout << data << " ";
        TreeNode* currentChild = firstChild;
        while (currentChild) {
            currentChild->PreOrderTraversal();
            currentChild = currentChild->nextSibling;
        }
    }

    //后序遍历孩子兄弟树
    void PostOrderTraverse() {
        TreeNode* currentChild = firstChild;
        while (currentChild) {
            currentChild->PostOrderTraverse();
            currentChild = currentChild->nextSibling;
        }
        std::cout << data << " ";
    }
};

// 示例：创建一个树并进行遍历
void createAndTraverseTree(TreeNode*& root) {
    root = new TreeNode(1);
    TreeNode* child1 = new TreeNode(2);
    TreeNode* child2 = new TreeNode(3);
    TreeNode* grandChild = new TreeNode(4);

    root->firstChild = child1;
    child1->nextSibling = child2;
    child1->firstChild = grandChild;
}

int main() {
    TreeNode* root = nullptr;
    createAndTraverseTree(root);

    std::cout << "Preorder Traversal:" << std::endl;
    root->PreOrderTraversal();
    std::cout << std::endl;

    std::cout << "Postorder Traversal:" << std::endl;
    root->PostOrderTraverse();
    std::cout << std::endl;

    // 注意：实际应用中应考虑内存释放
    delete root; // 简单示例中手动释放根节点，实际应用中应设计完整的内存管理策略

    return 0;
}