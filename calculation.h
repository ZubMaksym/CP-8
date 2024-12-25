#ifndef CP_8_CALCULATION_H
#define CP_8_CALCULATION_H
#include <math.h>

double calculateFrequency(double L, double C)
{
    return 1.0 / (2.0 * M_PI * sqrt(L* C));
}

#endif //CP_8_CALCULATION_H
