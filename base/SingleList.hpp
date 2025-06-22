#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP

#include <stdexcept>

template <typename T>
struct Node {
  T data;
  Node* next;
};

template <typename T>
using ptr_node = Node<T>*;

template <typename T>
using List = ptr_node<T>;

template <typename T>
class LinkedList {
  private:
    List<T> head;

  public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
      while (head) {
        ptr_node<T> temp = head;
        head = head->next;
        delete temp;
      }
      head = nullptr;
    }

  protected:
    ptr_node<T> create_node(T data) {
      ptr_node<T> new_node = new Node<T>;
      new_node->data = data;
      new_node->next = nullptr;
      return new_node;
    }

    void insert_e(ptr_node<T> new_node) {
      if (head == nullptr) {
        head = new_node;
        return;
      }

      ptr_node<T> current = head;
      while (current->next) {
        current = current->next;
      }
      current->next = new_node;
    }

    T delete_e() {
      if (!head)
        throw std::domain_error("List is empty");

      if (!head->next) {
        T temp = head->data;
        delete head;
        head = nullptr;
        return temp;
      }

      ptr_node<T> current = head;
      while (current->next->next) {
        current = current->next;
      }

      T temp = current->next->data;
      delete current->next;
      current->next = nullptr;
      return temp;
    }

    void insert_f(ptr_node<T> new_node) {
      new_node->next = head;
      head = new_node;
    }

    T delete_f() {
      if (!head)
        throw std::domain_error("List is empty");

      ptr_node<T> temp = head;
      T temp_val = temp->data;
      head = temp->next;
      delete temp;
      return temp_val;
    }

    int get_size() const {
      int count = 0;
      ptr_node<T> current = head;
      while (current) {
        count++;
        current = current->next;
      }
      return count;
    }

    bool is_empty() {
      return head == nullptr;
    }

    ptr_node<T> get_head() {
      return this->head;
    }
};

#endif
