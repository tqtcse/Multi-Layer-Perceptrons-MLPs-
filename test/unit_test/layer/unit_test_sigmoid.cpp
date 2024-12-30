#include "layer/Sigmoid.h"
#include "unit_test.hpp"

map<string, bool (UNIT_TEST_Layer::*)()> UNIT_TEST_Layer::TESTS;

bool UNIT_TEST_Layer::layer01() {
  string name = "layer01";
  Sigmoid layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{-1.0, 0.0}, {0.0, 1.0}};
  xt::xarray<double> DY = {{0.1, 0.2}, {0.3, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.268941, 0.5}, {0.5, 0.731059}};
  xt::xarray<double> expect_backward = {{0.019661, 0.05}, {0.075, 0.078645}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer02() {
  string name = "layer02";
  Sigmoid layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{0.0, 0.0}, {-1.0, 1.0}};
  xt::xarray<double> DY = {{0.5, 0.5}, {0.5, 0.5}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.5, 0.5}, {0.268941, 0.731059}};
  xt::xarray<double> expect_backward = {{0.125, 0.125}, {0.098306, 0.098306}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer03() {
  string name = "layer03";
  Sigmoid layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{1.0, -1.0}, {0.0, 0.0}};
  xt::xarray<double> DY = {{0.0, 0.2}, {0.3, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.731059, 0.268941}, {0.5, 0.5}};
  xt::xarray<double> expect_backward = {{0., 0.039322}, {0.075, 0.1}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer04() {
  string name = "layer04";
  Sigmoid layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{-2.0, -0.5}, {0.5, 2.0}};
  xt::xarray<double> DY = {{0.1, 0.0}, {0.3, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.119203, 0.377541},
                                       {0.622459, 0.880797}};
  xt::xarray<double> expect_backward = {{0.010499, 0.}, {0.070501, 0.041997}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer05() {
  string name = "layer05";
  Sigmoid layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{0.0, 0.5}, {1.0, -1.0}};
  xt::xarray<double> DY = {{0.5, 0.0}, {0.2, 0.3}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.5, 0.622459}, {0.731059, 0.268941}};
  xt::xarray<double> expect_backward = {{0.125, 0.}, {0.039322, 0.058984}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer06() {
  string name = "layer06";
  Sigmoid layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{1.0, 1.0}, {0.0, -1.0}};
  xt::xarray<double> DY = {{0.2, 0.3}, {0.1, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.731059, 0.731059}, {0.5, 0.268941}};
  xt::xarray<double> expect_backward = {{0.039322, 0.058984},
                                        {0.025, 0.078645}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer07() {
  string name = "layer07";
  Sigmoid layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{0.5, 0.5}, {1.0, 1.0}};
  xt::xarray<double> DY = {{0.2, 0.3}, {0.1, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.622459, 0.622459},
                                       {0.731059, 0.731059}};
  xt::xarray<double> expect_backward = {{0.047001, 0.070501},
                                        {0.019661, 0.078645}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer08() {
  string name = "layer08";
  Sigmoid layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{0.5, 0.8}, {0.2, 0.9}};
  xt::xarray<double> DY = {{0.4, 0.1}, {0.3, 0.2}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.622459, 0.689974},
                                       {0.549834, 0.71095}};
  xt::xarray<double> expect_backward = {{0.094001, 0.021391},
                                        {0.074255, 0.0411}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer09() {
  string name = "layer09";
  Sigmoid layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{-1.0, -0.5}, {0.5, 1.0}};
  xt::xarray<double> DY = {{0.0, 0.2}, {0.3, 0.4}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.268941, 0.377541},
                                       {0.622459, 0.731059}};
  xt::xarray<double> expect_backward = {{0., 0.047001}, {0.070501, 0.078645}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}

bool UNIT_TEST_Layer::layer10() {
  string name = "layer10";
  Sigmoid layer;
  stringstream output, expect;

  //! data ------------------------------------
  xt::xarray<double> X = {{0.0, 0.5}, {1.0, -1.0}};
  xt::xarray<double> DY = {{0.1, 0.0}, {0.2, 0.3}};

  xt::xarray<double> output_forward = layer.forward(X);
  xt::xarray<double> output_backward = layer.backward(DY);

  //! expect ----------------------------------
  xt::xarray<double> expect_forward = {{0.5, 0.622459}, {0.731059, 0.268941}};
  xt::xarray<double> expect_backward = {{0.025, 0.}, {0.039322, 0.058984}};
  expect << expect_forward << endl << expect_backward;

  //! output ----------------------------------
  output << output_forward << endl << output_backward;

  //! result ----------------------------------
  return printResult(output.str(), expect.str(), name);
}
