#include "ADT/Stack.hpp"
#include "base/BinaryTree.hpp"
#include <iostream>
#include <cctype>
#include <string>

int priority(char c) {
  if (c == '^') return 3;
  if (c == '*' || c == '/') return 2;
  return 1; // '+' atau '-'
}

bool is_operator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

std::string get_postfix(std::string infix) {
  Stack<char> stack;
  std::string result = "";

  for (char c : infix) {
    if (std::isalnum(c)) {
      result += c;
    } else if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      while (!stack.is_stack_empty() && stack.top()->data != '(') {
        result += stack.pop();
      }
      if (!stack.is_stack_empty() && stack.top()->data == '(') stack.pop();
    } else if (is_operator(c)) {
      while (!stack.is_stack_empty() && is_operator(stack.top()->data) &&
             priority(c) <= priority(stack.top()->data)) {
        result += stack.pop();
      }
      stack.push(c);
    }
  }

  while (!stack.is_stack_empty()) {
    char data = stack.pop();
    if (data != '(' && data != ')')
      result += data;
  }

  return result;
}

// ********************************************************************
// ***************************** TREE *********************************
// ********************************************************************
namespace tree {
  ptr_tree<char> build(std::string expr) {
    Stack<ptr_tree<char>> stack;
    BinaryTree<char> b_tree;

    for (char e: expr) {
      if (std::isalnum(e)) {
        stack.push(b_tree.create_node(e));
      } else if (is_operator(e)) {
        ptr_tree<char> right_child = stack.pop(); // element pertama yang di pop
        ptr_tree<char> left_child = stack.pop(); // element kedua yang di pop
        ptr_tree<char> parent = b_tree.create_node(e); // buat node sbg parent ketika `e` adalah operator
        parent->right = right_child; parent->left = left_child;
        stack.push(parent);
      }
    }

    return stack.pop();
  }

  void prefix(ptr_tree<char> &root) { // pre order traversal
    if (root != nullptr) {
      std::cout << root->data;
      prefix(root->left);
      prefix(root->right);
    }
  }

  void infix(ptr_tree<char> &root) { // in order traversal
    if (root != nullptr) {
      infix(root->left);
      std::cout << root->data;
      infix(root->right);
    }
  }

  void postfix(ptr_tree<char> &root) { // post order traversal
    if (root != nullptr) {
      postfix(root->left);
      postfix(root->right);
      std::cout << root->data;
    }
  }
}

int main() {
  return 0;
}
