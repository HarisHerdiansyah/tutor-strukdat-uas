#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "../base/BinaryTree.hpp"

template <typename T>
class BST: public BinaryTree<T> {
  public:
    void insert(ptr_tree<T> &root, T value) {
      if (root == nullptr) {
        root = this->create_node(value);
      } else if (root->data > value) {
        insert(root->left, value);
      } else if (root->data < value) {
        insert(root->right, value);
      }
    }
};

#endif