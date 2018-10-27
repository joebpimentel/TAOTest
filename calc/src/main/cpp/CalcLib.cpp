/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CalcLib.cpp
 * Author: joebp
 * 
 * Created on May 12, 2018, 4:43 PM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
// #include <boost/date_time/gregorian/gregorian.hpp>
// #include <boost/date_time/date_formatting.hpp>
// #include <boost/date_time/gregorian/greg_month.hpp>
#include "CalcLib.h"

using namespace std;
using namespace boost::posix_time;
ofstream timeslibfile;

void logTimeLibSample(string text, int sample) {
    ptime now(microsec_clock::universal_time());
    timeslibfile << text << ";" << to_iso_string(now) << endl;
}

CalcLib::CalcLib(uint iterations) {
    timeslibfile.open("../timelibsample.dat");
    count = 0;
    this->iterations = iterations;
}

double CalcLib::doCalc (double value) {
    double result;
    count++;
    logTimeLibSample(string("lib entered calc"), count);

    result = value;
    for (int iter = 0; iter < iterations; iter++) {
        result += result / 10.0;
    }
    
    logTimeLibSample(string("lib exiting calc"), count);
    return result;
}

CalcLib::~CalcLib() {
}
