/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt
 * to change this license Click
 * nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this
 * template
 */

/*
 * File:   Tanh.cpp
 * Author: ltsach
 *



g++ -std=c++17 -I "./test" -I "./include" -I "./include/tensor" -I "./include/sformat" -I "./include/ann" -I "./demo" $(find ./src/ann/ -type f -iregex ".*\.cpp") ./src/tensor/*.cpp main.cpp test/unit_test/layer/unit_test_tanh.cpp -o main -DTEST_LAYER


 * Created on September 1, 2024, 7:03 PM
 */

#include "layer/Tanh.h"

#include "ann/functions.h"
#include "sformat/fmt_lib.h"

Tanh::Tanh(string name)
{
  if (trim(name).size() != 0)
    m_sName = name;
  else
    m_sName = "Tanh_" + to_string(++m_unLayer_idx);
}

Tanh::Tanh(const Tanh &orig) { m_sName = "Tanh_" + to_string(++m_unLayer_idx); }

Tanh::~Tanh() {}

xt::xarray<double> Tanh::forward(xt::xarray<double> X)
{
  m_aCached_Y = xt::tanh(X);

  return m_aCached_Y;
}
xt::xarray<double> Tanh::backward(xt::xarray<double> DY)
{
  xt::xarray<double> DX = DY * (1 - xt::square(m_aCached_Y));

  return DX;
}

string Tanh::get_desc()
{
  string desc = fmt::format("{:<10s}, {:<15s}:", "Tanh", this->getname());
  return desc;
}
