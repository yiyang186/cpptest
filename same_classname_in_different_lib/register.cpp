#include <iostream>
#include "register.h"

using namespace std;

void A0::print() { cout << 0 << endl; }


map<string, Creator> &GetRegistry() {
  static map<string, Creator> reg;
  return reg;
}


Register::Register(const string &name, Creator fn) {
  map<string, Creator> &creators = GetRegistry();
  creators[name] = fn;
}

Creator Register::Get(const string &name) {
  map<string, Creator> &creators = GetRegistry();
  return creators[name];
}
