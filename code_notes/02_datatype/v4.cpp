#include <iostream>

using namespace std;

int main()
{
    int teaLeaves = 50;
    double waterTemperature = 85.576;
    float priceOfTea = 299.89;
    char teaGrade = 'A';
    bool isTeaReady = true;
    string Note = "*Serve it hot , drink within 10 mins of dispatch.......ThankYOu for choosing US!!*";

    cout << teaLeaves << " :- numbers of tea leaves we used \n"
         << waterTemperature << " Degrees of Tempreture we need \n"
         << priceOfTea << " :-  the price of tea \n"
         << teaGrade << " - Class of tea we are serving \n"
         << "Your tea is ready Sir/Ma'am" << isTeaReady << "\n"
         << Note << endl;

    return 0;
}