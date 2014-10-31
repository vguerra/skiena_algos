// Victor Guerra <vguerra@gmail.com>
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <numeric>
#include "dynamic_array.h"

TEST_CASE("Testing of dynamic_array", "[dynamic_array]") {
  SECTION("Default constructors") {
    dynamic_array da(2);
    CHECK(da.capacity() == 2);
    CHECK(da.size() == 0);
  }

  SECTION("Dynamic growing of dynamic_array", "[dynamic_array]") {
    dynamic_array da(2);
    da.insert(0);
    da.insert(1);
    CHECK(da.size() == 2);
    CHECK(da.capacity() == 2);

    da.insert(2);
    CHECK(da.capacity() == 4);
    CHECK(da.size() == 3);

    da.insert(3);
    CHECK(da.capacity() == 4);
    CHECK(da.size() == 4);
  }

  SECTION("Deliting elements of dynamic_array", "[dynamic_array]") {
    dynamic_array da(4);
    da.insert(0);
    da.insert(1);
    da.insert(2);
    da.insert(3);

    da.remove(1);
    CHECK(da.capacity() == 4);
    CHECK(da.size() == 3);
  }

  SECTION("Accesing elements of dynamic_array", "[dynamic_aray]") {
    dynamic_array da(3);
    std::iota(&da[0], &da[3], 0);

    CHECK(da[1] == 1);
  
    da[0] = 4;
    CHECK(da[0] == 4);
  }

  SECTION("Searching elements on dynamic_array", "[dynamic_array]") {
    dynamic_array da(10);
    for (auto i : {0, 1, 2, 3, 4, 5, 6, 7, 8}) {
      da.insert(i);
    }
    CHECK(da.search(0) == 0);
    CHECK(da.search(5) == 5);
    CHECK(da.search(100) == dynamic_array::npos);
  }
}
