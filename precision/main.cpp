#include <iostream>
#include <cfenv>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <cfloat>
#include <limits>

// #define FLT_ROUNDS 2  repeated definination
using namespace std;

int to_decimal(string s);
string to_binary(void *x, int num_bytes);

struct FloatNumber {
  char sign;
  string E;
  string M;
  string s;
  int M_offst;
  float forigin;

  FloatNumber() {};
  FloatNumber(float x);
  int getE();
  double getM();
  void print();
  double decimal();
  virtual void print_origin();
};


struct DoubleNumber: FloatNumber {
  double dorigin;

  DoubleNumber(double x);
  void print_origin();
};


int main() {

  cout << FLT_ROUNDS << endl;
  cout << numeric_limits<float>::round_style << endl;
  cout << fegetround() << endl;
  cout << 63./9. << ' ' << 0.63/0.09 << endl;

  float a = 0.000001, b = 0.499999;
  float f;
  double d;

  #pragma STDC FENV_ACCESS ON
  fesetround(FE_TONEAREST);

  FloatNumber fa(a);
  fa.print();

  FloatNumber fb(b);
  fb.print();

  f = a + b;
  FloatNumber ff(f);
  ff.print();

  d = a + b;
  DoubleNumber dd(d);
  dd.print();
  
  #pragma STDC FENV_ACCESS ON
  fesetround(FE_DOWNWARD);
  cout << FLT_ROUNDS << endl;
  cout << numeric_limits<float>::round_style << endl;
  cout << fegetround() << endl;

  f = a + b;
  FloatNumber ff1(f);
  ff1.print();

  d = a + b;
  DoubleNumber dd1(d);
  dd1.print();
  
  return 0;
}


int to_decimal(string s) {
  int d = 0;
  for(int i = 0; i < s.length(); i++) {
    int t = s[s.length() - 1 - i] - '0';
    if(t == 1)
      d += (1 << i);
  }
  return d;
}

string to_binary(void *x, int num_bytes) {
  string ret;
  char *c = (char *)x;
  for(int i = num_bytes - 1; i >= 0; i--) {
    char byte = *(c + i);
    ret += ((bitset<8>)byte).to_string();
  }
  return ret;
}


FloatNumber::FloatNumber(float x) {
  forigin = x;
  s = to_binary(&x, 4);
  sign = s[0];
  E = s.substr(1, 8);
  M = s.substr(9);
  M_offst = 127;
}

int FloatNumber::getE() {
  return to_decimal(E) - M_offst;
}

double FloatNumber::getM() {
  double ret = 1.;
  for(int i = 0; i < M.length(); i++) {
    // cout << ret << endl;
    int t = M[i] - '0';
    if(t == 1)
      ret += pow(2., -double(i + 1));
  }
  return ret;
}

void FloatNumber::print_origin() {
  printf("origin: %f\n", forigin);
}

void FloatNumber::print() {
  // cout << "binary: " << s << endl;
  // cout << "sign: " << sign << endl;
  print_origin();
  printf("E:\t%d\t%s\n", getE(), E.c_str());
  printf("M:\t%lf\t%s\n", getM(), M.c_str());
  // printf("decimal: %.lf\n", decimal());
}

double FloatNumber::decimal() {
  double t = getM() * pow(2., getE());
  if(sign == '1')
    t = -t;
  return t;
}

DoubleNumber::DoubleNumber(double x) {
  dorigin = x;
  s = to_binary(&x, 8);
  sign = s[0];
  E = s.substr(1, 11);
  M = s.substr(12);
  M_offst = 1023;
}

void DoubleNumber::print_origin() {
  printf("origin: %lf\n", dorigin);
}
