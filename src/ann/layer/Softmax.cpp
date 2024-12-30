/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt
 * to change this license Click
 * nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this
 * template
 */

/*
 * File:   Softmax.cpp
 * Author: ltsach


g++ -std=c++17 -I "./test" -I "./include" -I "./include/tensor" -I "./include/sformat" -I "./include/ann" -I "./demo" $(find ./src/ann/ -type f -iregex ".*\.cpp") ./src/tensor/*.cpp main.cpp test/unit_test/layer/unit_test_softmax.cpp -o main -DTEST_LAYER



 *
 * Created on August 25, 2024, 2:46 PM
 */

#include "layer/Softmax.h"

#include <filesystem> //require C++17

#include "ann/functions.h"
#include "sformat/fmt_lib.h"
namespace fs = std::filesystem;

Softmax::Softmax(int axis, string name) : m_nAxis(axis)
{
  if (trim(name).size() != 0)
    m_sName = name;
  else
    m_sName = "Softmax_" + to_string(++m_unLayer_idx);
}

Softmax::Softmax(const Softmax &orig) {}

Softmax::~Softmax() {}
// xt::xarray<double> Softmax::forward(xt::xarray<double> Z) {
//   xt::xarray<double> expZ = xt::exp(Z);
//   double sumExpZ = xt::sum(expZ)();
//   xt::xarray<double> m_aCached_Y= expZ / sumExpZ;
//   return m_aCached_Y;;
// }

// xt::xarray<double> Softmax::backward(xt::xarray<double> deltaY) {
//   xt::xarray<double> diagY = xt::diag(m_aCached_Y);

//   xt::xarray<double> T_Y = xt::transpose(m_aCached_Y);

//   xt::xarray<double> jacobian = diagY - xt::linalg::outer(m_aCached_Y, T_Y);

//   xt::xarray<double> DX = xt::linalg::dot(jacobian, deltaY);
//   return DX;

// }

xt::xarray<double> Softmax::forward(xt::xarray<double> X)
{
  xt::xarray<double> Z = xt::zeros_like(X);

  for (std::size_t i = 0; i < X.shape()[0]; ++i)
  {
    auto maxX = xt::amax(xt::view(X, i, xt::all()));
    auto expX = xt::exp(xt::view(X, i, xt::all()) - maxX);

    auto sumExpX = xt::sum(expX);

    xt::view(Z, i, xt::all()) = expX / sumExpX;
  }

  m_aCached_Y = Z;
  return m_aCached_Y;
}

// xt::xarray<double> Softmax::backward(xt::xarray<double> deltaY) {
//   // Tính ma trận chéo của m_aCached_Y
//   xt::xarray<double> diagY = xt::diag(m_aCached_Y);

//   // Tính ma trận Jacobian của hàm softmax
//   xt::xarray<double> T_Y = xt::transpose(m_aCached_Y);
//   xt::xarray<double> jacobian = diagY - xt::linalg::outer(m_aCached_Y, T_Y);

//   // Tính gradient đầu vào
//   xt::xarray<double> DX = xt::linalg::dot(jacobian, deltaY);
//   return DX;
// }

xt::xarray<double> Softmax::backward(xt::xarray<double> deltaY)
{
  xt::xarray<double> Dz = xt::zeros_like(deltaY);
  xt::xarray<double> diagY_stack = diag_stack(m_aCached_Y);

  xt::xarray<double> outerY_stack = outer_stack(m_aCached_Y, m_aCached_Y);

  xt::xarray<double> jacobian_stack = diagY_stack - outerY_stack;

  Dz = matmul_on_stack(jacobian_stack, deltaY);

  return Dz;
}

string Softmax::get_desc()
{
  string desc = fmt::format("{:<10s}, {:<15s}: {:4d}", "Softmax",
                            this->getname(), m_nAxis);
  return desc;
}
