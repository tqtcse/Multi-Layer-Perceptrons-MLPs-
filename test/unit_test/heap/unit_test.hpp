#ifndef UNIT_TEST_HEAP_HPP
#define UNIT_TEST_HEAP_HPP

#include "heap/Heap.h"
#include "library.hpp"
class UNIT_TEST_Heap {
 public:
  UNIT_TEST_Heap() {
    // TODO unit test new
    registerTest("heap01", &UNIT_TEST_Heap::heap01);
    registerTest("heap02", &UNIT_TEST_Heap::heap02);
    registerTest("heap03", &UNIT_TEST_Heap::heap03);
    registerTest("heap04", &UNIT_TEST_Heap::heap04);
    registerTest("heap05", &UNIT_TEST_Heap::heap05);
    registerTest("heap06", &UNIT_TEST_Heap::heap06);
    registerTest("heap07", &UNIT_TEST_Heap::heap07);
    registerTest("heap08", &UNIT_TEST_Heap::heap08);
    registerTest("heap09", &UNIT_TEST_Heap::heap09);
    registerTest("heap10", &UNIT_TEST_Heap::heap10);
    registerTest("heap11", &UNIT_TEST_Heap::heap11);
    registerTest("heap12", &UNIT_TEST_Heap::heap12);
    registerTest("heap13", &UNIT_TEST_Heap::heap13);
    registerTest("heap14", &UNIT_TEST_Heap::heap14);
    registerTest("heap15", &UNIT_TEST_Heap::heap15);
    registerTest("heap16", &UNIT_TEST_Heap::heap16);
    registerTest("heap17", &UNIT_TEST_Heap::heap17);
    registerTest("heap18", &UNIT_TEST_Heap::heap18);
    registerTest("heap19", &UNIT_TEST_Heap::heap19);
    registerTest("heap20", &UNIT_TEST_Heap::heap20);
    registerTest("heap21", &UNIT_TEST_Heap::heap21);
    registerTest("heap22", &UNIT_TEST_Heap::heap22);
    registerTest("heap23", &UNIT_TEST_Heap::heap23);
    registerTest("heap24", &UNIT_TEST_Heap::heap24);
    registerTest("heap25", &UNIT_TEST_Heap::heap25);
    registerTest("heap26", &UNIT_TEST_Heap::heap26);
    registerTest("heap27", &UNIT_TEST_Heap::heap27);
    registerTest("heap28", &UNIT_TEST_Heap::heap28);
    registerTest("heap29", &UNIT_TEST_Heap::heap29);
    registerTest("heap30", &UNIT_TEST_Heap::heap30);
    registerTest("heap31", &UNIT_TEST_Heap::heap31);
    registerTest("heap32", &UNIT_TEST_Heap::heap32);
    registerTest("heap33", &UNIT_TEST_Heap::heap33);
    registerTest("heap34", &UNIT_TEST_Heap::heap34);
    registerTest("heap35", &UNIT_TEST_Heap::heap35);
    registerTest("heap36", &UNIT_TEST_Heap::heap36);
    registerTest("heap37", &UNIT_TEST_Heap::heap37);
    registerTest("heap38", &UNIT_TEST_Heap::heap38);
    registerTest("heap39", &UNIT_TEST_Heap::heap39);
    registerTest("heap40", &UNIT_TEST_Heap::heap40);
    registerTest("heap41", &UNIT_TEST_Heap::heap41);
    registerTest("heap42", &UNIT_TEST_Heap::heap42);
    registerTest("heap43", &UNIT_TEST_Heap::heap43);
    registerTest("heap44", &UNIT_TEST_Heap::heap44);
    registerTest("heap45", &UNIT_TEST_Heap::heap45);
    registerTest("heap46", &UNIT_TEST_Heap::heap46);
    registerTest("heap47", &UNIT_TEST_Heap::heap47);
    registerTest("heap48", &UNIT_TEST_Heap::heap48);
    registerTest("heap49", &UNIT_TEST_Heap::heap49);
    registerTest("heap50", &UNIT_TEST_Heap::heap50);
  }

 private:
  // TODO unit test new
  bool heap01();
  bool heap02();
  bool heap03();
  bool heap04();
  bool heap05();
  bool heap06();
  bool heap07();
  bool heap08();
  bool heap09();
  bool heap10();
  bool heap11();
  bool heap12();
  bool heap13();
  bool heap14();
  bool heap15();
  bool heap16();
  bool heap17();
  bool heap18();
  bool heap19();
  bool heap20();
  bool heap21();
  bool heap22();
  bool heap23();
  bool heap24();
  bool heap25();
  bool heap26();
  bool heap27();
  bool heap28();
  bool heap29();
  bool heap30();
  bool heap31();
  bool heap32();
  bool heap33();
  bool heap34();
  bool heap35();
  bool heap36();
  bool heap37();
  bool heap38();
  bool heap39();
  bool heap40();
  bool heap41();
  bool heap42();
  bool heap43();
  bool heap44();
  bool heap45();
  bool heap46();
  bool heap47();
  bool heap48();
  bool heap49();
  bool heap50();

 public:
  static map<string, bool (UNIT_TEST_Heap::*)()> TESTS;
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
  static void registerTest(string name, bool (UNIT_TEST_Heap::*function)()) {
    if (TESTS.find(name) != TESTS.end()) {
      throw std::runtime_error("Test with name '" + name + "' already exists.");
    }
    TESTS[name] = function;
  }
};

#endif  // UNIT_TEST_heap_HPP