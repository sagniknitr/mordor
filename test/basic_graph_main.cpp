#include <gtest/gtest.h>
#include "core/graph_base.hpp"


#include "sample1.h"
#include "gtest/gtest.h"

namespace {


TEST(basic_graph_main, CreateGrap) {
}

TEST(basic_graph_main, DestroyGraph) {
}


} 

int main(int argc,
         char * argv[], char * envp[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}