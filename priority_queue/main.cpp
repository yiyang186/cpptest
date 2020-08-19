#include <iostream>
#include <memory>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
  int val;
  int key;

  Node(int v, int k): val(v), key(k) {}
  bool operator<(const Node &n) {
    return key < n.key;
  }

};


void cout_queue(priority_queue<shared_ptr<Node>> &l) {
  for(auto ll: l) {
    cout << ll->val << ' ' << ll->key << endl;
  }
}


int main() {
  priority_queue<shared_ptr<Node>> q;
  
  q.push(make_shared<Node>(0, 30));
  q.push(make_shared<Node>(1, 5));
  q.push(make_shared<Node>(2, 19));
  q.push(make_shared<Node>(3, 5));
  q.push(make_shared<Node>(4, 0));
  q.push(make_shared<Node>(5, 4));
  q.push(make_shared<Node>(6, 0));

  cout_queue(q);

  auto n = make_shared<Node>(7, 5);
  auto pos = lower_bound(q.begin(), q.end(), n);
  cout << ">>>>> " << (*pos)->val << ' ' << (*pos)->key << endl;

  auto pos1 = upper_bound(q.begin(), q.end(), n);
  cout << ">>>>> " << (*pos1)->val << ' ' << (*pos1)->key << endl;
  
  /*
  list<shared_ptr<Node>> l1;
  pos = lower_bound(l1.begin(), l1.end(), n, compareByKey());
  cout << ">>>>> " << (pos == l1.begin()) << endl;

  pos1 = upper_bound(l1.begin(), l1.end(), n, compareByKey());
  cout << ">>>>> " << (pos1 == l1.end()) << endl;
  // cout << ">>>>>> " << pos - l.begin() << endl;
  */
  
  return 0;
}
