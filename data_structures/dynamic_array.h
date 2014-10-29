// Victor Guerra <vguerra@gmail.com>
// Implementation of a dynamic array.

#include <cstddef>
#include <algorithm>

class dynamic_array {
  public:
  using reference = int&;
  using const_reference = const int&;
  static const std::size_t npos = -1;

  dynamic_array() = default;
  dynamic_array(std::size_t size) : size_(size), array_(new int[size]){};
  ~dynamic_array() = default;

  std::size_t search(int value) const;
  void insert(int value);
  void remove(std::size_t pos);

  std::size_t size() const { return last_; }
  std::size_t capacity() const { return size_; }

  reference operator[](std::size_t index) { return array_[index]; }
  const_reference operator[](std::size_t index) const { return array_[index]; }

  private:
  std::size_t last_ = 0;
  std::size_t size_ = 0;
  int* array_ = nullptr;
};
