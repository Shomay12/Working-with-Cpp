#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userTea;
    int TeaQuantity;

    cout << "what whould you like to order \n"
         << "Options are:- \n 1.Ginger Tea \n 2.Masala Tea \n 3.Elaichi Tea \n 4.Black Tea \n 5.Green tea \n"
         << endl;
    getline(cin, userTea);

    cout << "How many cups of Tea whould you like to Have ??" << endl;
    cin >> TeaQuantity;

    cout << "\n\nYou Ordered :- " << userTea << "\n Number of tea:- " << TeaQuantity << "\n ThankYou!!";

    return 0;
}