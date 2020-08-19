#include <iostream>
#include <memory>

using namespace std;


struct A {
  int a;
  virtual ~A() {}
};


struct B: public A {
  int b;
  virtual ~B() {}
};


struct C: public B {
  int c;
};


void using_pointer_c(A *a) {
  C *c = (C*)a;
  cout << c->c << endl;
}


void using_pointer(A *a) {
  cout << a->a << endl;

  B *b = (B*)a;
  cout << b->b << endl;

  using_pointer_c(a);
}


void using_shared_pointer_c(shared_ptr<A> a) {
  shared_ptr<C> c = dynamic_pointer_cast<C>(a);
  cout << c->c << endl;
}


void using_shared_pointer(shared_ptr<A> a) {
  cout << a->a << endl;
  
  shared_ptr<B> b = dynamic_pointer_cast<B>(a);
  cout << b->b << endl;

  using_shared_pointer_c(b);
}


int main() {
  C *c = new C();
  c->a = 1;
  c->b = 2;
  c->c = 3;
  using_pointer(c);

  shared_ptr<C> cc = make_shared<C>();
  cc->a = 1;
  cc->b = 2;
  cc->c = 3;
  using_shared_pointer(cc);
  return 0;
}
