#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Here we are doing the cpp operators " << endl;

    // arithemetical operator

    int cups;
    double pricePerCup, totalPrice, discountedPrice;
    cout << "\n Enter the number of tea cups :" << endl;
    cin >> cups;
    cout << "\n Enter the price per cups  :" << endl;
    cin >> pricePerCup;
    totalPrice = cups * pricePerCup;

    if (totalPrice > 100)
    {
        cout << " Congratulations !!! You are eligible for the discount " << endl;
        cout << "\n the total price is  : " << totalPrice << endl;
        double discount = ((totalPrice / 100) * 15);
        cout << "\n discount is 15%:-  :" << discount << endl;
        discountedPrice = totalPrice - ((totalPrice / 100) * 15);
        cout << "\n After 15% discount the Final Price is  :-  :" << discountedPrice << "\n ThankYou!!" << endl;
    }
    else
    {

        cout << "\n the total price is  : " << totalPrice << "\n ThankYou!!" << endl;
    }

    return 0;
}
