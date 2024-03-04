#include <queuelstp/queuelstp.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("were going down") {
  QueueLstP q;
  CHECK_EQ(q.IsEmpty(), 1);
  CHECK_THROWS(q.Top());
  q.Push(1);
  CHECK_EQ(q.IsEmpty(), 0);
  std::cout << q.Top() << std::endl;
  q.Push(2);
  CHECK_EQ(q.IsEmpty(), 0);
  std::cout << q.Top() << std::endl;
  q.Pop();
  std::cout << q.Top();

}