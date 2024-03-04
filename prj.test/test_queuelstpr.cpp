#include <queuelstpr/queuelstpr.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("were going down") {
  QueueLstPr q;
  CHECK_EQ(q.IsEmpty(), 1);
  CHECK_THROWS(q.Top());
  q.Push(1);
  CHECK_EQ(q.IsEmpty(), 0);
  q.Print();
  q.Push(2);
  CHECK_EQ(q.IsEmpty(), 0);
  q.Print();
  q.Push(1);
  q.Print();
  q.Push(3);
  q.Print();
  q.Push(2);
  q.Print();
  q.Push(10);
  q.Push(9);
  q.Print();
  q.Push(8);
  q.Push(7);
  q.Print();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Print();

}