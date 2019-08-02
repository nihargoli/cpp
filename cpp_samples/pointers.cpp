#include <iostream>
#include <memory>
#include <utility>
#include <new>

using namespace std;

class testClass
{

private:
    int testNum;

protected:
    int printTestNum() {
        cout << testNum << endl;
    }

public:
    int setTestNum(int &testNumRef) {
        testNum = testNumRef;
    }

};

class inheritedTestClass : public testClass {

public:
    int setTestNumFromInheritedClass(int num) {
        //testNum = num; not possible
        setTestNum(num);
    }
    int printTestNumFromInheritedClass() { 
        printTestNum();
    }

};

int main(int argc, char *argv[])
{

    // object is destroyed since we have used unique pointers
    unique_ptr<inheritedTestClass> tsUnique(new inheritedTestClass());
    tsUnique->setTestNumFromInheritedClass(10);
    tsUnique->printTestNumFromInheritedClass();

    unique_ptr<inheritedTestClass> tsUnique2 = move(tsUnique);
    //tsUnique2.reset();
    // OR
    // the below reports a compile time error
    // tsUnique2 = tsUnique;

    // shared_ptr
    shared_ptr<inheritedTestClass> tsShared(new inheritedTestClass());
    tsShared->setTestNumFromInheritedClass(10);
    tsShared->printTestNumFromInheritedClass();

    cout << "actual memory  count is " << tsShared.use_count() << endl;
    shared_ptr<inheritedTestClass> tsShared2 = tsShared;
    cout << "actual memory  count is " << tsShared.use_count() << endl;

    weak_ptr<inheritedTestClass> tsWeak {tsShared};
    shared_ptr<inheritedTestClass> l = tsWeak.lock();
    if (l)
        cout << "From weak pointer " << (l->printTestNumFromInheritedClass());

    // actual pointers
    inheritedTestClass *ts = new inheritedTestClass();
    ts->setTestNumFromInheritedClass(20);
    ts->printTestNumFromInheritedClass();
    delete ts;

    //
    int *a = new (nothrow) int;
    *a = 11;
    cout << "pointer to an integer value is " << *a << endl; 
    delete a;
    a = nullptr;

    int *b = new (nothrow) int[10];
    for ( int i = 0; i < 10; i++) {
        b[i] = i;
        cout << b[i] << endl;
    }
    delete []b;
    // declare and initialize
    int *binit = new (nothrow) int[5] {1,2,3,4,5};
    delete []binit;

    // 3 rows, 4 columns
    int **c = new (nothrow) int*[3]; 
    for (int i = 0; i < 4; i++)
        c[i] = new (nothrow) int[3];

    // delete
    for (int i = 0; i < 4; i++)
        delete c[i];

    int tempVal  = 11;
    int tempVal1 = 12;
    cout << "tempVal is " << tempVal << endl;

    // reference
    int& refB = tempVal;
    cout << "refB value is " << refB << endl;
    refB = 14;
    cout << "tempVal should be modified to 14 by refB"<< refB << " " << tempVal << endl;
    refB = tempVal1;
    cout << "tempVal should be modified to 14 by refB"<< refB << " " << tempVal << endl;
    delete *c;

}
