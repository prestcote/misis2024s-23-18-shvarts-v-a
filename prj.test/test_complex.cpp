
#include <iostream>
#include <stdexcept>
#include <map>
#include <complex/complex.hpp>

/*
void testFunc() {
  int errorCount = 0;

  Complex a_sum(1, 2);
  Complex b_sum(3, 4);
  Complex SumRes(a_sum.re + b_sum.re, a_sum.im + b_sum.im);
  Complex Sum;
  Sum = a_sum + b_sum;
  a_sum += b_sum;
  if (SumRes != Sum || SumRes != a_sum) {
    throw "Summation error found";
    errorCount += 1;
  }

  Complex a_sub(1, 2);
  Complex b_sub(3, 4);
  Complex SubRes(a_sub.re - b_sub.re, a_sub.im - b_sub.im);
  Complex Sub;
  Sub = a_sub - b_sub;
  a_sub -= b_sub;
  if (SubRes != Sub || SubRes != a_sub) {
    throw "Substraction error found";
  }

  Complex a_mult(1, 2);
  Complex b_mult(3, 4);
  Complex MultRes(a_mult.re * b_mult.re - a_mult.im * b_mult.im, a_mult.re * b_mult.im + a_mult.im * b_mult.re);
  Complex Mult;
  Mult = a_mult * b_mult;
  a_mult *= b_mult;
  if (MultRes != Mult) {
    std::cout << MultRes.re << ";" << MultRes.im << " " << Mult.re << ";" << Mult.im << " " << a_mult.re << ";" << a_mult.im;
    throw "Multiplication error found";
  }
  if (MultRes != a_mult) {
    throw "Multiplication assignment error found";
  }

  Complex a_div(-5, 10);
  Complex b_div(1, 2);
  double r = b_div.re * b_div.re + b_div.im * b_div.im;
  Complex DivRes((a_div.re * b_div.re + a_div.im * b_div.im) / r, (a_div.im * b_div.re - b_div.re * a_div.im) / r);
  Complex Div;
  Div = a_div / b_div;
  a_div /= b_div;
  if (DivRes != Div || DivRes != a_div) {
    throw "Division error found";
  }
}

int main() {
  Complex a(1, 2);
  Complex b(3, 4);
  Complex S;
  a *= b;
  int errorCount = 0;
  std::cout << "TestExecution \n";
  try {
    testFunc();
  }
  catch (const char * message) {
    std::cout << "error found: \n" << message << "\n";
    errorCount += 1;
  }
  try {
    a /= b;
  }
  catch (const char * message) {
    std::cout << "error found: DivisionByZeroException \n";
    errorCount += 1;
  }
  std::cout << "Test result: " << errorCount << " errors found";
}*/
/*
struct TestComplexException : public std::exception {
  TestComplexException(std::string n_TestName) :
    TestName{ n_TestName } {}
  std::string TestName;
};

void TestComplex(double re1, double im1, double re2, double im2) {

  { // check Complex c1 == Complex c2
    Complex c1(re1, im1);
    Complex c2(re2, im2);
    if ((c1 == c2 && (re1 != re2 || im1 != im2))) {
      throw TestComplexException("complex1 == complex2");
    }
    if ((c1 != c2 && (re1 == re2 && im1 == im2))) {
      throw TestComplexException("complex1 != complex2");
    }
  }

  { // check operator-
    Complex c1(re1, im1);
    Complex c2(re2, im2);
    Complex c3 = -c1;
    if (c3.re != -re1 || c3.im != -im1) {
      throw TestComplexException("operator-");
    }
    if (c1.re != re1 || c1.im != im1) {
      throw TestComplexException("operator- (lost const)");
    }
  }

  { // check operator+ and += (Complex, Complex)
    Complex c1(re1, im1);
    Complex c2(re2, im2);
    Complex real_result(re1 + re2, im1 + im2);

    Complex c4 = c1;
    c4 += c2;

    Complex c5 = c1 + c2;

    if (real_result != c4 || real_result != c5) {
      throw TestComplexException("operator+ / operator+= (Complex, Complex)");
    }
    if (c1 != Complex(re1, im1) || c2 != Complex(re2, im2)) {
      throw TestComplexException("operator+ / operator+= (Complex, Complex) (lost const)");
    }
  }

  { // check operator- and -= (Complex, Complex)
    Complex c1(re1, im1);
    Complex c2(re2, im2);
    Complex real_result(re1 - re2, im1 - im2);

    Complex c4 = c1;
    c4 -= c2;

    Complex c5 = c1 - c2;

    if (real_result != c4 || real_result != c5) {
      throw TestComplexException("operator- / operator-= (Complex, Complex)");
    }
    if (c1 != Complex(re1, im1) || c2 != Complex(re2, im2)) {
      throw TestComplexException("operator- / operator-= (Complex, Complex) (lost const)");
    }
  }

  { // check operator+ and += (Complex, double)
    Complex c1(re1, im1);
    double d2 = re2;
    Complex real_result(re1 + re2, im1);

    Complex c4 = c1;
    c4 += d2;

    Complex c5 = c1 + d2;

    if (real_result != c4 || real_result != c5) {
      throw TestComplexException("operator+ / operator+= (Complex, double)");
    }
    if (c1 != Complex(re1, im1) || d2 != re2) {
      throw TestComplexException("operator+ / operator+= (Complex, double) (lost const)");
    }
  }

  { // check operator- and -= (Complex, double)
    Complex c1(re1, im1);
    double d2 = re2;
    Complex real_result(re1 - re2, im1);

    Complex c4 = c1;
    c4 -= d2;

    Complex c5 = c1 - d2;

    if (real_result != c4 || real_result != c5) {
      throw TestComplexException("operator- / operator-= (Complex, double)");
    }
    if (c1 != Complex(re1, im1) || d2 != re2) {
      throw TestComplexException("operator- / operator-= (Complex, double) (lost const)");
    }
  }

  { // check operator* and *= (Complex, Complex)
    Complex c1(re1, im1);
    Complex c2(re2, im2);
    Complex real_result(re1 * re2 - im1 * im2, re1 * im2 + im1 * re2);

    Complex c3 = c1;
    c3 *= c2;

    Complex c4 = c1 * c2;


    if (c3 != real_result || c4 != real_result) {
      throw TestComplexException("operator* / operator*= (Complex, Complex)");
    }
    if (c1 != Complex(re1, im1) || c2 != Complex(re2, im2)) {
      throw TestComplexException("operator* / operator*= (Complex, Complex) (lost const)");
    }
  }

  { // check operator* and *= (Complex, double)
    Complex c1(re1, im1);
    double d2 = re2;
    Complex real_result(re1 * re2, im1 * re2);

    Complex c3 = c1;
    c3 *= d2;

    Complex c4 = c1 * d2;


    if (c3 != real_result || c4 != real_result) {
      throw TestComplexException("operator* / operator*= (Complex, double)");
    }
    if (c1 != Complex(re1, im1) || d2 != re2) {
      throw TestComplexException("operator* / operator*= (Complex, double) (lost const)");
    }
  }

  { // check conjugality
    Complex c1(re1, im1);
    Complex c2 = c1.conjugate();
    Complex real_result(re1, -im1);

    if (c2 != real_result) {
      throw TestComplexException("conjugality");
    }
    if (c1 != Complex(re1, im1)) {
      throw TestComplexException("conjugality (lose const)");
    }
  }

  { // check operator/ and /= (Complex, double)
    Complex c1(re1, im1);
    double d2 = re2;

    if (d2 != 0) {
      Complex c3 = c1;
      c3 /= d2;

      Complex c4 = c1 / d2;

      Complex real_result = Complex(re1 / re2, im1 / re2);

      if (c4 != real_result || c4 != real_result) {
        throw TestComplexException("operator/ / operator/= (Complex, double)");
      }

      if (c1 != Complex(re1, im1) || d2 != re2) {
        throw TestComplexException("operator/ / operator/= (Complex, double) (lost const)");
      }
    }
    else {
      try {
        Complex c3 = c1;
        c3 /= d2;
        throw TestComplexException("operator/ / operator/= (Complex, double) (no DivisionByZeroException)");
      }
      catch (Complex::DivisionByZeroException& e) {
        // all correct, do nothing
      }

      try {
        Complex c4 = c1 / d2;
        throw TestComplexException("operator/ / operator/= (Complex, double) (no DivisionByZeroException)");
      }
      catch (Complex::DivisionByZeroException& e) {
        // all correct, do nothing
      }
    }
  }

  { // check operator/ and /= (Complex, Complex)
    Complex c1(re1, im1);
    Complex c2(re2, im2);

    if (re2 * re2 + im2 * im2 != 0) {
      Complex c3 = c1;
      c3 /= c2;

      Complex c4 = c1 / c2;

      Complex real_result = Complex(re1, im1) * Complex(re2, im2).conjugate();
      real_result /= (re2 * re2 + im2 * im2);

      if (c3 != real_result || c4 != real_result) {
        throw TestComplexException("operator/ / operator/= (Complex, Complex)");
      }
      if (c1 != Complex(re1, im1) || c2 != Complex(re2, im2)) {
        throw TestComplexException("operator/ / operator/= (Complex, Complex) (lost const)");
      }
    }
    else {
      try {
        Complex c3 = c1;
        c3 /= c2;
        throw TestComplexException("operator/ / operator/= (Complex, Complex) (no DivisionByZeroException)");
      }
      catch (Complex::DivisionByZeroException& e) {
        // all correct, do nothing
      }

      try {
        Complex c4 = c1 / c2;
        throw TestComplexException("operator/ / operator/= (Complex, Complex) (no DivisionByZeroException)");
      }
      catch (Complex::DivisionByZeroException& e) {
        // all correct, do nothing
      }
    }
  }
  return;
}

int main() {
  bool exception_happened = false;
  std::map<std::string, int> exceptions_count;
  for (int i_re1 = -10; i_re1 <= 10; i_re1 += 1) {
    for (int i_im1 = -10; i_im1 <= 10; i_im1 += 1) {
      for (int i_re2 = -10; i_re2 <= 10; i_re2 += 1) {
        for (int i_im2 = -10; i_im2 <= 10; i_im2 += 1) {
          double re1{ i_re1 / 10.0 };
          double im1{ i_im1 / 10.0 };
          double re2{ i_re2 / 10.0 };
          double im2{ i_im2 / 10.0 };

          try {
            TestComplex(re1, im1, re2, im2);
          }
          catch (TestComplexException& e) {
            ++exceptions_count[e.TestName];
            if (!exception_happened) {
              std::cout << "Error with values:\n" <<
                "re1 = " << re1 <<
                ", im1 = " << im1 <<
                ", re2 = " << re2 <<
                ", im2 = " << im2 << '\n' <<
                "in test named \"" << e.TestName << "\"\n";
              exception_happened = true;
            }
          }
          catch (...) {
            ++exceptions_count["other"];
            if (!exception_happened) {
              std::cout << "Unusual exception happened \n";
              exception_happened = true;
            }
          }
        }
      }
    }
  }
  if (!exception_happened) {
    std::cout << "Congratulations! All of the tests passed successfully!!\n";
  }
  else {
    std::cout << "Total exceptions count:\n";
    for (auto i : exceptions_count) {
      std::cout << "in " << i.first << ": " << i.second << '\n';
    }
  }

  return 0;
}
*/

#include <complex/complex.hpp>
#include <iostream>

void printHeader() {
  std::cout
    << "|STATUS|               ANSWER == CORRECT              | COMMENT\n";
}
bool printTestLog(std::string answer, std::string correct,
  std::string comment) {
  bool status = answer == correct;
  if (status) {
    std::cout << "|  \033[92mOK\033[0m  | ";
  }
  else {
    std::cout << "| \033[91mFAIL\033[0m | ";
  }
  std::cout.width(20);
  std::cout << std::right;
  std::cout << answer;
  if (status) {
    std::cout << " == ";
  }
  else {
    std::cout << " != ";
  }
  std::cout.width(20);
  std::cout << std::left;
  std::cout << correct << " | " << comment << std::endl;

  return status;
}

std::pair<bool, Complex> testInput(std::string input_string) {
  std::istringstream input(input_string);
  Complex complex_number;
  input >> complex_number;
  return std::pair<bool, Complex>{input.good(), complex_number};
}

void testMethods() {
  printHeader();
  std::string x;
  std::ostringstream ostr("");
  int correct_counter = 0;
  int total_tests_counter = 0;

  ostr.str("");
  ostr << Complex(3, 4);
  correct_counter += printTestLog(ostr.str(), "{3,4}", "create {3,4}");
  total_tests_counter += 1;

  ostr.str("");
  Complex t(3, 4);
  ostr << t.re << " " << t.im;
  correct_counter += printTestLog(ostr.str(), "3 4", "complex.re complex.im");
  total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(4);
  correct_counter += printTestLog(ostr.str(), "{4,0}", "complex <- 4");
  total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(3, 4) + Complex(3, -1);
  correct_counter += printTestLog(ostr.str(), "{6,3}", "{3, 4} + {3, -1}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(3, 4) - Complex(3, -1);
  correct_counter += printTestLog(ostr.str(), "{0,5}", "{3, 4} - {3, -1}");
  total_tests_counter += 1;

  //ostr.str("");
  //ostr << abs(Complex(3, 4));
  //correct_counter += printTestLog(ostr.str(), "5", " abs({3, 4})");
  //total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(3, 4) * 2;
  correct_counter += printTestLog(ostr.str(), "{6,8}", " {3, 4} * 2");
  total_tests_counter += 1;

  ostr.str("");
  ostr << 2 * Complex(3, 4);
  correct_counter += printTestLog(ostr.str(), "{6,8}", " 2 * {3, 4}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(6, 4) / 2;
  correct_counter += printTestLog(ostr.str(), "{3,2}", " {6, 4} / 2");
  total_tests_counter += 1;

  ostr.str("");
  try {
    Complex(6, 4) / 0;
  }
  catch (const std::invalid_argument& e) {
    ostr << e.what();
  }
  correct_counter +=
    printTestLog(ostr.str(), "DivisionByZeroException", " {6, 4} / 0");
  total_tests_counter += 1;

  ostr.str("");
  ostr << Complex(12, 8) / Complex(6, 4);
  correct_counter += printTestLog(ostr.str(), "{2,0}", "{12, 8} / {6, 4}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << (Complex(12, 8) == Complex(12, 8));
  correct_counter += printTestLog(ostr.str(), "1", "{12, 8} == {12, 8}");
  total_tests_counter += 1;

  double z = 100;
  z /= 9995577897775;
  double power = 6575763;
  double y = pow(z, 0.5 / power);
  y = pow(y, 2);
  y = pow(y, power);

  ostr.str("");
  ostr << (y == z);
  correct_counter +=
    printTestLog(ostr.str(), "0",
      "z = 100/(9995577897775) y = (z**0.5/x) ** 2 ** x; y == z");
  total_tests_counter += 1;

  ostr.str("");
  ostr << (Complex(y, 8) == Complex(z, 8));
  correct_counter += printTestLog(ostr.str(), "1", "{z, 8} == {y, 8}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << (Complex(12, 8) == Complex(12, 7));
  correct_counter += printTestLog(ostr.str(), "0", "{12,8} != {12,7}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << (Complex(12, 8) == Complex(11, 8));
  correct_counter += printTestLog(ostr.str(), "0", "{12,8} != {11, 8}");
  total_tests_counter += 1;

  ostr.str("");
  std::pair<bool, Complex> test_results = testInput("{1, 2}");
  ostr << test_results.first << " " << test_results.second;
  correct_counter += printTestLog(ostr.str(), "1 {1,2}", "Input: {1, 2}");
  total_tests_counter += 1;

  ostr.str("");
  test_results = testInput("{1,2}");
  ostr << test_results.first << " " << test_results.second;
  correct_counter += printTestLog(ostr.str(), "1 {1,2}", "Input: {1,2}");
  total_tests_counter += 1;

  ostr.str("");
  test_results = testInput("{1, 2");
  ostr << test_results.first << " " << test_results.second;
  correct_counter += printTestLog(ostr.str(), "0 {0,0}", "Input: {1, 2");
  total_tests_counter += 1;

  ostr.str("");
  test_results = testInput("1, 2");
  ostr << test_results.first << " " << test_results.second;
  correct_counter += printTestLog(ostr.str(), "0 {0,0}", "Input: (1, 2}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << (Complex(12, 8) == Complex(11, 8));
  correct_counter += printTestLog(ostr.str(), "0", "{12,8} != {11, 8}");
  total_tests_counter += 1;

  ostr.str("");
  ostr << (Complex(-1, 2) == -Complex(1, -2));
  correct_counter += printTestLog(ostr.str(), "1", "Complex(-1, 2) == -Complex(1, -2)");
  total_tests_counter += 1;

  // finally tests counting
  ostr.str("");
  ostr << correct_counter;
  std::string correct_counter_str = ostr.str();
  ostr.str("");
  ostr << total_tests_counter;
  printTestLog(correct_counter_str, ostr.str(), "correct tests / total tests");
}

int main() {
  std::cout << "Running tests:\n";
  testMethods();
  return 0;
}
