// Victor Guerra <vguerra@gmail.com>
// Implementation of a dynamic array.

#include <cstddef>
#include <algorithm>

class dynamic_array {
  public:
  static const std::size_t npos = -1;
    
  dynamic_array() = default;
  dynamic_array(std::size_t size) : size_(size) , array_(new int[size]) {};
  ~dynamic_array() = default;

  std::size_t search(int value) const;
  void insert(int value);
  void remove(std::size_t pos);

  std::size_t size() const { return last_ + 1; }
  std::size_t capacity() const { return size_; }

  private:
  std::size_t last_ = 0;
  std::size_t size_ = 0;
  int* array_ = nullptr; 
};

