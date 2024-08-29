#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <roots.h>

// Ищет корень по методу касательных
float root(float (*f)(float), float (*g)(float), float a, float b, float eps, float (*df)(float), float (*dg)(float), uint32_t *iterations)
{
  float func(float x)
  {
    return f(x) - g(x);
  }
  float dfunc(float x)
  {
    return df(x) - dg(x);
  }
  float diff = func(a) / dfunc(a);
  float x1, x0;
  if (diff > 0)
  {
    x1 = b - diff;
    x0 = b;
  }
  else
  {
    x1 = a - diff;
    x0 = a;
  }
  *iterations = 1;
  while (fabs(x0 - x1) > eps && a <= x1 && x1 <= b)
  {
    x0 = x1;
    x1 = x1 - func(x1) / dfunc(x1);
    (*iterations)++;
  }
  if (fabs(x0 - x1) > eps)
  {
    printf("Could not find root in [%.3f, %.3f]\n", a, b);
    exit(1);
  }
  return x1;
}
