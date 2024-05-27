#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

class Cmd {
public:
  Cmd() = default;
  Cmd(double v) : v_(v) {};

  virtual double out(double start) = 0;
protected: 
  double v_ = 0;
  Cmd* next_ = nullptr;
};

class Add : public Cmd {
public:
  Add() = default;
  Add(double v_) : Cmd(v_) {};

  double out(double start) override {
    v_ += start;
    std::cout << v_ << std::endl;
    return v_;
  }
};

class Mul : public Cmd {
public:
  Mul() = default;
  Mul(double v_) : Cmd(v_) {}

  double out(double start) override {
    v_ *= start;
    std::cout << v_ << std::endl;
    return v_;
  }
};

class Sub : public Cmd {
public:
  Sub() = default;
  Sub(double v_) : Cmd(v_) {};

  double out(double start) override {
    v_ = start - v_;
    std::cout << v_ << std::endl;
    return v_;
  }
};

class Div : public Cmd {
public:
  Div() = default;
  Div(double v_) : Cmd(v_) {};

  double out(double start) override {
    v_ = start / v_;
    std::cout << v_ << std::endl;
    return v_;
  }
};

int execute(std::string command_, int operand_, std::vector<Cmd*>operations) {
   //posdfopsdifopsdfopisdopf i have no idea what to do ngl
  Cmd* ptr = nullptr;
  if (command_ == "ADD") {
    ptr = new Add(operand_);
    operations.push_back(ptr);
  }
  else if (command_ == "MUL") {
    ptr = new Mul(operand_);
    operations.push_back(ptr);
  }
  else if (command_ == "SUB") {
    ptr = new Sub(operand_);
    operations.push_back(ptr);
  }
  else if (command_ == "DIV") {
    ptr = new Div(operand_);
    operations.push_back(ptr);
  }
  else if (command_ == "REV") {
    if (operand_ < 0 || operand_ > operations.size()) {
      throw std::logic_error("wrong size");
    }
    operations.resize(operations.size() - operand_);
  }
  else if (command_ == "OUT") {
    for (Cmd* ptr : operations) {
      operand_ = ptr->out(operand_);
    }
  }
  return operand_;
}

int main() {
  std::fstream file;
  file.open("input.txt", std::ios::in);

  if (!file) {
    std::cerr << "Unable to open file\n";
    return 1;
  }

  std::string line;
  std::istringstream iss(line);
  std::string command_ = "";
  int operand_ = 0;

  std::vector <Cmd*> operations;

  while (std::getline(file, line)) {
    iss >> command_ >> operand_;
    execute(command_, operand_, operations);
  }
  file.close();

  std::ofstream output("output.txt");
  output << operand_ << "\n";
  return 0;
}
