class Base {
public:
    int x;
    Base(int a) : x(a) {}
    virtual void print() { cout << "This is Base class." << endl; }
};

class Derived : public Base {
public:
    int y;
    Derived(int a, int b) : Base(a), y(b) {}
    void print() override { cout << "This is Derived class." << endl; }
};

int main() {
    Derived d(10, 20);
    Base* b = &d; // Upcasting: Derived to Base

    // Static cast
    Derived* d1 = static_cast<Derived*>(b);
    d1->print(); // This is Derived class.

    // Dynamic cast
    Derived* d2 = dynamic_cast<Derived*>(b);
    if (d2) {
        d2->print(); // This is Derived class.
    }

    // Reinterpret cast
    Base* b2 = new Base(100);
    Derived* d3 = reinterpret_cast<Derived*>(b2);
    d3->print(); // This is Derived class. (Undefined behavior!)

    // Const cast
    const Base* b3 = &d;
    Base* b4 = const_cast<Base*>(b3);
    b4->print(); // This is Derived class. (Undefined behavior!)

    return 0;
}
