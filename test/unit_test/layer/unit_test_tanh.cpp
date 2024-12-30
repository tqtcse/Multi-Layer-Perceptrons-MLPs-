#include "layer/Tanh.h"
#include "unit_test.hpp"

map<string, bool (UNIT_TEST_Layer::*)()> UNIT_TEST_Layer::TESTS;

bool UNIT_TEST_Layer::layer01() {
  string name = "layer1";
  Tanh layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{1, 2}, {3, 4}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.761594, 0.964028},
                                       {0.995055, 0.999329}};
  xt::xarray<double> expect_backward = {{0.041997, 0.01413}, {0.0, 0.001475}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer02() {
  string name = "layer2";
  Tanh layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{0, 0}, {0, 0}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.0, 0.0}, {0.0, 0.0}};
  xt::xarray<double> expect_backward = {{0.1, 0.2}, {0.0, 1.1}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer03() {
  string name = "layer3";
  Tanh layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{-1, -2}, {-3, -4}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{-0.761594, -0.964028},
                                       {-0.995055, -0.999329}};
  xt::xarray<double> expect_backward = {{0.041997, 0.01413}, {0.0, 0.001475}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer04() {
  string name = "layer4";
  Tanh layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{2, 3}, {4, 5}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.964028, 0.995055},
                                       {0.999329, 0.999909}};
  xt::xarray<double> expect_backward = {{0.007065, 0.001973}, {0.0, 0.0002}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer05() {
  string name = "layer5";
  Tanh layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{5, 6}, {7, 8}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.999909, 0.999988}, {0.999998, 1.0}};
  xt::xarray<double> expect_backward = {{1.815832e-05, 4.915309e-06},
                                        {0.0, 4.951547e-07}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer06() {
  string name = "layer6";
  Tanh layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{-5, -6}, {-7, -8}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{-0.999909, -0.999988},
                                       {-0.999998, -1.0}};
  xt::xarray<double> expect_backward = {{1.815832e-05, 4.915309e-06},
                                        {0.0, 4.951547e-07}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer07() {
  string name = "layer7";
  Tanh layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{0.5, 0.1}, {-0.5, -0.1}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.462117, 0.099668},
                                       {-0.462117, -0.099668}};
  xt::xarray<double> expect_backward = {{0.078645, 0.198013}, {0.0, 1.089073}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer08() {
  string name = "layer8";
  Tanh layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{-0.5, -0.1}, {0.5, 0.1}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{-0.462117, -0.099668},
                                       {0.462117, 0.099668}};
  xt::xarray<double> expect_backward = {{0.078645, 0.198013}, {0.0, 1.089073}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer09() {
  string name = "layer9";
  Tanh layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{20, 20}, {20, 20}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{1.0, 1.0}, {1.0, 1.0}};
  xt::xarray<double> expect_backward = {{0., 0.}, {0., 0.}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer10() {
  string name = "layer10";
  Tanh layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{10, -10}, {5, -5}};
  xt::xarray<double> DY = {{0.5, 0.3}, {0.2, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{1.0, -1.0}, {0.999909, -0.999909}};
  xt::xarray<double> expect_backward = {{4.122307e-09, 2.473384e-09},
                                        {3.631665e-05, 7.263329e-05}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}
