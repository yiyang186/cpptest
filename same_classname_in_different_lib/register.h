#include <dlfcn.h>
#include <map>
#include <iostream>
#include <functional>
#include <memory>

using namespace std;

struct A0{
  virtual void print();
};

using Creator = function<A0* ()>;


map<string, Creator> &GetRegistry();


struct Register {
  Register(const string &name, Creator fn);
  Creator Get(const string &name);
};
