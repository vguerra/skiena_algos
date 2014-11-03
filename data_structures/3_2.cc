//Victor Guerra <vguerra@gmail.com>
//20141102

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>

struct List {
  ~List() {
    // Iterate over the nodes and delete them
    while (head_) {
      Node *tmp = head_;
      head_ = head_->next_;
      delete tmp;
    }
  }

  void insert_front(int val) {
    Node *new_head = new Node(val, head_);
    head_ = new_head; 
    ++size_;
  }

  void delete_front() {
    if (head_ != nullptr) {
      Node *tmp = head_;
      head_ = head_->next_;
      delete tmp;
      --size_;
    }
  }

  void reverse() {
    std::queue<int> q{};
    while (size()) {
      q.push(head_->data_);
      delete_front();
    }
    while (q.size()) {
      insert_front(q.front());
      q.pop();
    }
  }

  void reverse_inplace() {
    Node *p1 = nullptr;
    Node *p2 = head_;
    
    while (p2 != nullptr) {
      Node *tmp = p2->next_;
      p2->next_ = p1;
      p1 = p2;
      p2 = tmp;
    }
    head_ = p1;
  }

  void print() {
    Node *runner = head_;
    while (runner) {
      std::cout << runner->data_ << " -> ";
      runner = runner->next_;
    }
    std::cout << " null\n";
  }

  std::size_t size() {
    return size_;
  }
  
  private:
    struct Node {
      Node(int val, Node *next) : data_(val), next_(next) {}
      int data_;
      struct Node *next_ = nullptr;
    };
    std::size_t size_ = 0;
    struct Node *head_ = nullptr;
};

int main() {
  List l1;
  int num; 
  while (std::cin >> num) {
    l1.insert_front(num);
  }
  l1.print();
  l1.reverse();
  l1.print();
  l1.reverse_inplace();
  l1.print();

  return EXIT_SUCCESS; 
}
