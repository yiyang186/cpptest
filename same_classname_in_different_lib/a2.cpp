#include <iostream>
#include "register.h"

struct A: public A0 {
  void print() { std::cout << 2 << std::endl; }
};

Register A1("A2", []() { return new A(); });
