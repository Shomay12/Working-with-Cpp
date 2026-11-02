#include <iostream>

using namespace std;

int main()
{
    float priceOfTea = 299.89;
    int roundedTeaPrice = (int)priceOfTea; /* here we converts the datatypes from one to other here it's a example of the
    float to int and same as well the other datatypes can be change to one other */

    float ab = 10003;
    string id = to_string(ab);
    string abc = id + " helllo this is me ";
    cout << abc << endl;

    cout << roundedTeaPrice << endl;

    return 0;
}