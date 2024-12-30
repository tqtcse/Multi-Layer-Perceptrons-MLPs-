/*
 * Assignment 2 - Developing List Data Structures and Artificial Neural Networks
 * file : main.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 26.10.2024

 ! build code :  in PDF

 * run code
    * terminal unit test array list
    !./main test_unit
    !./main test_unit nameFunctionUnitTest
*/

#include "main.hpp"
#include "test\unit_test\heap\unit_test.cpp"
#include "test\unit_test\hash\unit_test.cpp"
#ifdef TEST_HASH
// #include "random_test/hash/random_test.hpp"
#include "unit_test/hash/unit_test.hpp"
const string TEST_CASE = "HASH";
#elif defined(TEST_HEAP)
// #include "random_test/heap/random_test.hpp"
#include "unit_test/heap/unit_test.hpp"
const string TEST_CASE = "HEAP";
#elif defined(TEST_LAYER)
// #include "random_test/heap/random_test.hpp"
#include "unit_test/layer/unit_test.hpp"
const string TEST_CASE = "LAYER";
#elif defined(TEST_LOSS)
// #include "random_test/heap/random_test.hpp"
#include "unit_test/loss/unit_test.hpp"
const string TEST_CASE = "LOSS";
#endif
void printTestCase();

int main(int argc, char *argv[]) {
  // if (argc <= 1) {
  //   printTestCase();
  //   return 1;
  // }

  // std::string arg1 = argv[1];
  // if (arg1 == "test_unit") {
  //   std::cout << GREEN << BOLD << "Running unit_test/" << TEST_CASE << RESET
  //             << "\n";
  //   handleTestUnit(argc, argv);
  // } else if (arg1 == "test_random") {
  //   std::cout << GREEN << BOLD << "Running test_random/" << TEST_CASE << RESET
  //             << "\n";
  //   handleTestRandom(argc, argv);
  // } else {
  //   printTestCase();
  // }
  int array[] = {50, 20, 15, 10, 8, 6, 7, 23}; 
  //min heap: [6, 10, 7, 23, 15, 20, 8, 50]
  //max heap: [50, 23, 15, 20, 8, 6, 7, 10]
  Heap<int> minHeap1;
  cout << "Min Heap: ";
  minHeap1.heapify(array, 8);
  cout << minHeap1.toString() << endl;
  
  Heap<int> minHeap2(minHeapComparator);
  cout << "Min Heap: ";
  minHeap2.heapify(array, 8);
  cout << minHeap2.toString() << endl;
  
  Heap<int> maxHeap(maxHeapComparator);
  cout << "Max Heap: ";
  maxHeap.heapify(array, 8);
  cout << maxHeap.toString() << endl;
  return 0;
}

#ifdef TEST_HASH
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_Hash unitTest;

  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    unitTest.runAllTests();
  } else if (argc == 3) {
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}

void handleTestRandom(int argc, char *argv[]) {
  // HEAPMIT CODE
}
#elif TEST_HEAP
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_Heap unitTest;

  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    std::cout << "Running all unit tests array: ----------\n";
    unitTest.runAllTests();
  } else if (argc == 3) {
    std::cout << "Running unit test array: " << argv[2] << " ----------\n";
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}

void handleTestRandom(int argc, char *argv[]) {
  // HEAPMIT CODE
}
#elif TEST_LAYER
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_Layer unitTest;

  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    std::cout << "Running all unit tests array: ----------\n";
    unitTest.runAllTests();
  } else if (argc == 3) {
    std::cout << "Running unit test array: " << argv[2] << " ----------\n";
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}

void handleTestRandom(int argc, char *argv[]) {
  // HEAPMIT CODE
}
#elif TEST_LOSS
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_Loss unitTest;

  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    std::cout << "Running all unit tests array: ----------\n";
    unitTest.runAllTests();
  } else if (argc == 3) {
    std::cout << "Running unit test array: " << argv[2] << " ----------\n";
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}

void handleTestRandom(int argc, char *argv[]) {
  // HEAPMIT CODE
}
#endif

void printTestCase() {
  std::cout << GREEN << BOLD << "terminal unit test" << RESET << std::endl;
  std::cout << RED << "./main test_unit" << RESET << std::endl;
  std::cout << RED << "./main test_unit nameFunctionUnitTest" << RESET
            << std::endl
            << std::endl;

  // std::cout << GREEN << BOLD << "terminal auto test" << RESET << std::endl;
  // std::cout << RED << "./main test_random number_1 number_2" << RESET
  //           << std::endl;
  // std::cout << RED << "./main test_random number" << RESET << std::endl;
}