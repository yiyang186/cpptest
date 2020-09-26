#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Base {
public:
  Base() {
    p = make_shared<vector<int>>();
  }

  void add_one() {
    p->push_back(1);
  }

  int size() {
    return p->size();
  }

protected:
  shared_ptr<vector<int>> p;
};


class A: public Base {
public:
  A(): Base() {
    cout << "p pointer: " << p << endl;
    auto pp = p.get();
    cout << "origin p pointer: " << pp << endl;
  }
};

class B: public Base {
public:
  B(): Base() {
    cout << "p pointer: " << p << endl;
    auto pp = p.get();
    cout << "origin p pointer: " << pp << endl;
  }
};

int main() {
  A *a = new A();
  B *b = new B();;

  a->add_one();
  cout << a->size() << endl;
  cout << b->size() << endl;

  Base *base = a;
  base->add_one();
  cout << a->size() << endl;
  cout << b->size() << endl;


  return 0;
}
