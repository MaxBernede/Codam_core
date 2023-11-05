#include "minirt.h"

float ft_atof(char *nptr)
{
    float result = 0.0;
    float fraction = 0.1;
    int sign = 1;

    while (ft_isspace(*nptr))
        nptr++;
    if (*nptr == '-' && nptr++)
        sign = -1;
    else if (*nptr == '+')
        nptr++;
    while (*nptr >= '0' && *nptr <= '9')
    {
        result = result * 10 + (*nptr - '0');
        nptr++;
    }
    if (*nptr == '.')
    {
        nptr++;
        while (*nptr >= '0' && *nptr <= '9') 
        {
            result += (*nptr - '0') * fraction;
            fraction /= 10.0;
            nptr++;
        }
    }
    return result * sign;
}
