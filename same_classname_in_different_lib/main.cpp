#include <dlfcn.h>
#include "register.h"

using namespace std;

int main(int argc, char *argv[]) {
  for(int i = 1; i < argc; i += 1) {
    cout << "dlopen " << argv[i] << endl;
    void *handle = dlopen(argv[i], RTLD_NOW | RTLD_LOCAL);
    if(handle == nullptr) {
      cout << "invalid lib: " << argv[i] << endl;
    }
  }

  map<string, Creator> &reg = GetRegistry();

  cout << "get A1" << endl;
  A0 *a1 = reg["A1"]();
  a1->print();

  cout << "-------" << endl;

  cout << "get A2" << endl;
  A0 *a2 = reg["A2"]();
  a2->print();
  
  return 0;
}

