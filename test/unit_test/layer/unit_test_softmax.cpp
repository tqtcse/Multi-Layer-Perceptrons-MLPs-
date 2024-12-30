#include "layer/Softmax.h"
#include "unit_test.hpp"

map<string, bool (UNIT_TEST_Layer::*)()> UNIT_TEST_Layer::TESTS;

bool UNIT_TEST_Layer::layer01() {
  string name = "layer1";
  Softmax layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {1, 2, 3};
  xt::xarray<double> DY = {0.1, 0.2, 0.3};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {0.090031, 0.244728, 0.665241};
  xt::xarray<double> expect_backward = {-0.014182, -0.014077, 0.028259};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer02() {
  string name = "layer2";
  Softmax layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {1, 4, 2};
  xt::xarray<double> DY = {0.1, 0.5, 0.4};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {0.04201, 0.843795, 0.114195};
  xt::xarray<double> expect_backward = {-0.015618, 0.023815, -0.008197};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer03() {
  string name = "layer3";
  Softmax layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {2, 2, 2};
  xt::xarray<double> DY = {0.3, 0.3, 0.4};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {0.333333, 0.333333, 0.333333};
  xt::xarray<double> expect_backward = {-0.011111, -0.011111, 0.022222};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer04() {
  string name = "layer4";
  Softmax layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {3, 1, 2};
  xt::xarray<double> DY = {0.5, 0.1, 0.4};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {0.665241, 0.090031, 0.244728};
  xt::xarray<double> expect_backward = {0.040237, -0.030567, -0.00967};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer05() {
  string name = "layer5";
  Softmax layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {0.5, 1.5, 1.0};
  xt::xarray<double> DY = {0.2, 0.3, 0.5};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {0.186324, 0.50648, 0.307196};
  xt::xarray<double> expect_backward = {-0.026608, -0.021681, 0.048289};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer06() {
  string name = "layer6";
  Softmax layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {10, 20, 30};
  xt::xarray<double> DY = {0.0, 1.0, 0.0};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {2.061060e-09, 4.539787e-05,
                                       9.999546e-01};
  xt::xarray<double> expect_backward = {-9.356773e-14, 4.539581e-05,
                                        -4.539581e-05};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer07() {
  string name = "layer7";
  Softmax layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {1, 3, 5};
  xt::xarray<double> DY = {0.2, 0.3, 0.5};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {0.015876, 0.11731, 0.866813};
  xt::xarray<double> expect_backward = {-0.004315, -0.020151, 0.024466};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer08() {
  string name = "layer8";
  Softmax layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {5, 6, 7};
  xt::xarray<double> DY = {0.3, 0.4, 0.3};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {0.090031, 0.244728, 0.665241};
  xt::xarray<double> expect_backward = {-0.002203, 0.018484, -0.01628};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer09() {
  string name = "layer9";
  Softmax layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {2, 3, 1};
  xt::xarray<double> DY = {0.5, 0.3, 0.2};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {0.244728, 0.665241, 0.090031};
  xt::xarray<double> expect_backward = {0.039171, -0.026571, -0.012599};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer10() {
  string name = "layer10";
  Softmax layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {1, 3, 2};
  xt::xarray<double> DY = {0.1, 0.4, 0.5};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {0.090031, 0.665241, 0.244728};
  xt::xarray<double> expect_backward = {-0.026781, 0.001687, 0.025094};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}
