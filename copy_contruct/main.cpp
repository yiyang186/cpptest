#include <iostream>
#include <memory>
#include <vector>


using namespace std;

struct A {
  int a;
  int b;
  vector<int> v; 
};

int main() {
  A a({1, 2});
  a.v.push_back(10);
  a.v.push_back(20);
  cout<< a.a << ' ' << a.b << endl;
  cout<< a.v[0] << ' ' << a.v[1] << endl;

  A b(a);
  cout<< b.a << ' ' << b.b << endl;

  auto c = make_shared<A>(a);
  cout<< c->a << ' ' << c->b << endl;
  cout<< c->v[0] << ' ' << c->v[1] << endl;

  b = *c;
  cout<< b.a << ' ' << b.b << endl;
  cout<< b.v[0] << ' ' << b.v[1] << endl;

  return 0;
}
