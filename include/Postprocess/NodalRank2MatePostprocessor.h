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
//+++ Date   : 2022.09.28
//+++ Purpose: Get the nodal rank2 material value via its node id for pps
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once

#include "Postprocess/NodalPostprocessorBase.h"

/**
 * This class access the nodal's rank2 material value via its global node id
 */
class NodalRank2MatePostprocessor:public NodalPostprocessorBase{
protected:
    /**
     * compute the nodal value for nodal pps
     * @param dofid the local dof id, start from 1
     * @param t_parameters the parameters from json
     * @param t_dofhandler the dofHandler class
     * @param t_soln the solution class
     * @param t_projsystem the projection class
     */
    virtual double computeNodalValue(const int &dofid,
                                     const nlohmann::json &t_parameters,
                                     const DofHandler &t_dofhandler,
                                     SolutionSystem &t_soln,
                                     ProjectionSystem &t_projsystem) override;

private:
    int m_nodeid=0;/**< the global node id */
    int m_i=1;/**< the i index of the specific rank2 tensor */
    int m_j=1;/**< the j index of the specific rank2 tensor */
    string m_rank2matename="";/**< the string name of the scalar material */
    Rank2Tensor m_pps_value=0.0;/**< the postprocess result */

};