#include <iostream>
#include "register.h"

struct A: public A0 {
  void print() { std::cout << 1 << std::endl; }
};

Register A1("A1", []() { return new A(); });
