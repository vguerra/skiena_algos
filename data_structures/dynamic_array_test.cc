// Victor Guerra <vguerra@gmail.com>
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
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

    da.remove(1);
    CHECK(da.capacity() == 4);
    CHECK(da.size() == 3);
  
  }
}
