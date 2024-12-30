#include "loss/CrossEntropy.h"
#include "unit_test.hpp"

map<string, bool (UNIT_TEST_Loss::*)()> UNIT_TEST_Loss::TESTS;

bool UNIT_TEST_Loss::loss01() {
  string name = "loss01";
  // ! data ------------------------------------
  CrossEntropy loss;
  xt::xarray<double> Y = {0.1, 0.9};
  xt::xarray<double> T = {0, 1};

  // ! expect ----------------------------------
  string expect =
      "0.0526802\n\
{-0.      , -0.555555}";

  // ! output ----------------------------------
  stringstream output;
  output << loss.forward(Y, T) << endl;
  output << loss.backward();

  // ! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Loss::loss02() {
  string name = "loss02";
  // ! data ------------------------------------
  CrossEntropy loss;
  xt::xarray<double> Y = {0.2, 0.8};
  xt::xarray<double> T = {0, 1};

  // ! expect ----------------------------------
  string expect =
      "0.111572\n\
{-0.      , -0.625   }";

  // ! output ----------------------------------
  stringstream output;
  output << loss.forward(Y, T) << endl;
  output << loss.backward();

  // ! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Loss::loss03() {
  string name = "loss03";
  // ! data ------------------------------------
  CrossEntropy loss;
  xt::xarray<double> Y = {0.4, 0.6};
  xt::xarray<double> T = {0, 1};

  // ! expect ----------------------------------
  string expect =
      "0.255413\n\
{-0.      , -0.833333}";

  // ! output ----------------------------------
  stringstream output;
  output << loss.forward(Y, T) << endl;
  output << loss.backward();

  // ! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Loss::loss04() {
  string name = "loss04";
  // ! data ------------------------------------
  CrossEntropy loss;
  xt::xarray<double> Y = {0.7, 0.3};
  xt::xarray<double> T = {1, 0};

  // ! expect ----------------------------------
  string expect =
      "0.178337\n\
{-0.714286, -0.      }";

  // ! output ----------------------------------
  stringstream output;
  output << loss.forward(Y, T) << endl;
  output << loss.backward();

  // ! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Loss::loss05() {
  string name = "loss05";
  // ! data ------------------------------------
  CrossEntropy loss;
  xt::xarray<double> Y = {0.9, 0.1};
  xt::xarray<double> T = {1, 0};

  // ! expect ----------------------------------
  string expect =
      "0.0526802\n\
{-0.555555, -0.      }";

  // ! output ----------------------------------
  stringstream output;
  output << loss.forward(Y, T) << endl;
  output << loss.backward();

  // ! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Loss::loss06() {
  string name = "loss06";
  // ! data ------------------------------------
  CrossEntropy loss;
  xt::xarray<double> Y = {0.5, 0.5};
  xt::xarray<double> T = {1, 0};

  // ! expect ----------------------------------
  string expect =
      "0.346573\n\
{-1.      , -0.      }";

  // ! output ----------------------------------
  stringstream output;
  output << loss.forward(Y, T) << endl;
  output << loss.backward();

  // ! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Loss::loss07() {
  string name = "loss07";
  // ! data ------------------------------------
  CrossEntropy loss;
  xt::xarray<double> Y = {0.3, 0.7};
  xt::xarray<double> T = {1, 0};

  // ! expect ----------------------------------
  string expect =
      "0.601986\n\
{-1.666666, -0.      }";

  // ! output ----------------------------------
  stringstream output;
  output << loss.forward(Y, T) << endl;
  output << loss.backward();

  // ! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Loss::loss08() {
  string name = "loss08";
  // ! data ------------------------------------
  CrossEntropy loss;
  xt::xarray<double> Y = {0.05, 0.95};
  xt::xarray<double> T = {0, 1};

  // ! expect ----------------------------------
  string expect =
      "0.0256466\n\
{-0.      , -0.526316}";

  // ! output ----------------------------------
  stringstream output;
  output << loss.forward(Y, T) << endl;
  output << loss.backward();

  // ! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Loss::loss09() {
  string name = "loss09";
  // ! data ------------------------------------
  CrossEntropy loss;
  xt::xarray<double> Y = {0.9, 0.1};
  xt::xarray<double> T = {0, 1};

  // ! expect ----------------------------------
  string expect =
      "1.15129\n\
{-0.      , -4.999995}";

  // ! output ----------------------------------
  stringstream output;
  output << loss.forward(Y, T) << endl;
  output << loss.backward();

  // ! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Loss::loss10() {
  string name = "loss10";
  // ! data ------------------------------------
  CrossEntropy loss;
  xt::xarray<double> Y = {0.2, 0.2};
  xt::xarray<double> T = {0, 1};

  // ! expect ----------------------------------
  string expect =
      "0.804719\n\
{-0.      , -2.499999}";

  // ! output ----------------------------------
  stringstream output;
  output << loss.forward(Y, T) << endl;
  output << loss.backward();

  // ! result ----------------------------------
  return printResult(output.str(), expect, name);
}
