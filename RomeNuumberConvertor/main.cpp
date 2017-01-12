#include <iostream>
#include "romenumber.h"
#include <string>

#include <cassert>
using namespace std;


int main(int argc, char *argv[])
{
//    RomeNumber r("DDCCXXXV");
//    RomeNumber a(1145);
//    cout << r.GetArabNumber() << endl;
//    cout << a.GetRomeString() << endl;
//    RomeNumber x = a + r;
//    cout << x.GetArabNumber() << endl;
//    cout << x.GetRomeString() << endl;
//    x += 20;
//    cout << x.GetArabNumber() << endl;
//    cout << x.GetRomeString() << endl;

//    cout << r;
    RomeNumber r1 = RomeNumber("MDIL");
    RomeNumber r2 ("MCDXLIX");

    cout << r1 <<endl;
    cout << r2 << endl;
    assert(r1 == 1549);
    assert(r1 + 1 == 1550);
    assert(r1 + r2 >= r2);

    cout << r2 + r2 << endl ;
    cout << r2 * 2 << endl ;
    assert(r2 + r2 == r2*2);
    assert(r1 >  r2);
    assert(r1 != r2);

    cin >> r2;

    cout << r2;

    r1 += 2;
    cout << r1;

    return 0;
}
