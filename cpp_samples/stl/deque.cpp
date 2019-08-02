//  double ended queue

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(int argc, char *argv[])
{
    deque<string> items = { "windows", "unix" };

    items.push_back("android");
    items.push_front("linux");
    items.push_back("bsd");

    for (auto& i : items) {
        cout << i  << endl;
    }

    cout << endl;

    items.pop_back();

    for (auto& i : items) {
        cout << i  << endl;
    }

    cout << endl;
    items.pop_front();
    for (auto& i : items) {
        cout << i  << endl;
    }

    cout << endl;

    deque<string>::iterator it = items.begin();
    while(it != items.end()) {
        cout << *it << endl;
        it++;
    }


    return 0;
}
