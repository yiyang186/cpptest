#include <iostream>
#include <memory>
#include <functional>

using namespace std;

typedef int (*Func)(int a, int b);

struct A {
    Func f;
    int a, b;

    A(Func ff): f(ff), a(1), b(2) {}
    int run() {return f(a, b);}
};

int foo(int a, int b) {
    return a + b;
}

A build_by_lambda() {
    auto c = make_shared<int>(10);
    auto fn = [c](int a, int b) {
        return a + b + *c;
    };

    // function<int(int, int)> func = fn;

    A a(fn);
    return move(a);
}

int main() {
    A a1(foo);
    cout << a1.run() << endl;      

    A a2 = build_by_lambda(); 
    cout << a2.run() << endl;      
    
    return 0;
}
