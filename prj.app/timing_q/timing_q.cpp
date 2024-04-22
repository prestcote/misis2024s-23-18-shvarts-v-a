#include <queuelst/queuelst.hpp>
#include <queuearr/queuearr.hpp>

#include <chrono>
#include <iostream>

int QueueArrPush(int elements) {
  QueueArr d;
  const auto start_arr{ std::chrono::high_resolution_clock::now() };
  for (int i = 0; i < elements; i++) {
    d.Push(Complex(i, 0));
  }
  const auto end_arr{ std::chrono::high_resolution_clock::now() };
  const std::chrono::nanoseconds elapsed_seconds_arr{ end_arr - start_arr };
  int res = elapsed_seconds_arr.count();
  return res;
}

int QueueLstPush(int elements) {
  QueueLst p;
  const auto start_lst{ std::chrono::high_resolution_clock::now() };
  for (int i = 0; i < 10; i++) {
    p.Push(Complex(i, 0));
  }
  const auto end_lst{ std::chrono::high_resolution_clock::now() };
  const std::chrono::nanoseconds elapsed_seconds{ end_lst - start_lst };
  int res =  elapsed_seconds.count();
  return res;
}

int main() {
  std::cout << "PUSH time test" << std::endl << std::endl;

  std::cout << "number of elements: 2" << std::endl;
  std::cout << "arr time: " << QueueArrPush(2) << std::endl;
  std::cout << "lst time: " << QueueLstPush(2) << std::endl << std::endl;

  std::cout << "number of elements: 10" << std::endl;
  std::cout << "arr time: " << QueueArrPush(10) << std::endl;
  std::cout << "lst time: " << QueueLstPush(10) << std::endl << std::endl;

  std::cout << "number of elements: 100" << std::endl;
  std::cout << "arr time: " << QueueArrPush(100) << std::endl;
  std::cout << "lst time: " << QueueLstPush(100) << std::endl << std::endl;

  std::cout << "number of elements: 10000" << std::endl;
  std::cout << "arr time: " << QueueArrPush(1000) << std::endl;
  std::cout << "lst time: " << QueueLstPush(1000) << std::endl << std::endl;

  std::cout << "number of elements: 10000" << std::endl;
  std::cout << "arr time: " << QueueArrPush(10000) << std::endl;
  std::cout << "lst time: " << QueueLstPush(10000) << std::endl;
  
}