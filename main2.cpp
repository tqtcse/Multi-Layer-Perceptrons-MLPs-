/*
 * Assignment 2 - Developing List Data Structures and Artificial Neural Networks
 * file : main.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 17.10.2024

 ! build code :     g++ -fsanitize=hashress -fsanitize=undefined -std=c++17
    -o main -Iinclude -Itest -Isrc
    main.cpp
    test/unit_test/hash/unit_test.cpp
    test/unit_test/heap/unit_test.cpp src/hash/hash.cpp src/heap/heap.cpp
 -DTEST_HASH

 * run code
    * terminal unit test array list
    !./main test_unit
    !./main test_unit nameFunctionUnitTest
*/

#include "main.hpp"
#include "test\unit_test\layer\unit_test_relu.cpp"
// #include "F:\DSA2\ASS2\template\test\unit_test\hash\unit_test.cpp"
// #include "F:\DSA2\ASS2\template\test\unit_test\hash\unit_test.hpp"
// #include "F:\DSA2\ASS2\Multi-layer-perceptrons\test\unit_test\heap\unit_test.hpp"
// #include "F:\DSA2\ASS2\Multi-layer-perceptrons\include\list\DLinkedList.h"
// #include "F:\DSA2\ASS2\Multi-layer-perceptrons\include\list\XArrayList.h"
// #include "F:\DSA2\ASS2\Multi-layer-perceptrons\test\unit_test\layer\unit_test_relu.cpp"
// #include "F:\DSA2\ASS2\Multi-layer-perceptrons\include\ann\layer\ReLU.h"
// #include "F:\DSA2\ASS2\Multi-layer-perceptrons\include\ann\layer\ILayer.h"

int main(int argc, char *argv[]) {
  string name = "layer01";
  ReLU layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{-1.0, 0.0}, {0.0, 1.0}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0., 0.}, {0., 1.}};
  xt::xarray<double> expect_backward = {{0., 0.2}, {0., 1.1}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //output
  // std::cout << "output : " << output.str() << endl;
  // std::cout << "expect : " << expect << endl;
  // if(expect == output.str()) {
  //   cout << "test " + name + " --------------- PASS" <<"\n";
  // } else {
  //   cout << "test " + name + " --------------- FAIL" << "\n";
  // }
}

// g++ -std=c++17 -I "./test" -I "./include" -I "./include/tensor" -I "./include/sformat" -I "./ include/ann" -I "./demo" $(find ./src/ann/ -type f -iregex ".*\.cpp") ./src/tensor/*.cpp main.cpp test/unit_test/layer/unit_test_relu.cpp -o main -DTEST_LAYER
  // *Relu
// g++ -fsanitize=address -std=c++17 -I "./test"  -I "./include" -I "./include/tensor" -I "./include/sformat" -I "./include/ann" -I "./demo" $(find ./src/ann/ -type f -iregex ".*\.cpp") ./src/tensor/*.cpp main.cpp test/unit_test/layer/unit_test_relu.cpp -o main -DTEST_LAYER
  // *Sigmoid
// g++ -fsanitize=address -std=c++17 -I "./test"  -I "./include" -I "./include/tensor" -I "./include/sformat" -I "./include/ann" -I "./demo" $(find ./src/ann/ -type f -iregex ".*\.cpp") ./src/tensor/*.cpp main.cpp test/unit_test/layer/unit_test_sigmoid.cpp -o main -DTEST_LAYER
//   *Tanh
// g++ -fsanitize=address -std=c++17 -I "./test"  -I "./include" -I "./include/tensor" -I "./include/sformat" -I "./include/ann" -I "./demo" $(find ./src/ann/ -type f -iregex ".*\.cpp") ./src/tensor/*.cpp main.cpp test/unit_test/layer/unit_test_tanh.cpp -o main -DTEST_LAYER
//   *Softmax
// g++ -fsanitize=address -std=c++17 -I "./test"  -I "./include" -I "./include/tensor" -I "./include/sformat" -I "./include/ann" -I "./demo" $(find ./src/ann/ -type f -iregex ".*\.cpp") ./src/tensor/*.cpp main.cpp test/unit_test/layer/unit_test_softmax.cpp -o main -DTEST_LAYER
//   *Loss
// g++ -fsanitize=address -std=c++17 -I "./test"  -I "./include" -I "./include/tensor" -I "./include/sformat" -I "./include/ann" -I "./demo" $(find ./src/ann/ -type f -iregex ".*\.cpp") ./src/tensor/*.cpp main.cpp test/unit_test/loss/unit_test_CrossEntropy.cpp -o main -DTEST_LOSS