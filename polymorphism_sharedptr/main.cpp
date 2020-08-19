#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct A {
  int x;
  virtual ~A() {}
};

struct B: A {
  int y;
  ~B() {}
};

int main() {
  vector<shared_ptr<A>> av;
  auto a = make_shared<A>();
  a->x = 1;
  av.push_back(a);

  auto b = make_shared<B>();
  b->y = 2;
  av.push_back(b);

  cout << av[0]->x << endl;

  shared_ptr<B> bb = dynamic_pointer_cast<B>(av[1]);

  cout << bb->y << endl;
  cout << "Done" << endl;
  return 0;
}
