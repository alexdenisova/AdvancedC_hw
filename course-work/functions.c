#include <functions.h>

float f1(float x)
{
  return 0.6 * x + 3;
}

float df1(float x)
{
  return 0.6;
}

float f2(float x)
{
  return (x - 2) * (x - 2) * (x - 2) - 1;
}

float df2(float x)
{
  return 3 * (x - 2) * (x - 2);
}

float f3(float x)
{
  return 3 / x;
}

float df3(float x)
{
  return -3 / x / x;
}

float test_f1(float x)
{
  return x - 1;
}

float dtest_f1(float x)
{
  return 1;
}

float test_f2(float x)
{
  return 0;
}

float dtest_f2(float x)
{
  return 0;
}
