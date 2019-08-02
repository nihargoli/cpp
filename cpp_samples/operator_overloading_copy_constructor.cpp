#include <iostream>

using namespace std;

class copyCtor
{

    int *p;
    int  p1;
public:
    copyCtor(int &a) {
        p  = new int(a);
        p1 = 20;
    };
    copyCtor(const copyCtor &cp) {
        p = new int(*(cp.p));
        p1 = cp.p1;
    };
    copyCtor & operator = (const copyCtor &cp) {
        p = new int(*(cp.p));
        // p1 = *(cp.p1);
        return *this;
    }

    int operator + (const copyCtor *cp) {
        return (p1 + cp->p1);
    }
    void printP() const {
        cout << *p << " " << p1  << endl;
    }

    void deleteP() {
        delete p;
        p = nullptr;
    }
};

int main()
{

    int a1 = 10;
    int a3 = 11;
    copyCtor c1(a1);
    copyCtor c3(a3);
    cout << c1 + c3 << endl;
    copyCtor c2 = c1;
    c3 = c1;
    c1.printP();
    c1.deleteP();
    c2.printP();
    c2.deleteP();
    c3.printP();
    c3.deleteP();
}
