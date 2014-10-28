// Victor Guerra <vguerra@gmail.com>
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "dynamic_array.h"

TEST_CASE("Constructors of dynamic_array", "[dynamic_array]") {
  SECTION("Default constructors") { 
    {
      dynamic_array da(2);
  
      WARN("The capacity is: " << da.capacity());
      WARN("The size is: " << da.size());
  
    }
  }
}
