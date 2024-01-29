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
//+++ Date   : 2021.10.06
//+++ Purpose: implement the user-2 dirichlet boundary condition
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "BCSystem/User2DirichletBC.h"

User2DirichletBC::User2DirichletBC(){
    m_localU.resize(11,0.0);// the maximum dofs of each bc block is 10!
}

void User2DirichletBC::computeBCValue(const FECalcType &calctype,const double &penalty,const double &bcvalue,const nlohmann::json &json,
                                const LocalElmtInfo &elmtinfo,
                                const LocalElmtSolution &elmtsoln,
                                const vector<int> &dofids,
                                Vector &U,
                                SparseMatrix &K,
                                Vector &RHS){
    if(calctype==FECalcType::COMPUTERESIDUAL){
        for(int i=0;i<static_cast<int>(dofids.size());i++){
            RHS.insertValue(dofids[i],0.0);
        }
    }
    else if(calctype==FECalcType::COMPUTEJACOBIAN){
        for(int i=0;i<static_cast<int>(dofids.size());i++){
            K.insertValue(dofids[i],dofids[i],penalty);
        }
    }

    computeU(bcvalue,json,dofids,elmtinfo,elmtsoln,m_localU);
    for(int i=0;i<static_cast<int>(dofids.size());i++){
        U.insertValue(dofids[i],m_localU(i+1));
    }

}

void User2DirichletBC::computeU(const double &bcvalue,const nlohmann::json &json,const vector<int> &dofids,
                          const LocalElmtInfo &elmtinfo,
                          const LocalElmtSolution &elmtsoln,
                          VectorXd &localU){
    if(bcvalue||json.size()||dofids.size()||elmtinfo.m_t||elmtsoln.m_gpU.size()||localU.getM()){}
    //******************************************************
    //*** here you must implement your own dirichlet bc
    //*** please see the example below, where the bcvalue
    //*** should be either defined in your json file or calc
    //*** here as whatever you like
    //******************************************************
    // for(int i=1;i<=static_cast<int>(dofids.size());i++){
    //     localU(i)=bcvalue;
    // }
    MessagePrinter::printErrorTxt("User-2 dirichlet bc has not be implemented yet, please update your code in User1DirichletBC.cpp");
    MessagePrinter::exitAsFem();
}