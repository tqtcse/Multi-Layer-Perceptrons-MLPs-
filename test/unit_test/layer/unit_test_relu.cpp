#include "layer/ReLU.h"
#include "unit_test.hpp"

map<string, bool (UNIT_TEST_Layer::*)()> UNIT_TEST_Layer::TESTS;

bool UNIT_TEST_Layer::layer01() {
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

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer02() {
  string name = "layer02";
  ReLU layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{0.0, 0.0}, {0.0, 0.0}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0., 0.}, {0., 0.}};
  xt::xarray<double> expect_backward = {{0.1, 0.2}, {0., 1.1}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer03() {
  string name = "layer03";
  ReLU layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{-1.0, 0.5}, {0.0, -0.3}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0., 0.5}, {0., 0.}};
  xt::xarray<double> expect_backward = {{0., 0.2}, {0., 0.}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer04() {
  string name = "layer04";
  ReLU layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{100.0, 200.0}, {300.0, 400.0}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{100., 200.}, {300., 400.}};
  xt::xarray<double> expect_backward = {{0.1, 0.2}, {0.0, 1.1}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer05() {
  string name = "layer05";
  ReLU layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{-100.0, -200.0}, {-300.0, -400.0}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.3, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0., 0.}, {0., 0.}};
  xt::xarray<double> expect_backward = {{0., 0.}, {0., 0.}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer06() {
  string name = "layer06";
  ReLU layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{-1.0, 2.0}, {3.0, -4.0}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.0, 1.1}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0., 2.}, {3., 0.}};
  xt::xarray<double> expect_backward = {{0., 0.2}, {0., 0.}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer07() {
  string name = "layer07";
  ReLU layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{-1.0, -0.5}, {0.5, 1.0}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.3, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0., 0.}, {0.5, 1.}};
  xt::xarray<double> expect_backward = {{0., 0.}, {0.3, 0.4}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer08() {
  string name = "layer08";
  ReLU layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{1e-10, 2e-10}, {3e-10, -4e-10}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.3, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{1e-10, 2e-10}, {3e-10, 0.}};
  xt::xarray<double> expect_backward = {{0.1, 0.2}, {0.3, 0.}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer09() {
  string name = "layer09";
  ReLU layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{0.0, 1.0}, {1.0, 0.0}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.3, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0., 1.}, {1., 0.}};
  xt::xarray<double> expect_backward = {{0.1, 0.2}, {0.3, 0.4}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer10() {
  string name = "layer10";
  ReLU layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{0.0, -1.0}, {-2.0, 2.0}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.3, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0., 0.}, {0., 2.}};
  xt::xarray<double> expect_backward = {{0.1, 0.}, {0., 0.4}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}