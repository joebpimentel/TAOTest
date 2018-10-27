/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CalcImpl.cpp
 * Author: joebp
 * 
 * Created on May 1, 2018, 10:16 AM
 */

#include <iostream>
#include <fstream>
#include <ostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/date_formatting.hpp>
#include <boost/date_time/gregorian/greg_month.hpp>
#include "CalcImpl.h"
ofstream timesfile;

using namespace std;
using namespace boost::posix_time;
using namespace boost::gregorian;

void logTimeSample(string text, int sample) {
    ptime now(microsec_clock::universal_time());
    timesfile << text << ";" << to_iso_string(now) << std::endl;
}

CalcImpl::CalcImpl(uint iterations) {
    timesfile.open("../timeserversample.dat");
    count = 0;
    this->iterations = iterations;
}

CalcImpl::CalcImpl(const CalcImpl& orig) {
    orb_ = CORBA::ORB::_duplicate(orig.orb_);
    iterations = orig.iterations;
}

CORBA::Double CalcImpl::doCalc (CORBA::Double value) {
    CORBA::Double result;
    count++;
    logTimeSample(string("entered calc"), count);

    result = value;
    for (int iter = 0; iter < iterations; iter++) {
        result += result / 10.0;
    }
    
    logTimeSample(string("exiting calc"), count);
    return result;
}

// Set the ORB pointer.

void CalcImpl::orb (CORBA::ORB_ptr o)
{
  this->orb_ = CORBA::ORB::_duplicate (o);
}

void CalcImpl::shutdown() {
    orb_->shutdown();
}

CalcImpl::~CalcImpl() {
}

