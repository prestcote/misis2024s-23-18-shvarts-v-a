#include <iostream>
#include <vector>
#include <string>
#include <exception>

class Robocalc {
public:
  Robocalc() = default;
  Robocalc(double v) : v_(v) {};

  virtual double Out(double start) {
    return 1;
  }

protected: 
  double v_ = 0;
};

class Robocalc_add : public Robocalc {
public:
  Robocalc_add() = default;
  Robocalc_add(double v_) : Robocalc(v_) {};

  double Out(double start) override {
    v_ += start;
    std::cout << v_ << std::endl;
    return v_;
  }
};

class Robocalc_mul : public Robocalc {
public:
  Robocalc_mul() = default;
  Robocalc_mul(double v_) : Robocalc(v_) {}

  double Out(double start) override {
    v_ *= start;
    std::cout << v_ << std::endl;
    return v_;
  }
};

class Robocalc_sub : public Robocalc {
public:
  Robocalc_sub() = default;
  Robocalc_sub(double v_) : Robocalc(v_) {};

  double Out(double start) override {
    v_ = start - v_;
    std::cout << v_ << std::endl;
    return v_;
  }
};

class Robocalc_div : public Robocalc {
public:
  Robocalc_div() = default;
  Robocalc_div(double v_) : Robocalc(v_) {};

  double Out(double start) override {
    v_ = start / v_;
    std::cout << v_ << std::endl;
    return v_;
  }
};


int main() {
  std::vector<Robocalc*> vec;
  std::string command;
  while (std::cin >> command) {
    if (command == "ADD") {
      double v;
      std::cin >> v;
      Robocalc* idx = new Robocalc_add(v);
      vec.push_back(idx);
    }
    else if (command == "MUL") {
      double v;
      std::cin >> v;
      Robocalc* idx = new Robocalc_mul(v);
      vec.push_back(idx);
    }
    else if (command == "DIV") {
      double v;
      std::cin >> v;
      if (v == 0) {
        std::cout << "division by zero error";
        return 0;
      }
      /*
      try {
        v /= 0;
      }
      catch (const char* error_message) {
        std::cout << error_message << std::endl;
        break;
      }
      */
      Robocalc* idx = new Robocalc_div(v);
      vec.push_back(idx);
    }
    else if (command == "SUB") {
      double v;
      std::cin >> v;
      Robocalc* idx = new Robocalc_sub(v);
      vec.push_back(idx);
    }
    else if (command == "REV") {
      double size;
      std::cin >> size;
      if (size > vec.size() || size < 0) {
        std::cout << "invalid size";
        return 0;
      }
      vec.resize(vec.size() - size);
    }
    else if (command == "OUT") {
      int v = 0;
      std::cin >> v;
      for (int i = 0; i < vec.size(); i++) {
        v = vec[i]->Out(v);
        //std::cout << v << std::endl;
      }
      std::cout << v << std::endl;
    }
    else {
      std::cout << "wrong command. try again.";
    }
  }
}
