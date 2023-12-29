//****************************************************************
//* This file is part of the AsFem framework
//* Advanced Simulation kit based on Finite Element Method (AsFem)
//* All rights reserved, Yang Bai/MM-Lab@CopyRight 2020-present
//* https://github.com/MatMechLab/AsFem
//* Licensed under GNU GPLv3, please see LICENSE for details
//* https://www.gnu.org/licenses/gpl-3.0.en.html
//****************************************************************
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ Author : Yang Bai
//+++ Date   : 2022.05.22
//+++ Purpose: defines the base class of user-defined shape functions 
//+++          in AsFem
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#include "Utils/MessagePrinter.h"
#include "MathUtils/Vector3d.h"

using std::vector;
using std::abs;
using std::sqrt;

/**
 * The base class for user-defined shape function
 */
class ShapeFunUserBase{
public:
    /**
     * this virtual function responsible for the calculation of 1d shape function and its local derivatives
     * @param xi \f$\xi\f$ for local coordinate
     * @param eta \f$\eta\f$ for local coordinate
     * @param zeta \f$\zeta\f$ for local coordinate
     * @param t_shpvals the vector of shape function values
     * @param t_shpders the vector of shape function's local derivatives, \f$\frac{dN}{d\xi},\frac{dN}{d\eta}\f$
     */
    virtual void calcShapeValsAndDerivatives(const double &xi,const double &eta,const double &zeta,vector<double> &t_shpvals,vector<Vector3d> &t_shpders)=0;

};