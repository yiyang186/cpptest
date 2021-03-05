#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;


int main() {
  unordered_map<string, int> um;
  um["a"];
  cout << um.size() << endl;

  map<string, int> m;
  m["a"];
  cout << m.size() << endl;

  um.find("y");
  cout << um.size() << endl;

  m.find("y");
  cout << m.size() << endl;

  unordered_map<string, vector<int>> vum;
  vum["a"];
  cout << m.size() << endl;
  cout << vum["a"].size() << endl;

  // vum.at("b");   // Aborted
  return 0;
}
