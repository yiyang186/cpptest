#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main() {
  ifstream f("./a.json");
  json data;
  f >> data;

  cout << data["a"] << endl;


  data["b"].push_back("xxx");
  for(auto i: data["b"])
    cout << i << ' ';
  cout << endl;

  std::vector<string> v;
  v.assign(data["b"].begin(), data["b"].end());
  for(auto i: v)
    cout << i << ' ';
  cout << endl;

  return 0;
}
