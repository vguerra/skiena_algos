// Victor Guerra <vguerra@gmail.com>

#include "dynamic_array.h"

std::size_t dynamic_array::search(int value) const {
  auto array_end = array_ + size_;
  auto it = std::find(array_, array_end, value);
  return (it == array_end ? npos : it - array_);
}

void dynamic_array::insert(int value) {
  if (last_ > size_) {
    // do allocation and copy contents
  }
  array_[last_++] = value;
}

void dynamic_array::remove(std::size_t pos) {
  std::swap(array_[pos], array_[last_]);
  --last_;
}
