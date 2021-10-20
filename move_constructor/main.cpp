#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

/* 返回函数中的临时变量不要写move
 * 不写move, 编译器会优化在调用出构造，不会复制，
 * 这叫Copy elision
 * 在函数中返回临时变量符合 NRVO, "named return value optimization"
 * 和 RVO, "return value optimization", 编译器会做优化
 * 若写move, 则有的编译器会优化，有的会调用移动构造函数。
 * 经测试，优化后确实比移动构造函数快
 */

struct X {
  X(int m_, int n_): m(m_), n(n_) {}
  int m = 0;
  int n = 0;
};


struct A {
  A() {
    x = new X(0, 0);
  }

  A(int m, int n) {
    x = new X(m, n);
    cout << "create" << endl;
  }

  ~A() {
    if(x != nullptr)
      delete x;
  }

  A(const A &aa) {
    x = new X(aa.x->m, aa.x->n);
    cout << "copy" << endl;
  }

  A(A &&aa) {
    x = aa.x;
    aa.x = nullptr;
    cout << "move" << endl;
  }
  
  X *x = nullptr;
};


A createA0() {
  A a(1, 2);
  return a;
}


A createA1() {
  return A(10, 20);
}


A createA2() {
  A a(1, 2);
  return std::move(a);
}


A createA3() {
  return std::move(A(10, 20));
}

A ga(100, 200);
A createA4() {
  return ga;
}

A createA5() {
  return std::move(ga);
}

vector<A> createVectorA0() {
  vector<A> va(4);
  return va; 
}


vector<A> createVectorA1() {
  vector<A> va(4);
  return std::move(va); 
}


int main() {
  cout << "a0" << endl;
  A a0 = createA0();

  cout << "a1" << endl;
  A a1 = createA1();

  cout << "a2" << endl;
  A a2 = createA2();

  cout << "a3" << endl;
  A a3 = createA3();

  cout << "a4" << endl;
  A a4 = createA4();

  cout << "a5" << endl;
  A a5 = createA5();

  cout << "a6" << endl;
  A a6(a3);

  time_point<system_clock> st, ed;
  cout << "vector A0" << endl;
  st = system_clock::now();
  for(int i = 0; i < 100000; ++i) {
    vector<A> va0 = createVectorA0();
  }
  ed = system_clock::now();
  auto d = duration_cast<microseconds>(ed - st);
  cout << d.count() << "ms" << endl;

  cout << "vector A1" << endl;
  st = system_clock::now();
  for(int i = 0; i < 100000; ++i) {
    vector<A> va1 = createVectorA1();
  }
  ed = system_clock::now();
  d = duration_cast<microseconds>(ed - st);
  cout << d.count() << "ms" << endl;

  return 0;
}
