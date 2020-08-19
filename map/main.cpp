#include <iostream>
#include <map>
#include <list>

using namespace std;

int main() {
  list<int> l;
  map<list<int>::iterator, int> m;

  l.push_front(1);
  l.push_front(2);
  l.push_front(3);
  l.push_front(4);

  for(auto it = l.begin(); it != l.end(); ++it) {
    m[it] = *it;
  }

  for(auto it = m.begin(); it != m.end(); ++it) {
    cout << it->second << ' ';
  }
  cout << endl;

  return 0;
}
