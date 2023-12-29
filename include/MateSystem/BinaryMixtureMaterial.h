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
//+++ Date   : 2022.10.03
//+++ Purpose: Calculate the binary mixture free energy
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once

#include "MateSystem/BulkMaterialBase.h"
#include "MateSystem/FreeEnergyMaterialBase.h"

/**
 * This class calculates the free energy of binary mixture solution
*/
class BinaryMixtureMaterial:public BulkMaterialBase,
                            public FreeEnergyMaterialBase{
public:
    /**
     * Constructor
    */
    BinaryMixtureMaterial();
    /**
     * Deonstructor
    */
    ~BinaryMixtureMaterial();
protected:
    /**
     * Initial the preset material properties, if you don't need the history information of some materials, then you can avoid calling this function
     * @param t_inputparams the input material parameters read from the json file
     * @param t_elmtinfo the data structure for the local element information
     * @param t_elmtsoln the solutions, i.e., U and V of the local element
     * @param Mate the materials (container) to be initialized
     */
    virtual void initMaterialProperties(const nlohmann::json &t_inputparams,
                                        const LocalElmtInfo &t_elmtinfo,
                                        const LocalElmtSolution &t_elmtsoln,
                                        MaterialsContainer &t_mate) override;
    /**
     * Compute the material property accroding to your model
     * @param t_inputparams the input material parameters read from the input file
     * @param t_elmtinfo the data structure for the local element information
     * @param t_elmtsoln the solutions, i.e., U and V of the local element
     * @param t_mateold the materials from previous step
     * @param t_mate the materials to be calculated
     */
    virtual void computeMaterialProperties(const nlohmann::json &t_inputparams,
                                           const LocalElmtInfo &t_elmtinfo,
                                           const LocalElmtSolution &t_elmtsoln,
                                           const MaterialsContainer &t_mateold,
                                           MaterialsContainer &t_mate) override;

private:
    /**
     * Calculate the free energy and its first/second order (partial) derivatives.
     * @param parameters the json parameters read from input file
     * @param args the variables for the free energy expression, it could be concentration or order parameters
     * @param F the system free energy
     * @param dFdargs the first order derivatives of F with respect to its own args
     * @param d2Fdargs2 the second order (partial) derivatives of F with respect to different args, off-diagnoal part for partial derivatives
    */
    virtual void computeFreeEnergyAndDerivatives(const nlohmann::json &parameters,
                                                 const VectorXd &args,
                                                 VectorXd       &F,
                                                 VectorXd       &dFdargs,
                                                 MatrixXd       &d2Fdargs2) override;

private:
    VectorXd m_args;/**< the variables */
    VectorXd m_F;/**< the system free energy*/
    VectorXd m_dFdargs;/**< the first order derivatives of F */
    MatrixXd m_d2Fdargs2;/**< the second order derivatives of F */

    double m_chi;/**< the phase interaction parameter*/

};