#include <iostream>
#include <vector>
#include <memory> // 用于智能指针

class TreeNode {
public:
    int data;                   // 节点的数据
    std::vector<std::shared_ptr<TreeNode>> children; // 存储子节点的智能指针向量

    // 构造函数
    TreeNode(int value) : data(value) {}

    // 递归前序遍历
    void preorderTraversal() const {
        std::cout << data << " ";
        for (const auto& child : children) {
            child->preorderTraversal();
        }
    }

    // 递归中序遍历
    /*
    注意此处的中序遍历指：第一个子节点->根->其他子节点
    */
    void inorderTraversal() const {
        if (children.empty()) {
            std::cout << data << " ";
        }
        else {
            children.front()->inorderTraversal();   // 先遍历第一个孩子
            std::cout << data << " ";   // 然后遍历根节点
            if (children.size() > 1) {  // 然后依次遍历其他孩子
                for (int i = 1; i < children.size(); i++)
                {
                    children[i]->inorderTraversal();
                }
            }
        }
    }

    // 递归后序遍历
    void postorderTraversal() const {
        for (const auto& child : children) {
            child->postorderTraversal();
        }
        std::cout << data << " ";
    }
};

// 示例：创建一个树并进行遍历
void createAndTraverseTree() {
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>(1); // 创建根节点
    std::shared_ptr<TreeNode> child1 = std::make_shared<TreeNode>(2); // 创建子节点
    std::shared_ptr<TreeNode> child2 = std::make_shared<TreeNode>(3);
    std::shared_ptr<TreeNode> grandChild = std::make_shared<TreeNode>(4); // 创建孙子节点

    root->children.push_back(child1); // 添加子节点到根节点
    root->children.push_back(child2);
    child1->children.push_back(grandChild); // 添加孙子节点到子节点

    std::cout << "Preorder Traversal:" << std::endl;
    root->preorderTraversal();
    std::cout << std::endl;

    std::cout << "Inorder Traversal:" << std::endl;
    root->inorderTraversal();
    std::cout << std::endl;

    std::cout << "Postorder Traversal:" << std::endl;
    root->postorderTraversal();
    std::cout << std::endl;
}

int main() {
    createAndTraverseTree();
    return 0;
}