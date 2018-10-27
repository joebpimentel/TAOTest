/*
 * File:   CalcLib.h
 * Author: joebp
 *
 * Created on May 12, 2018, 4:43 PM
 */

#ifndef CALCLIB_H
#define CALCLIB_H
class CalcLib {
    public:
        CalcLib(uint iterations);

        double doCalc(double value);

        virtual ~CalcLib();

    private:
        uint iterations;
        int count;
};
#endif /* CALCLIB_H */
