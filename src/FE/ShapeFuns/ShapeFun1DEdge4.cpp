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
//+++ Purpose: implement the edge4 shape fun and its local derivatives
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "FE/ShapeFun1DEdge4.h"

ShapeFun1DEdge4::ShapeFun1DEdge4(){
}

void ShapeFun1DEdge4::calc1DShapeValsAndDerivatives(const double &xi,vector<double> &t_shpvals,vector<Vector3d> &t_shpders){
    if(t_shpvals.size()<4 || t_shpders.size()<4){
        MessagePrinter::printErrorTxt("your shape val or derivs vector size is smaller than 4, error detected in Shape1DEdge4.cpp");
        MessagePrinter::exitAsFem();
    }
    /**
     * The nodes should look like:
     * 1---2---3---4
    */
    // the details can be found here: http://www.sd.ruhr-uni-bochum.de/downloads/Shape_funct.pdf
    t_shpvals[1-1]=-(3.0*xi+1.0)*(3.0*xi-1.0)*(    xi-1.0)/16.0;
    t_shpders[1-1](1)=-27.0*xi*xi/16.0+9.0*xi/8.0+ 1.0/16.0;
    t_shpders[1-1](2)= 0.0;
    t_shpders[1-1](3)= 0.0;

    t_shpvals[2-1]=(3.0*xi+3.0)*(3.0*xi-1.0)*(3.0*xi-3.0)/16.0;
    t_shpders[2-1](1)= 81.0*xi*xi/16.0-9.0*xi/8.0-27.0/16.0;
    t_shpders[2-1](2)= 0.0;
    t_shpders[2-1](3)= 0.0;

    t_shpvals[3-1]=-(3.0*xi+3.0)*(3.0*xi+1.0)*(3.0*xi-3.0)/16.0;
    t_shpders[3-1](1)=-81.0*xi*xi/16.0-9.0*xi/8.0+27.0/16.0;
    t_shpders[3-1](2)= 0.0;
    t_shpders[3-1](3)= 0.0;

    t_shpvals[4-1]=(    xi+1.0)*(3.0*xi+1.0)*(3.0*xi-1.0)/16.0;
    t_shpders[4-1](1)= 27.0*xi*xi/16.0+9.0*xi/8.0- 1.0/16.0;
    t_shpders[4-1](2)= 0.0;
    t_shpders[4-1](3)= 0.0;
    
}