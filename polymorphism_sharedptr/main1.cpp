#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct A {
  int x;
};

struct B: A {
  int y;
};

int main() {
  vector<A*> av;
  A *a = new A();
  a->x = 1;
  av.push_back(a);

  B *b = new B();
  b->y = 2;
  av.push_back(b);

  cout << av[0]->x << endl;

  B *bb = static_cast<B*>(av[1]);
  cout << bb->y << endl;
  cout << "Done" << endl;
  return 0;
}
