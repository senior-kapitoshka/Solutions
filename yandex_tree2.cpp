#include <iostream>
#include <vector>

class TreeNode {
private:
    int value;
    TreeNode* root = nullptr;
    std::vector<TreeNode*> children;

public:
    TreeNode(int val): value(val) {
    }

    TreeNode(const TreeNode&) = delete;
    TreeNode& operator=(const TreeNode&) = delete;

    TreeNode* AddChild(int child_value) {
        auto node = new TreeNode(child_value);
        node->root = this;
        children.push_back(node);
        return node;
    }

    void Print(int depth = 0) const {
        for (int i = 0; i < depth; ++i) {
            std::cout << " ";
        }
        std::cout << "- " << value << "\n";
        for (const auto& child : children) {
            child->Print(depth + 1);
        }
    }
// утекает память. В этом легко убедиться: узлы дерева создаются с помощью new, но нигде не удаляются.

//Самым простым решением было бы дописать деструктор в конце класса:

~TreeNode() {
    for (TreeNode* child : children) {
        delete child;
    }
}

};

///////////////////////////
#include <iostream>
#include <vector>
#include <memory>

class TreeNode {
private:
    int value;
    TreeNode* root = nullptr;
    std::vector<std::unique_ptr<TreeNode>> children;

public:
    TreeNode(int val): value(val) {
    }

    TreeNode(const TreeNode&) = delete;
    TreeNode& operator=(const TreeNode&) = delete;

    TreeNode* AddChild(int child_value) {
   //создавать сразу в векторе!     
        children.push_back(std::make_unique<TreeNode>(child_value));
   //привязывать указатель на конец вектора!     
        children.back()->root = this;
//возвращается raw ptr с помощью метода get!!
    
        return children.back().get();
    }

    void Print(int depth = 0) const {
        for (int i = 0; i < depth; ++i) {
            std::cout << " ";
        }
        std::cout << "- " << value << "\n";
        for (const auto& child : children) {
            child->Print(depth + 1);
        }
    }
};

