#include <iostream>
using namespace std;

class Visitor;

class Element {
public:
    virtual void accept(Visitor* visitor) = 0;
    virtual ~Element() = default;
};

class ElementA : public Element {
public:
    void accept(Visitor* visitor) override;
    void operationA() {
        cout << "ElementA operation" << endl;
    }
};
class ElementB : public Element {
public:
    void accept(Visitor* visitor) override;
    void operationB() {
        cout << "ElementB operation" << endl;
    }
};
// інтерфейс відвідувача //
class Visitor {
public:
    virtual void visitElementA(ElementA* element) = 0;
    virtual void visitElementB(ElementB* element) = 0;
    virtual ~Visitor() = default;
};
class ConcreteVisitor : public Visitor {
public:
    void visitElementA(ElementA* element) override {
        cout << "Visitor visiting ElementA" << endl;
        element->operationA();
    }
    void visitElementB(ElementB* element) override {
        cout << "Visitor visiting ElementB" << endl;
        element->operationB();
    }
};
void ElementA::accept(Visitor* visitor) {
    visitor->visitElementA(this);
}
void ElementB::accept(Visitor* visitor) {
    visitor->visitElementB(this);
}
int main() {
    ElementA elementA;
    ElementB elementB;
    ConcreteVisitor visitor;

    elementA.accept(&visitor); 
    elementB.accept(&visitor);

    return 0;
}