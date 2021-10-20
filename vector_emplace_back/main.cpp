#include <iostream>
#include <vector>

using namespace std;

struct A {
  A() {
    cout << "construct" << endl;
  }

  A(const A &a) {
    val = a.val;
    cout << "copy" << endl;
  }

  A(A &&a) {
    val = a.val;
    a.val = 0;
    cout << "move" << endl;
  }

  int val = 0;
};


int main() {
  vector<A> va;
  va.reserve(10);                // avoid vector increasing

  cout << ">> push_back" << endl;
  va.push_back(A());             // construct, move

  cout << ">> emplace_back" << endl;
  va.emplace_back(A());          // construct, move

  cout << ">> push_back a" << endl;
  A a;                           // construct
  va.push_back(a);               // copy

  cout << ">> emplace_back a" << endl;
  A a1;                          // construct
  va.emplace_back(a1);           // copy

  cout << ">> move push_back a" << endl;
  A b;                           // construct
  va.push_back(std::move(b));    // move

  cout << ">> move emplace_back a" << endl;
  A c;                           // construct
  va.emplace_back(std::move(c)); // move
  return 0;
}
