#include <iostream>
#include <memory>
#include <algorithm>
#include <list>

using namespace std;

struct Node {
  int val;
  int key;

  Node(int v, int k): val(v), key(k) {}
  bool operator<(const Node &n) {
    return key < n.key;
  }

};


struct compareByKey {
  bool operator()(const shared_ptr<Node> &n1, const shared_ptr<Node> &n2) {
    return n1->key < n2->key;
  }
};

void cout_list(list<shared_ptr<Node>> &l) {
  for(auto ll: l) {
    cout << ll->val << ' ' << ll->key << endl;
  }
}


int main() {
  list<shared_ptr<Node>> l;
  
  l.push_back(make_shared<Node>(0, 0));
  l.push_back(make_shared<Node>(1, 0));
  l.push_back(make_shared<Node>(2, 4));
  l.push_back(make_shared<Node>(3, 5));
  l.push_back(make_shared<Node>(4, 5));
  l.push_back(make_shared<Node>(5, 19));
  l.push_back(make_shared<Node>(6, 30));

  cout_list(l);

  auto n = make_shared<Node>(7, 5);
  auto pos = lower_bound(l.begin(), l.end(), n, compareByKey());
  cout << ">>>>> " << (*pos)->val << ' ' << (*pos)->key << endl;

  auto pos1 = upper_bound(l.begin(), l.end(), n, compareByKey());
  cout << ">>>>> " << (*pos1)->val << ' ' << (*pos1)->key << endl;
  // cout << ">>>>>> " << pos - l.begin() << endl;
  
  list<shared_ptr<Node>> l1;
  pos = lower_bound(l1.begin(), l1.end(), n, compareByKey());
  cout << ">>>>> " << (pos == l1.begin()) << endl;

  pos1 = upper_bound(l1.begin(), l1.end(), n, compareByKey());
  cout << ">>>>> " << (pos1 == l1.end()) << endl;
  // cout << ">>>>>> " << pos - l.begin() << endl;
  
  return 0;
}
