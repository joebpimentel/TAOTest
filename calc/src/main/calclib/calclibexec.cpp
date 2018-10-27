/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <sstream>      // std::ostringstream
#include <boost/date_time/posix_time/posix_time.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "../cpp/CalcLib.h"

using namespace std;
using namespace boost::posix_time;
ofstream timesfile;

void logTimeLibSample(std::string text, int sample) {
    ptime now(microsec_clock::universal_time());
    timesfile << text << ";" << to_iso_string(now) << std::endl;
}

int main(int argc, char** argv) {
    timesfile.open("../timelibsample.dat");
    uint interations = 1;
    CalcLib* calc = new CalcLib(interations);
    auto result = 0.0;
    for (auto i = 0; i < 100; i++) {
        logTimeLibSample(string("before_calc"), i);
        result += calc->doCalc(100.0);
        logTimeLibSample(string("after_calc"), i);
        printf("Result: %lf\n", result);
    }
    timesfile.close();

    return 0;
}
