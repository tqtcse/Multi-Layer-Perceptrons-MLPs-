#ifndef UNIT_TEST_LOSS_HPP
#define UNIT_TEST_LOSS_HPP

#include "library.hpp"
class UNIT_TEST_Loss {
 public:
  UNIT_TEST_Loss() {
    registerTest("loss01", &UNIT_TEST_Loss::loss01);
    registerTest("loss02", &UNIT_TEST_Loss::loss02);
    registerTest("loss03", &UNIT_TEST_Loss::loss03);
    registerTest("loss04", &UNIT_TEST_Loss::loss04);
    registerTest("loss05", &UNIT_TEST_Loss::loss05);
    registerTest("loss06", &UNIT_TEST_Loss::loss06);
    registerTest("loss07", &UNIT_TEST_Loss::loss07);
    registerTest("loss08", &UNIT_TEST_Loss::loss08);
    registerTest("loss09", &UNIT_TEST_Loss::loss09);
    registerTest("loss10", &UNIT_TEST_Loss::loss10);
  }

 private:
  bool loss01();
  bool loss02();
  bool loss03();
  bool loss04();
  bool loss05();
  bool loss06();
  bool loss07();
  bool loss08();
  bool loss09();
  bool loss10();

 public:
  static map<string, bool (UNIT_TEST_Loss::*)()> TESTS;
  // ANSI escape codes for colors
  const string green = "\033[32m";
  const string red = "\033[31m";
  const string cyan = "\033[36m";
  const string reset = "\033[0m";  // To reset to default color

  // print result test case
  bool printResult(string output, string expect, string name) {
    if (expect == output) {
      cout << green << "test " + name + " --------------- PASS" << reset
           << "\n";
      return true;
    } else {
      cout << red << "test " + name + " --------------- FAIL" << reset << "\n";
      cout << "\texpect : " << expect << endl;
      cout << "\toutput : " << output << endl;
      return false;
    }
  }
  // run 1 test case
  void runTest(const std::string &name) {
    auto it = TESTS.find(name);
    if (it != TESTS.end()) {
      (this->*(it->second))();
    } else {
      throw std::runtime_error("Test with name '" + name + "' does not exist.");
    }
  }
  // run all test case
  void runAllTests() {
    vector<string> fails;
    for (const auto &test : TESTS) {
      if (!(this->*(test.second))()) {
        fails.push_back(test.first);
      }
    }

    cout << cyan << "\nResult -------------------------" << reset << endl;
    // Print the results
    if (fails.empty()) {
      cout << green << "All tests passed!" << reset << endl;
    } else {
      int totalTests = TESTS.size();
      int failedTests = fails.size();
      int passedTests = totalTests - failedTests;
      double passRate =
          (totalTests > 0)
              ? (static_cast<double>(passedTests) / totalTests) * 100.0
              : 0.0;
      cout << red << "Some tests failed:";
      for (const auto &fail : fails) {
        cout << "  " << fail;
      }
      cout << cyan << "\nPass rate: " << passRate << "%" << reset << endl;
    }
  }
  static void registerTest(string name, bool (UNIT_TEST_Loss::*function)()) {
    if (TESTS.find(name) != TESTS.end()) {
      throw std::runtime_error("Test with name '" + name + "' already exists.");
    }
    TESTS[name] = function;
  }
};

#endif  // UNIT_TEST_loss_HPP