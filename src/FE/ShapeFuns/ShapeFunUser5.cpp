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
//+++ Purpose: defines the user-defined (5) shape functions in AsFem
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "FE/ShapeFunUser5.h"

void ShapeFunUser5::calcShapeValsAndDerivatives(const double &xi,const double &eta,const double &zeta,
                                                vector<double> &t_shpvals,
                                                vector<Vector3d> &t_shpders){
    //****************************************
    //*** get rid of unused warning
    //****************************************
    if(xi||eta||zeta||t_shpvals.size()||t_shpders.size()){}

    //********************************************
    //*** please provide 
    //***   1) shape function value 
    //***   2) their local derivatives (w.r.t xi,eta,zeta not x,y,z !!!)
    //*** this subroutine will be called in ShapeFunUser class
    //********************************************

}