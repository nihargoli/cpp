/**
** Feel free to use the code. No restrictions.
** Added code to better understand virtual functions
** and pointers to arrays.
** author: nihar goli; email: nihargoli@gmail.com
**/

#include <iostream>

using namespace std;

class App
{

    string app_name;

    public:
        App(const string& name) : app_name(name){ }

        virtual void printAppName() const {
            cout << "application  name is " << app_name << endl;
        }
       
        /* remove virtual and call the function
        ** notice that app details are printed by base class pointer though it points to derived class*/
        virtual void printAppDetails() const {
            cout << "No over ridden method in derived class so print from base class for printAppDetails" << endl;
            cout << "Manufacturer name is unknown" << endl;
        }

};

class WordApp : public App
{
    public:
        WordApp(string appname) : App(appname) {}
        // virtual over ridden functions should have same name
        void printAppDetails() const {
            cout << "Manufacturer name is Microsoft Word" << endl;
        }
}; 

class ExcelApp : public App
{
    public:
        ExcelApp(string appname) : App(appname) {}
}; 

int main(int argc, char *argv[])
{

    App *baseClassApp;
    ExcelApp *eDerivedClassApp = new(nothrow) ExcelApp("excel");
    if (eDerivedClassApp) {
        // If a class memeber is virtual, then every object create for a class
        // will have vptr pointing to its classes vtable(consists of all references to functions).
        // Here printAppName is virtual. If the derived class does not over ride printAppName, then
        // base class printAppName is called same as printAppDetails.
        baseClassApp = eDerivedClassApp;
        baseClassApp->printAppName();
        baseClassApp->printAppDetails();
    } else {
        cout << "Failed to allocate memory" << endl;
    }
    /////////////////////////////
    baseClassApp = NULL;
    WordApp *wDerivedClassApp = new(nothrow) WordApp("word");
    if (wDerivedClassApp) {
        // If a class memeber is virtual, then every object create for a class
        // will have vptr pointing to its classes vtable(consists of all references to functions).
        // Here printAppName is virtual. If the derived class does not over ride printAppName, then
        // base class printAppName.
        // Since printAppDetails is over ridden - appDEtails are printed from derived class
        baseClassApp = wDerivedClassApp;
        baseClassApp->printAppName();
        baseClassApp->printAppDetails();
    } else {
        cout << "Failed to allocate memory" << endl;
    }

}
