#include <queuelstpr/queuelstpr.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("were going down") {
  QueueLstPr q;
  CHECK_EQ(q.IsEmpty(), 1);
  CHECK_THROWS(q.Top());
  q.Push(1);
  CHECK_EQ(q.IsEmpty(), 0);
  q.Push(2);
  CHECK_EQ(q.IsEmpty(), 0);
  q.Push(1);
  q.Push(3);
  q.Push(2);
  q.Push(10);
  q.Push(9);
  q.Push(8);
  q.Push(7);
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
  q.Pop();
}

TEST_CASE("generic test 0") {
  QueueLstPr qlp;
  CHECK(qlp.IsEmpty());
  qlp.Push(352131);
  CHECK_FALSE(qlp.IsEmpty());
  qlp.Push(-1313);
  qlp.Push(1815);
  CHECK_FALSE(qlp.IsEmpty());
  CHECK_EQ(qlp.Top(), -1313);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 1815);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 352131);
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE("copy_ctor") {
  QueueLstPr qlp;
  qlp.Push(352131);
  qlp.Push(-1313);
  qlp.Push(1815);
  QueueLstPr qlp_c(qlp);

  CHECK_EQ(qlp.Top(), -1313);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 1815);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 352131);
  qlp.Pop();
  CHECK(qlp.IsEmpty());

  CHECK_EQ(qlp_c.Top(), -1313);
  qlp_c.Pop();
  CHECK_EQ(qlp_c.Top(), 1815);
  qlp_c.Pop();
  CHECK_EQ(qlp_c.Top(), 352131);
  qlp_c.Pop();
  CHECK(qlp_c.IsEmpty());
}

TEST_CASE("copy_ctor 2") {
  QueueLstPr qlp;
  qlp.Push(1815);
  qlp.Push(-1313);
  qlp.Push(352131);
  qlp.Push(1815);
  qlp.Push(-1313);
  QueueLstPr qlp_c(qlp);

  CHECK_EQ(-1313, qlp.Top());
  qlp.Pop();
  CHECK_EQ(-1313, qlp.Top());
  qlp.Pop();
  CHECK_EQ(1815, qlp.Top());
  qlp.Pop();
  CHECK_EQ(1815, qlp.Top());
  qlp.Pop();
  CHECK_EQ(352131, qlp.Top());
  qlp.Pop();
  CHECK(qlp.IsEmpty());

  CHECK_EQ(-1313, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(-1313, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(1815, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(1815, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(352131, qlp_c.Top());
  qlp_c.Pop();
  CHECK(qlp_c.IsEmpty());
}

TEST_CASE("eq_ctor") {
  QueueLstPr qlp;
  qlp.Push(352131);
  qlp.Push(-1313);
  qlp.Push(1815);
  QueueLstPr qlp_e = qlp;

  CHECK_EQ(qlp.Top(), -1313);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 1815);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 352131);
  qlp.Pop();
  CHECK(qlp.IsEmpty());

  CHECK_EQ(qlp_e.Top(), -1313);
  qlp_e.Pop();
  CHECK_EQ(qlp_e.Top(), 1815);
  qlp_e.Pop();
  CHECK_EQ(qlp_e.Top(), 352131);
  qlp_e.Pop();
  CHECK(qlp_e.IsEmpty());
}

TEST_CASE("eq ctor 2") {
  QueueLstPr qlp;
  qlp.Push(1815);
  qlp.Push(-1313);
  qlp.Push(352131);
  qlp.Push(1815);
  qlp.Push(-1313);
  QueueLstPr qlp_c = qlp;

  CHECK_EQ(-1313, qlp.Top());
  qlp.Pop();
  CHECK_EQ(-1313, qlp.Top());
  qlp.Pop();
  CHECK_EQ(1815, qlp.Top());
  qlp.Pop();
  CHECK_EQ(1815, qlp.Top());
  qlp.Pop();
  CHECK_EQ(352131, qlp.Top());
  qlp.Pop();
  CHECK(qlp.IsEmpty());

  CHECK_EQ(-1313, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(-1313, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(1815, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(1815, qlp_c.Top());
  qlp_c.Pop();
  CHECK_EQ(352131, qlp_c.Top());
  qlp_c.Pop();
  CHECK(qlp_c.IsEmpty());
}

TEST_CASE("generic test 1") {
  QueueLstPr qlp;
  qlp.Push(352131);
  qlp.Push(-1313);
  qlp.Push(1815);

  CHECK_EQ(qlp.Top(), -1313);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 1815);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 352131);
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE("generic test 1 (five elems)") {
  QueueLstPr qlp;
  qlp.Push(1815);
  qlp.Push(-1313);
  qlp.Push(352131);
  qlp.Push(1815);
  qlp.Push(-1313);

  CHECK_EQ(-1313, qlp.Top());
  qlp.Pop();
  CHECK_EQ(-1313, qlp.Top());
  qlp.Pop();
  CHECK_EQ(1815, qlp.Top());
  qlp.Pop();
  CHECK_EQ(1815, qlp.Top());
  qlp.Pop();
  CHECK_EQ(352131, qlp.Top());
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE("generic test 2 (chain to right side)") {
  QueueLstPr qlp;
  qlp.Push(-1313);
  qlp.Push(1815);
  qlp.Push(352131);

  CHECK_EQ(qlp.Top(), -1313);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 1815);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 352131);
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE("generic test 3 (chain to left side)") {
  QueueLstPr qlp;
  qlp.Push(352131);
  qlp.Push(1815);
  qlp.Push(-1313);

  CHECK_EQ(qlp.Top(), -1313);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 1815);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 352131);
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE("generic test 4 (same elems)") {
  QueueLstPr qlp;
  qlp.Push(352131);
  qlp.Push(352131);
  qlp.Push(352131);
  qlp.Push(1815);
  qlp.Push(1815);

  CHECK_EQ(qlp.Top(), 1815);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 1815);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 352131);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 352131);
  qlp.Pop();
  CHECK_EQ(qlp.Top(), 352131);
  qlp.Pop();
  CHECK(qlp.IsEmpty());
}

TEST_CASE("MOVE SEMANTICS") {
  QueueLstPr qlp_parent;
  qlp_parent.Push(1815);
  qlp_parent.Push(-1313);
  qlp_parent.Push(352131);
  qlp_parent.Push(1815);
  qlp_parent.Push(-1313);
  QueueLstPr qlp_0(qlp_parent);

  auto start_1{ std::chrono::steady_clock::now() };
  QueueLstPr qlp_1(qlp_parent);
  auto end_1{ std::chrono::steady_clock::now() };

  auto start_2{ std::chrono::steady_clock::now() };
  QueueLstPr qlp_2(std::move(qlp_parent));
  auto end_2{ std::chrono::steady_clock::now() };

  qlp_parent = qlp_0;
  auto start_3{ std::chrono::steady_clock::now() };
  QueueLstPr qlp_3 = std::move(qlp_parent);
  auto end_3{ std::chrono::steady_clock::now() };

  std::chrono::nanoseconds elapsed_1(end_1 - start_1);
  std::chrono::nanoseconds elapsed_2(end_2 - start_2);
  std::chrono::nanoseconds elapsed_3(end_3 - start_3);

  // std::cout << elapsed_1 << ' ' << elapsed_2 << ' ' << elapsed_3;

  CHECK_EQ(-1313, qlp_1.Top());
  qlp_1.Pop();
  CHECK_EQ(-1313, qlp_1.Top());
  qlp_1.Pop();
  CHECK_EQ(1815, qlp_1.Top());
  qlp_1.Pop();
  CHECK_EQ(1815, qlp_1.Top());
  qlp_1.Pop();
  CHECK_EQ(352131, qlp_1.Top());
  qlp_1.Pop();
  CHECK(qlp_1.IsEmpty());

  CHECK_EQ(-1313, qlp_2.Top());
  qlp_2.Pop();
  CHECK_EQ(-1313, qlp_2.Top());
  qlp_2.Pop();
  CHECK_EQ(1815, qlp_2.Top());
  qlp_2.Pop();
  CHECK_EQ(1815, qlp_2.Top());
  qlp_2.Pop();
  CHECK_EQ(352131, qlp_2.Top());
  qlp_2.Pop();
  CHECK(qlp_2.IsEmpty());

  CHECK_EQ(-1313, qlp_3.Top());
  qlp_3.Pop();
  CHECK_EQ(-1313, qlp_3.Top());
  qlp_3.Pop();
  CHECK_EQ(1815, qlp_3.Top());
  qlp_3.Pop();
  CHECK_EQ(1815, qlp_3.Top());
  qlp_3.Pop();
  CHECK_EQ(352131, qlp_3.Top());
  qlp_3.Pop();
  CHECK(qlp_3.IsEmpty());


  CHECK(elapsed_2 + std::chrono::nanoseconds(200) < elapsed_1);
  CHECK(elapsed_3 + std::chrono::nanoseconds(200) < elapsed_1);
}

TEST_CASE("QueueLstPr constructors") {
  QueueLstPr queue;
  CHECK(queue.IsEmpty());

  QueueLstPr queue1;
  queue1.Push(1);
  QueueLstPr queue2(queue1);
  QueueLstPr queue3;
  queue3 = queue2;
  CHECK_FALSE(queue3.IsEmpty());

  QueueLstPr queue4(std::move(queue3));
  CHECK(queue4.Top() == 1);
  CHECK(queue3.IsEmpty());
}

TEST_CASE("QueueLstPr - IsEmpty") {
  QueueLstPr queue;
  CHECK(queue.IsEmpty());
  queue.Push(1);
  CHECK(!queue.IsEmpty());
  queue.Pop();
  CHECK(queue.IsEmpty());
}

TEST_CASE("QueueLstPr - right order") {
  QueueLstPr queue;
  queue.Push(1);
  queue.Push(3);
  queue.Push(2);
  CHECK(queue.Top() == 1);
  queue.Pop();
  CHECK(queue.Top() == 2);
  queue.Pop();
  CHECK(queue.Top() == 3);
  queue.Pop();
  CHECK(queue.IsEmpty());
}