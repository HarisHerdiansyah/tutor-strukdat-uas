#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

template <typename T>
struct TreeNode {
  T data;
  TreeNode* left;
  TreeNode* right;
};

template <typename T>
using ptr_tree = TreeNode<T>*;

template <typename T>
using RootTree = ptr_tree<T>;

template <typename T>
class BinaryTree {
  private:
    RootTree<T> root;
  
  public:
    BinaryTree() {
      root = nullptr;
    }

    ~BinaryTree() {}

    ptr_tree<T> create_node(T value) {
      ptr_tree<T> new_node = new TreeNode<T>;
      new_node->data = value;
      new_node->left = new_node->right = nullptr;
      return new_node;
    }

    ptr_tree<T> get_root() {
      return this->root;
    }
};

#endif