#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

class Base {
public:
  Base() = default;
  Base(double v) : v_(v) {};

  virtual double out(double start) {
    return 1;
  }

protected: 
  double v_ = 0;
};

class Add : public Base {
public:
  Add() = default;
  Add(double v_) : Base(v_) {};

  double out(double start) override {
    v_ += start;
    std::cout << v_ << std::endl;
    return v_;
  }
};

class Mul : public Base {
public:
  Mul() = default;
  Mul(double v_) : Base(v_) {}

  double out(double start) override {
    v_ *= start;
    std::cout << v_ << std::endl;
    return v_;
  }
};

class Sub : public Base {
public:
  Sub() = default;
  Sub(double v_) : Base(v_) {};

  double out(double start) override {
    v_ = start - v_;
    std::cout << v_ << std::endl;
    return v_;
  }
};

class Div : public Base {
public:
  Div() = default;
  Div(double v_) : Base(v_) {};

  double out(double start) override {
    v_ = start / v_;
    std::cout << v_ << std::endl;
    return v_;
  }
};

void run(std::string command, int operand) {
   //posdfopsdifopsdfopisdopf i have no idea what you want ngl
  Base* ptr = nullptr;
  if (command == "ADD") {
    ptr = new Add();
  }
  else if (command == "MUL") {
    ptr = new Mul();
  }
  else if (command == "SUB") {
    ptr = new Sub();
  }
  else if (command == "DIV") {
    ptr = new Div();
  }
  else if (command == "REV") {
    //TODO
  }
  else if (command == "OUT") {
    //TODO
  }
}

int main() {
  std::ifstream file("input.txt");
  std::string line;
  std::istringstream iss(line);
  std::string command_;
  int operand_;
  while (std::getline(file, line)) {
    iss >> command_ >> operand_;

  }
}
