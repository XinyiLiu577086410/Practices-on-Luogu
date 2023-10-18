#include <iostream>
#define type unsigned long long 
type binpow(type a, type b, type p)
{   
    type res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b = b >> 1;
    }
    return res % p;
}

type a, b, p;
int main(void) {
    std::cin >> a >> b >> p;
    std::cout << a << '^' << b << " mod " << p << "=" << binpow(a, b, p);
    return 0;
}