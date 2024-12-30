/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt
 * to change this license Click
 * nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this
 * template
 */

/*
 * File:   Sigmoid.cpp
 * Author: ltsach
 *
 * Created on August 25, 2024, 2:45 PM


g++ -std=c++17 -I "./test" -I "./include" -I "./include/tensor" -I "./include/sformat" -I "./include/ann" -I "./demo" $(find ./src/ann/ -type f -iregex ".*\.cpp") ./src/tensor/*.cpp main.cpp test/unit_test/layer/unit_test_sigmoid.cpp -o main -DTEST_LAYER




 */

#include "layer/Sigmoid.h"

#include "ann/functions.h"
#include "sformat/fmt_lib.h"

Sigmoid::Sigmoid(string name)
{
  if (trim(name).size() != 0)
    m_sName = name;
  else
    m_sName = "Sigmoid_" + to_string(++m_unLayer_idx);
}

Sigmoid::Sigmoid(const Sigmoid &orig)
{
  m_sName = "Sigmoid_" + to_string(++m_unLayer_idx);
}

Sigmoid::~Sigmoid() {}
xt::xarray<double> Sigmoid::forward(xt::xarray<double> X)
{
  m_aCached_Y = 1.0 / (1.0 + xt::exp(-X));
  return m_aCached_Y;
}

xt::xarray<double> Sigmoid::backward(xt::xarray<double> DY)
{
  xt::xarray<double> DX = DY * m_aCached_Y * (1.0 - m_aCached_Y);
  return DX;
}

string Sigmoid::get_desc()
{
  string desc = fmt::format("{:<10s}, {:<15s}:", "Sigmoid", this->getname());
  return desc;
}