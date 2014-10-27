// Victor Guerra <vguerra@gmail.com>
// Implementation of a dynamic array. 

#include <algorithm>
#include <array>

class dynamic_array {
  public: 
    dynamic_array() = default;
    ~dynamic_array() = default;

  private:
    std::array<int, 1> array_;
};
