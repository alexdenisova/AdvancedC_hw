#ifndef roots
#define roots

#include <stdint.h>

float root(float (*f)(float), float (*g)(float), float a, float b, float eps, float (*df)(float), float (*dg)(float), uint32_t *iterations);

#endif
