#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <memory>

using namespace std;

int main() {

  map<string, int> m;
  m["a"]++;

  cout << m["a"] << endl;

  m["a"]++;
  cout << m["a"] << endl;

  unordered_map<string, int> umi;

  map<string, vector<int>> mv;
  mv["xx"].push_back(1);
  cout << mv["xx"][0] << endl;

  unordered_map<string, vector<int>> umv;
  umv["xx"].push_back(1);
  cout << umv["xx"][0] << endl;

  vector<int> vv = umv["yy"];
  cout << "vv size: " << vv.size() << endl;

  unordered_map<string, shared_ptr<vector<int>>> umsv;
  shared_ptr<vector<int>> sv = nullptr;
  sv = umsv["oo"];
  if(!sv) {
    cout << "oo is not existed" << endl;
  }

  for(int i = 0; i < 100; i++) {
    m[to_string(i)] = i;
  }

  cout << m.size() << endl;

  for(int i = 0; i < 100; i++) {
    m.erase(to_string(i));
    cout << m.size() << " ";
  }
  cout << endl;
  return 0;
}
