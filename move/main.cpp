#include <iostream>
#include <queue>

using namespace std;

struct A {
    int a;
    int b;
};

struct B {
    int a;
    int b;
};

queue<pair<A, B>> q;

void test(int x, int y) {
    A a{x, y};
    B b{x, y};
    auto p = make_pair<A, B>(move(a), move(b)); // no meaning
    q.push(move(p));
}

int main() {
    test(1, 2);
    auto &x = q.front();

    cout << x.first.a << " " << x.second.b << endl;

    return 0;
}
