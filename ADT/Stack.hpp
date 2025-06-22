#ifndef STACK_HPP
#define STACK_HPP

#include "../base/SingleList.hpp"

template <typename T>
class Stack: protected LinkedList<T> {
  public:
    void push(T value) {
      this->insert_f(this->create_node(value));
    }

    T pop() {
      return this->delete_f();
    }

    int size() {
      return this->get_size();
    }

    bool is_stack_empty() {
      return this->is_empty();
    }

    ptr_node<T> top() {
      return this->get_head();
    }
};

#endif
