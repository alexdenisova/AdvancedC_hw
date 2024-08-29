#include <math.h>
#include <stdio.h>
#include <roots.h>

// Считает интеграл по методу Симпсона
float integral(float (*f)(float), float a, float b, float eps)
{
  float sum = 0;
  float min = a, max = b;
  if (a > b)
  {
    min = b;
    max = a;
  }
  for (float x = min; x < max - eps; x += eps)
  {
    sum += eps / 6.0 * (f(x) + 4.0 * f(0.5 * (x + x + eps)) + f(x + eps));
  }
  return sum;
}
