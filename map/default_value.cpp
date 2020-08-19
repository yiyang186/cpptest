#include <iostream>
#include <map>

using namespace std;

int main() {

  map<string, int> m;
  m["a"]++;

  cout << m["a"] << endl;

  m["a"]++;
  cout << m["a"] << endl;
  return 0;
}
