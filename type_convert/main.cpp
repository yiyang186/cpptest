#include <cstdio>
#include <cfenv>

using namespace std;

void test_double(double d) {
  float f;
  f = d;
  printf("%.10f\n", f);
  printf("%.10lf\n", d);
}

int main() {
  float a;
  double b = 134.49999597;
  double c = 134.49999;

  #pragma STDC FENV_ACCESS ON
  fesetround(FE_DOWNWARD);
  test_double(b);
  test_double(c);
  
  fesetround(FE_TONEAREST);
  test_double(b);
  test_double(c);
  
  return 0;
}
