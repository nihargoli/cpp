#include <iostream>

using namespace std;

class testExplicit
{

public:
    int var;
    explicit testExplicit(int &v) : var(v) { }

};

void setMethod(testExplicit t1) {
     cout << t1.var << endl;
}
int main(int argc, char *argv[])
{

    int temp = 10;
    testExplicit *t1 = new testExplicit(temp);

    // Notice that since we have a single argument constructor
    // and we made a function call with integer as argument and
    // taking that as an object of testExplicit class.. 
    // the compiler is allowed to convert one argument of the function to
    // implicitly convert to the type it thinks best matches. here object
    // of testExplicit is assigned to temp => testExplicit.var = temp//

    // If we specify explicit compiler catches and does throw an error
    // uncomment explicit and you will not notice an error for this function
    // call.  
    setMethod(temp);
}
