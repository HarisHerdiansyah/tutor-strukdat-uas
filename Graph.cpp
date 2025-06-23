#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

namespace adjacency_matrix {
  template <typename T>
  using Array = std::vector<T>;

  template <typename T>
  using Matrix = std::vector<Array<T>>;

  void insert_edge(Matrix<int> &adj, int from, int to) {
  int currentSize = adj.size();
  int largest = std::max(from, to);

  if (largest >= currentSize) {
    adj.resize(largest + 1);
    for (Array<int> &adjMember: adj) {
      adjMember.resize(largest + 1, 0);
    }
  }

    adj[from][to] = adj[to][from] = 1;
  }

  void delete_edge(Matrix<int> &adj, int from, int to) {
    adj[from][to] = adj[to][from] = 0;
  }

  void printAdjMtx(Matrix<int> &adj) {
    int size = adj.size();

    std::cout << "   ";
    for (int i = 0; i < size; i++) {
      std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "   ";
    for (int i = 0; i < size; i++) {
      std::cout << "-" << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < size; i++) {
      std::cout << i << "| ";
      for (int j = 0; j < size; j++) {
        std::cout << adj[i][j] << " ";
      }
      std::cout << "\n";
    }
  }
}

namespace adjacency_list {
  void insert_edge(std::map<int, std::set<int>> &adj, int from, int to) {
    adj[from].insert(to);
    adj[to].insert(from);
  }

  void delete_edge(std::map<int, std::set<int>> &adj, int from, int to) {
    if (adj.find(from) != adj.end()) {
      adj[from].erase(to);
    }
    if (adj.find(to) != adj.end()) {
      adj[to].erase(from);
    }
  }

  void delete_vertex(std::map<int, std::set<int>> &adj, int vertex) {
    for (auto &pair: adj) {
      pair.second.erase(vertex);
    }
    adj.erase(vertex);
  }

  void print_adjacency_list(const std::map<int, std::set<int>> &adj) {
    for (const auto &pair : adj) {
      std::cout << pair.first << ": ";
      for (const int neighbor : pair.second) {
        std::cout << neighbor << " ";
      }
      std::cout << '\n';
    }
  }

  void bfs(const std::map<int, std::set<int>> &adj) {
    std::set<int> visited;
    std::vector<int> qv;
    qv.push_back(1);
    visited.insert(1);

    while (!qv.empty()) {
      int front = qv.front();
      qv.erase(qv.begin());

      auto it = adj.find(front);
      if (it != adj.end()) {
        for (const auto &edge: it->second) {
          if (visited.count(edge)) continue;
          qv.push_back(edge);
          visited.insert(edge);
        }
      }
    }
  }

  void dfs(const std::map<int, std::set<int>> &adj) {
    std::set<int> visited;
    std::vector<int> stack;
    stack.push_back(1);
    visited.insert(1);

    while (!stack.empty()) {
      int top = stack.back();
      stack.pop_back();

      auto it = adj.find(top);
      if (it != adj.end()) {
        for (const auto &edge: it->second) {
          if (visited.count(edge)) continue;
          stack.push_back(edge);
          visited.insert(edge);
        }
      }
    }
  }
}

int main() {
  std::map<int, std::set<int>> graph;
  adjacency_list::insert_edge(graph, 1, 2);
  adjacency_list::insert_edge(graph, 1, 3);
  adjacency_list::insert_edge(graph, 1, 4);
  adjacency_list::insert_edge(graph, 2, 4);
  adjacency_list::insert_edge(graph, 2, 5);
  adjacency_list::insert_edge(graph, 3, 6);
  adjacency_list::insert_edge(graph, 5, 7);
  std::cout << "Adjacency List:\n";
  adjacency_list::dfs(graph);
  return 0;
}