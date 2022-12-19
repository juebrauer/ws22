#include <iostream>

class A {
    public:
    A()
    {
        std::cout << "ctor of A() called.\n";
    }
    virtual void foo() = 0;
    virtual void foo2() = 0;
};


class C: public A {
    public:
    C()
    {
        std::cout << "ctor of C() called.\n";
    }
    void foo() {
        std::cout << "foo() of class C called.\n";
    }
   
};

int main() {

    C* c1 = new C();
  
}