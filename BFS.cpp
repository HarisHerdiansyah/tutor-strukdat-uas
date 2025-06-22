#include "ADT/Queue.hpp"
#include "ADT/BinarySearchTree.hpp"
#include "base/Array.hpp"
#include <iostream>

void bfs(ptr_tree<int> &root) {
  Queue<ptr_tree<int>> ptr_queue;
  ptr_queue.enqueue(root);
  while (!ptr_queue.is_queue_empty()) {
    ptr_tree<int> ptr = ptr_queue.dequeue();
    std::cout << ptr->data << " "; // misal prosedur yang ingin kita lakukan adalah print
    if (ptr->left) ptr_queue.enqueue(ptr->left);
    if (ptr->right) ptr_queue.enqueue(ptr->right);
  }
}

int main() {
  Array<int> data_tree;
  data_tree.push_back(7);
  data_tree.push_back(6);
  data_tree.push_back(10);
  data_tree.push_back(2);
  data_tree.push_back(13);
  data_tree.push_back(1);
  data_tree.push_back(5);
  data_tree.push_back(16);

  BST<int> bst;
  ptr_tree<int> root = bst.get_root();

  for (int i = 0; i < data_tree.get_size(); i++) {
    bst.insert(root, data_tree.get(i));
  }
  bfs(root);
  return 0;
}