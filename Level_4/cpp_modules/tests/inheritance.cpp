#include <iostream>
#include <string>

class A {
public:
    std::string name;
    int age;

    A(const std::string& n, int a) : name(n), age(a) {}
};

class B : virtual public A {
public:
    B() : A("bee", 10) {}
};

class C : virtual public A {
public:
    C() : A("CEE", 5) {}
};

class D : public B, public C {
public:
    D() {
        B::name = "NewName";  // Attribut 'name' hérité de B
        C::age = 42;          // Attribut 'age' hérité de C
    }
};

int main() {
    D diamond;

    std::cout << "Name (from D): " << diamond.name << std::endl;  // Hérité de B : bee
    std::cout << "Age (from D): " << diamond.age << std::endl;    // Hérité de C : 5

    return 0;
}
