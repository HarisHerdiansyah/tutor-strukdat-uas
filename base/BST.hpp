#ifndef BST_HPP
#define BST_HPP

template <typename T>
struct Node {
  T data;
  Node* left;
  Node* right;
};

template <typename T>
using ptr_tree = Node<T>*;

template <typename T>
using RootTree = ptr_tree<T>;

template <typename T>
class BST {
  private:
    RootTree<T> root;
  
  public:
    BST() {
      root = nullptr;
    }

    ~BST() {}

    void pre_order() const {}
    
    void in_order() const {}

    void post_order() const {}

    void bfs() const {}
};

#endif