#include <iostream> /*
{pre processor directives } inclued is one of them the one which start with the #
 include --> inclusive --->iostream is a file or lib which have the basic cout cin etc kinda thing
it have pre-define functions or methods which are used to develope a program
*/
#include <Eigen/Dense>
using namespace std;
/*
this basically make a box or bounderies of a certain names whicha are standarized by the cpp
it means that if there are two class having same name can we seprated by the namespace region you can build
your own namespace which is good to have to make a proper understandable program here the
std is predefined by the cpp which includes the cpp defined names , functions , methods
it sperate the effects of the name clashing
*/

using Eigen::MatrixXd;

namespace myName
{
    void Display(std::string a)
    {
        std::cout << a;
    }
}

int main()
{
    cout << "hello this side shomay \n";
    myName::Display("hello this is the Display side !! \n");

    MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    std::cout << m << std::endl;

    return 2;
}
