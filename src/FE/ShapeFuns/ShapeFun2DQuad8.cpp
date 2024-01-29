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

#include "FE/ShapeFun2DQuad8.h"

ShapeFun2DQuad8::ShapeFun2DQuad8(){}

void ShapeFun2DQuad8::calc2DShapeValsAndDerivatives(const double &xi,const double &eta,vector<double> &t_shpvals,vector<Vector3d> &t_shpders){
    if(t_shpvals.size()<8 || t_shpders.size()<8){
        MessagePrinter::printErrorTxt("your shape val or derivs vector size is smaller than 8, error detected in ShapeFun2DQuad8.cpp");
        MessagePrinter::exitAsFem();
    }
    /**
     * VTK Cell type: vtkQuadraticQuad
     * The nodes should look like:
     * 4---7---3
     * |       |
     * 8       6
     * |       |
     * 1---5---2
    */
    t_shpvals[1-1]=(1.0-xi)*(1.0-eta)*(-xi-eta-1.0)/4.0;
    t_shpders[1-1](1)= (1.0-eta)*(2.0*xi+eta)/4.0;
    t_shpders[1-1](2)= (1.0-xi )*(xi+2.0*eta)/4.0;
    t_shpders[1-1](3)= 0.0;

    t_shpvals[2-1]=(1.0+xi)*(1.0-eta)*( xi-eta-1.0)/4.0;
    t_shpders[2-1](1)= (1.0-eta)*(2.0*xi-eta)/4.0;
    t_shpders[2-1](2)= (1.0+xi )*(2.0*eta-xi)/4.0;
    t_shpders[2-1](3)= 0.0;

    t_shpvals[3-1]=(1.0+xi)*(1.0+eta)*( xi+eta-1.0)/4.0;
    t_shpders[3-1](1)= (1.0+eta)*(2.0*xi+eta)/4.0;
    t_shpders[3-1](2)= (1.0+xi )*(xi+2.0*eta)/4.0;
    t_shpders[3-1](3)= 0.0;

    t_shpvals[4-1]=(1.0-xi)*(1.0+eta)*(-xi+eta-1.0)/4.0;
    t_shpders[4-1](1)= (1.0+eta)*(2.0*xi-eta)/4.0;
    t_shpders[4-1](2)= (1.0-xi )*(2.0*eta-xi)/4.0;
    t_shpders[4-1](3)= 0.0;

    t_shpvals[5-1]=(1.0-xi*xi)*(1.0-eta    )/2.0;
    t_shpders[5-1](1)= xi*(eta-1.0);
    t_shpders[5-1](2)= (xi*xi-1.0)/2.0;
    t_shpders[5-1](3)= 0.0;

    t_shpvals[6-1]=(1.0+xi   )*(1.0-eta*eta)/2.0;
    t_shpders[6-1](1)= (1.0-eta*eta)/2.0;
    t_shpders[6-1](2)=-(1.0+xi)*eta;
    t_shpders[6-1](3)= 0.0;

    t_shpvals[7-1]=(1.0-xi*xi)*(1.0+eta    )/2.0;
    t_shpders[7-1](1)=-xi*(1.0+eta);
    t_shpders[7-1](2)= (1.0-xi*xi)/2.0;
    t_shpders[7-1](3)= 0.0;

    t_shpvals[8-1]=(1.0-xi   )*(1.0-eta*eta)/2.0;
    t_shpders[8-1](1)= (eta*eta-1.0)/2.0;
    t_shpders[8-1](2)= (xi-1.0)*eta;
    t_shpders[8-1](3)= 0.0;

}
