// Victor Guerra <vguerra@gmail.com>
// 20141020

// Selection Sort 

#include <cstdint>
#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
#include <iterator>
#include <utility>

using vec_t = std::vector<std::int32_t>;

void selection_sort(vec_t&);

void selection_sort(vec_t& vec) {
  if (vec.empty()) return;
  using it_t = vec_t::iterator;
  for (it_t runner = std::begin(vec); runner != std::prev(std::end(vec)); ++runner) {
    it_t min_it = min_element(std::next(runner), std::end(vec));
    if (*min_it < *runner) {
      std::cout << "swaping : " << *runner << ", " << *min_it << "\n";
      std::iter_swap(runner, min_it);
    }
  }
}

int main() {
  std::size_t nums;
  std::cin >> nums;
  vec_t vec(nums);
  std::random_device rd; 
  std::mt19937 g(rd());

  std::iota(std::begin(vec), std::end(vec), 0);
  std::shuffle(std::begin(vec), std::end(vec), g);

  std::cout << "shuffle: \n";
  std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<std::int32_t>(std::cout, " "));
  std::cout << "\n";

  selection_sort(vec);

  std::cout << "selection sorted: \n";
  std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<std::int32_t>(std::cout, " "));
  std::cout << "\n";
  
  vec_t vec1(0);

  selection_sort(vec1);


  return EXIT_SUCCESS;
}
