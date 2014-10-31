// Victor Guerra <vguerra@gmail.com>

#include "dynamic_array.h"

const std::size_t dynamic_array::npos; 

std::size_t dynamic_array::search(int value) const {
  auto array_end = array_.get() + last_;
  auto array_begin = array_.get();
  auto it = std::find(array_begin, array_end, value);
  return (it == array_end ? npos : it - array_begin);
}

void dynamic_array::insert(int value) {
  if (last_ == size_) {
    size_ *= 2;
    std::unique_ptr<int[]> tmp(new int[size_]);
    std::copy(array_.get(), array_.get() + last_, tmp.get());
    array_ = std::move(tmp);
  }
  array_[last_++] = value;
}

void dynamic_array::remove(std::size_t pos) {
  std::swap(array_[pos], array_[--last_]);
}
