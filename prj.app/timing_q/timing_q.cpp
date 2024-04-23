#include <queuelstt/queuelstt.hpp>
#include <queuearrt/queuearrt.hpp>
#include <complex/complex.hpp>

#include <chrono>
#include <iostream>

int QueueArrPush(int elements) {
  QueueArrT<Complex> d;
  const auto start_arr{ std::chrono::high_resolution_clock::now() };
  for (int i = 0; i < elements; i++) {
    d.Push(Complex(i, 0));
    //d.Push(i);
  }
  const auto end_arr{ std::chrono::high_resolution_clock::now() };
  const std::chrono::nanoseconds elapsed_seconds_arr{ end_arr - start_arr };
  int res = elapsed_seconds_arr.count();
  return res;
}

int QueueArrPop(int elements) {
  QueueArrT<Complex> d;
  for (int i = 0; i < elements; i++) {
    d.Push(Complex(i, 0));
    //d.Push(i);
  }
  const auto start_arr{ std::chrono::high_resolution_clock::now() };
  while (!d.IsEmpty()) {
    d.Pop();
  }
  const auto end_arr{ std::chrono::high_resolution_clock::now() };
  const std::chrono::nanoseconds elapsed_seconds_arr{ end_arr - start_arr };
  int res = elapsed_seconds_arr.count();
  return res;
}

int QueueArrCtorCopy(int elements) {
  QueueArrT<Complex> d;
  for (int i = 0; i < elements; i++) {
    d.Push(Complex(i, 0));
  }
  const auto start_copyarr{ std::chrono::high_resolution_clock::now() };
  QueueArrT<Complex> copy(d);
  const auto end_copyarr{ std::chrono::high_resolution_clock::now() };
  const std::chrono::nanoseconds timer_copyctor_arr{ end_copyarr - start_copyarr };
  int res = timer_copyctor_arr.count();
  return res;
}

int QueueArrCopy(int elements) {
  QueueArrT<Complex> p;
  for (int i = 0; i < elements; i++) {
    p.Push(Complex(i, 0));
  }
  QueueArrT<Complex> d;
  const auto start_arr{ std::chrono::high_resolution_clock::now() };
  d = p;
  const auto end_arr{ std::chrono::high_resolution_clock::now() };
  const std::chrono::nanoseconds seconds{ end_arr - start_arr };
  int res = seconds.count();
  return res;
}

int QueueLstPush(int elements) {
  QueueLstT<Complex> p;
  const auto start_lst{ std::chrono::high_resolution_clock::now() };
  for (int i = 0; i < elements; i++) {
    p.Push(Complex(i, 0));
    //p.Push(i);
  }
  const auto end_lst{ std::chrono::high_resolution_clock::now() };
  const std::chrono::nanoseconds elapsed_seconds{ end_lst - start_lst };
  int res =  elapsed_seconds.count();
  return res;
}

int QueueLstPop(int elements) {
  QueueLstT<Complex> d;
  for (int i = 0; i < elements; i++) {
    d.Push(Complex(i, 0));
  }
  const auto start_arr{ std::chrono::high_resolution_clock::now() };
  while (!d.IsEmpty()) {
    d.Pop();
  }
  const auto end_arr{ std::chrono::high_resolution_clock::now() };
  const std::chrono::nanoseconds elapsed_seconds_arr{ end_arr - start_arr };
  int res = elapsed_seconds_arr.count();
  return res;
}

int QueueLstCtorCopy(int elements) {
  QueueLstT<Complex> d;
  for (int i = 0; i < elements; i++) {
    d.Push(Complex(i, 0));
  }
  const auto start_copyarr{ std::chrono::high_resolution_clock::now() };
  QueueLstT<Complex> copy(d);
  const auto end_copyarr{ std::chrono::high_resolution_clock::now() };
  const std::chrono::nanoseconds timer_copyctor_arr{ end_copyarr - start_copyarr };
  int res = timer_copyctor_arr.count();
  return res;
}

void PushTest(int elements) {
  std::cout << "number of elements: " << elements << std::endl;
  int av_arr = 0;
  for (int i = 0; i < 10; i++) {
    av_arr += QueueArrPush(elements);
  }
  std::cout << "arr time: " << av_arr / 10 << std::endl;
  int av_lst = 0;
  for (int i = 0; i < 10; i++) {
    av_lst += QueueLstPush(elements);
  }
  std::cout << "lst time: " << av_lst / 10 << std::endl << std::endl;
}


void PopTest(int elements) {
  std::cout << "number of elements: " << elements << std::endl;
  int av_arr = 0;
  for (int i = 0; i < 10; i++) {
    av_arr += QueueArrPop(elements);
  }
  std::cout << "arr time: " << av_arr / 10 << std::endl;
  int av_lst = 0;
  for (int i = 0; i < 10; i++) {
    av_lst += QueueLstPop(elements);
  }
  std::cout << "lst time: " << av_lst / 10 << std::endl << std::endl;
}

void CopyCtorTest(int elements) {
  std::cout << "number of elements copied: " << elements << std::endl;
  int av_arr = 0;
  for (int i = 0; i < 10; i++) {
    av_arr += QueueArrCtorCopy(elements);
  }
  std::cout << "arr time: " << av_arr / 10 << std::endl;
  int av_lst = 0;
  for (int i = 0; i < 10; i++) {
    av_lst += QueueLstCtorCopy(elements);
  }
  std::cout << "lst time: " << av_lst / 10 << std::endl << std::endl;
}

int main() {

  std::cout << "PUSH time test; average of 10 measurements" << std::endl << std::endl;
  PushTest(1);
  PushTest(2);
  PushTest(10);
  PushTest(100);
  PushTest(1000);
  PushTest(10000);

  std::cout << "POP time test; average of 10 measurements" << std::endl << std::endl;
  PopTest(1);
  PopTest(2);
  PopTest(10);
  PopTest(100);
  PopTest(1000);
  PopTest(10000);
  
  std::cout << "COPY CTOR time test; average of 10 measurements" << std::endl << std::endl;
  CopyCtorTest(0);
  CopyCtorTest(1);
  CopyCtorTest(2);
  CopyCtorTest(10);
  CopyCtorTest(100);
  CopyCtorTest(1000);
  CopyCtorTest(10000);
}