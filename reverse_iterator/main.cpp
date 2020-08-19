#include <iostream>
#include <deque>

using namespace std;

int main() {
  deque<int> dq;
  dq.push_back(1);
  dq.push_back(2);
  dq.push_back(3);
  dq.push_back(4);

  for(auto it = dq.begin(); it != dq.end(); ++it) {
    cout << *it << endl;
  }

  cout << endl;

  // auto it = dq.rbegin();
  // while(it != dq.rend()) {   it is reverse_iterator, dq can not erase
  auto it = dq.begin();
  while(it != dq.end()) {
    cout << "see " << *it << endl;
    if(*it == 2) {
      it = dq.erase(it);
    } else {
      ++it;
    }
  }

  for(auto it = dq.begin(); it != dq.end(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
