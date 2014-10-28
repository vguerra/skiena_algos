// Victor Guerra <vguerra@gmail.com>

#include "dynamic_array.h"

std::size_t dynamic_array::search(int value) const {
  auto array_end = array_ + size_;
  auto it = std::find(array_, array_end, value);
  return (it == array_end ? npos : it - array_);
}

void dynamic_array::insert(int value) {
  if (last_ == size_) {
    size_ *= 2;
    int* tmp_array = new int[size_];
    std::copy(array_, array_ + last_, tmp_array);
    delete[] array_;
    array_ = tmp_array;
  }
  array_[last_++] = value;
}

void dynamic_array::remove(std::size_t pos) {
  std::swap(array_[pos], array_[last_]);
  --last_;
}
