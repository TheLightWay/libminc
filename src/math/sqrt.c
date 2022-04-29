#include <math.h>

double sqrt(double n)
{
    double sqrt = n / 2;
    double temp = sqrt;

    while (sqrt != temp)
    {
        temp = sqrt;
        sqrt = (n / sqrt + sqrt) / 2;
    }

    return sqrt;
}
