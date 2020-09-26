#include <iostream>
#include <memory>
#include <vector>

using namespace std;

shared_ptr<vector<int>> foo() {
  auto v = make_shared<std::vector<int>>(10);
  
  for(int i = 0; i < v->size(); i++)
    v->at(i) = i;

  return v;
}

class B {
public:
  int b;

  B(int b_): b(b_) {}
};

class A {
public:
  B b;
  vector<B> bs;
};


int main() {
  auto v = foo();

  for(int i = 0; i < v->size(); i++)
    cout << v->at(i) << endl;

  shared_ptr<vector<int>> v1;
  // cout << v1->size() << endl;

  A a;
  a.bs.push_back(B(1));
  a.bs.push_back(B(2));
  a.bs.push_back(B(3));

  vector<vector<B>::Iterator> bs;
  bs.push_back(a.bs.begin());
  bs.push_back(a.bs.begin() + 1);
  bs.push_back(a.bs.begin() + 2);

  for(auto b: bs) {
    cout << b->b << ' ';
  }
  cout << endl;
  return 0;
}
