#include <iostream>

using namespace std;

int main()
{

    // int smallTeaPack = -100;
    // cout << smallTeaPack << endl;-----> here in the day to day life tea can't be in negative
    unsigned int smallTeaPack = -100; // unsigned used to determine the value should be in positive only it didn't allow the sign
                                      // in front of the variable---->it returns the garbage values
    cout << smallTeaPack << endl;

    double largeTeaStorage = 1000000000000;
    long largeTeaStorage1 = 1000000000000;
    cout << "\n"
         << largeTeaStorage << "\n"
         << largeTeaStorage1 << "\n"
         << endl;

    return 0;
}