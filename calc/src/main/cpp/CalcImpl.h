/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CalcImpl.h
 * Author: joebp
 *
 * Created on May 1, 2018, 10:16 AM
 */

#ifndef CALCIMPL_H
#define CALCIMPL_H

#include "tao/corba.h"
#include "../cpp/CalcS.h"

class CalcImpl : virtual public POA_br::org::joe::Calc {
public:
    CalcImpl(uint iterations = 1);
    CalcImpl(const CalcImpl& orig);
    
    CORBA::Double doCalc (CORBA::Double value);
    void shutdown (void);
    
    /// Set the ORB pointer.
    void orb (CORBA::ORB_ptr o);

    virtual ~CalcImpl();
private:
    CORBA::ORB_var orb_;
    uint iterations;
    
    void operator= (const CalcImpl&);
    
    int count;
};

#endif /* CALCIMPL_H */

