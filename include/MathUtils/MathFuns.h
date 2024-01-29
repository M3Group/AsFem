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
//+++ Date   : 2021.01.17
//+++ Purpose: Implement some commonly used mathematic functions
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once

#include <cmath>
#include "Utils/MessagePrinter.h"

using std::abs;

/**
 * This class offers some general functions for math calc.
*/
class MathFuns{
public:
    /**
     * constructor
    */
    MathFuns();

    /**
     * The positive bracket operator
     * @param x the scalar args
    */
    static double bracketPos(const double &x);
    /**
     * The negative bracket operator
     * @param x the scalar args
    */
    static double bracketNeg(const double &x);

    /**
     * The sign function
    */
    static double sign(const double &x);

};