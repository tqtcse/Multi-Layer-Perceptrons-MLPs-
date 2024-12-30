/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt
 * to change this license Click
 * nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this
 * template
 */

/*
 * File:   CrossEntropy.cpp
 * Author: ltsach
 *
 * Created on August 25, 2024, 2:47 PM
 */

#include "loss/CrossEntropy.h"

#include "ann/functions.h"

CrossEntropy::CrossEntropy(LossReduction reduction) : ILossLayer(reduction) {}

CrossEntropy::CrossEntropy(const CrossEntropy& orig) : ILossLayer(orig) {}

CrossEntropy::~CrossEntropy() {}

double CrossEntropy::forward(xt::xarray<double> X, xt::xarray<double> t) {
  // Todo CODE YOUR
  // int N = X.shape()[0];
  // m_aYtarget = t;
  // m_aCached_Ypred = X;
  // xt::xarray<double> logYpred = xt::log(m_aCached_Ypred + 1e-7);
  // xt::xarray<double> loss = xt::sum(-m_aYtarget * logYpred, -1)/N;
  // return loss[0];
  this->m_aYtarget = t;
  this->m_aCached_Ypred = X;
  return cross_entropy(X, t, m_eReduction == REDUCE_MEAN);
}
xt::xarray<double> CrossEntropy::backward() {
  // Todo CODE YOUR
  int N = m_aCached_Ypred.shape()[0];
  return (-m_aYtarget / (m_aCached_Ypred+ 1e-7))/N;
}