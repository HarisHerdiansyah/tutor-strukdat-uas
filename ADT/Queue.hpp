#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../base/SingleList.hpp"

template <typename T>
class Queue: protected LinkedList<T> {
  public:
    void enqueue(T value) {
      this->insert_e(this->create_node(value));
    }

    T dequeue() {
      return this->delete_f();
    }

    bool is_queue_empty() {
      return this->is_empty();
    }
};

#endif