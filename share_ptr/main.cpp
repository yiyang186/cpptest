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

int main() {
  auto v = foo();

  for(int i = 0; i < v->size(); i++)
    cout << v->at(i) << endl;

  shared_ptr<vector<int>> v1;
  cout << v1->size() << endl;
  return 0;
}
