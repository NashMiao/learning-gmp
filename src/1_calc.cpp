#include<iostream>
#include<gmpxx.h>
using namespace std;
int main()
{
    mpz_class a;
    a = 1;
    for(int i = 0; i < 1000; i++)
        a *= 2;
    cout<<"2^1000 = "<<a<<endl;
    mpz_class b, c;
           b = -12345;
           c = "98765432100123456789";
    cout<<"b * c = "<<b * c<<endl;
    return 0;    
}