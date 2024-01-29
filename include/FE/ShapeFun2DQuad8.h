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
//+++ Date   : 2022.05.14
//+++ Purpose: 2d quad8 shape function
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once

#include "FE/ShapeFun2DBase.h"

/**
 * This class implement the quad8's shape function calculation
 */
class ShapeFun2DQuad8:public ShapeFun2DBase{
public:
    ShapeFun2DQuad8();

protected:
    /**
     * this virtual function responsible for the calculation of 1d shape function and its local derivatives
     * @param xi \f$\xi\f$ for local coordinate
     * @param eta \f$\eta\f$ for local coordinate
     * @param t_shpvals the vector of shape function values
     * @param t_shpders the vector of shape function's local derivatives, \f$\frac{dN}{d\xi},\frac{dN}{d\eta}\f$
     */
    virtual void calc2DShapeValsAndDerivatives(const double &xi,const double &eta,vector<double> &t_shpvals,vector<Vector3d> &t_shpders) override;


};