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
#include "tao/corba.h"
#include "../cpp/CalcC.h"
#include "../cpp/CalcImpl.h"

using namespace std;
using namespace boost::posix_time;
ofstream timesfile;

void logTimeSample(std::string text, int sample) {
    ptime now(microsec_clock::universal_time());
    timesfile << text << ";" << to_iso_string(now) << std::endl;
}

int main(int argc, char** argv) {
    timesfile.open("../timeclientsample.dat");

    // Declare ORB
    CORBA::ORB_var orb;
    try {
        string in;
        ifstream serverIofFile;
        serverIofFile.open("../server.ior");
        serverIofFile >> in;
        serverIofFile.close();

        // Initialize the ORB
        orb = CORBA::ORB_init(argc, argv);
        CORBA::Object_var tmp = orb->string_to_object(in.c_str());
        br::org::joe::Calc_var calc = br::org::joe::Calc::_narrow(tmp.in());
        if (CORBA::is_nil(calc.in())) {
            printf("Nil Test::Hello reference\n");
            return 1;
        }

        auto result = 0.0;
        for (auto i = 0; i < 100; i++) {
            logTimeSample(string("before_calc"), i);
            result += calc->doCalc(100.0);
            logTimeSample(string("after_calc"), i);
            printf("Result: %lf\n", result);
        }
        // End CORBA
    } catch (const CORBA::Exception& ex) {
        ex._tao_print_exception("Exception caught:");
        return 1;
    }
    timesfile.close();

    return 0;
}
