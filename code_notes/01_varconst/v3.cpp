#include <iostream>
using namespace std;

namespace Hello
{
    void Display(std::string a)
    {
        cout << a;
    }
}

int main()
{
    int score; // integers store
    const string score_uniq = "hello world 121";
    score = 10;
    cout << "this is the score of the maths :- " << score << " " << score_uniq;
    cout << "\n";
    cout << "Welcome to Shomayyy's Pc" << endl; // endl--> end the line
    Hello::Display("hello this is demmo method ");

    return 0;
}