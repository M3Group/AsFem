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
//+++ Date   : 2022.10.26
//+++ Purpose: This class carry out the side integration for the user-1
//+++          defined calculation.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once

#include "Postprocess/SideIntegralPostprocessorBase.h"

/**
 * This class implements the side integral for the user-1 defined calculation/formulation.
 */
class User1SideIntegralPostprocessor:public SideIntegralPostprocessorBase{
protected:
    /**
     * compute the nodal value for nodal pps
     * @param dofid the global dof id, start from 1
     * @param nodeid the global node id, starts from 1
     * @param t_parameters the parameters from json
     * @param t_elmtinfo the local element info
     * @param t_shp the local shape function
     * @param t_soln the solution class
     * @param t_projsystem the projection class
     */
    virtual double computeSideIntegralValue(const int &dofid,
                                            const int &nodeid,
                                            const nlohmann::json &t_parameters,
                                            const LocalElmtInfo &t_elmtinfo,
                                            const LocalShapeFun &t_shp,
                                            SolutionSystem &t_soln,
                                            ProjectionSystem &t_projsystem) override;

private:
    double m_ppsvalue=0.0;/** the postprocess result */                      
};