// #include <stdio.h>
// #include <exception>
// #include <new>
// #include <string.h>
#include <bits/stdc++.h>
#define print(x)    do{\
                        printf("\n"); \
                        for(int i = 0; i < n; i++) {\
                            for(int j = 0; j < n; j++){\
                                printf("%lld", (x)(i,j));\
                            }\
                            printf("\n");\
                        }\
                    }while(0);

typedef long long ll;
ll n, k;
ll mod = (ll)1e9 + 7;
struct mat {
    ll a[50*50];
    ll v;
/*functions*/
    
    mat(int n) :v(n) {
        memset(a, 0, sizeof a);
        for(ll i = 0; i < v; i++)
                operator()(i,i) = 1;
    }
    
    inline ll & operator() (ll i, ll j) {
        return a[v*i+j];
    }

    mat operator * (mat b) {
        // print((*this))
        // printf("*");
        // print(b)
        mat br(v), res(v);
        memset(res.a, 0, sizeof a);
        for(ll i = 0; i < v; i++)
            for (ll j = 0; j < v; j++)
            {
                br(j, i) = b(i, j);
            }
        // print(br)
        for(ll i = 0; i < v; i++)
            for (ll j = 0; j < v; j++)
                for(ll k = 0; k < v; k++)
                {
                    res(i, j) = (res(i, j) + ((*this)(i, k) * br(j, k)) % mod ) % mod;
                }
        // printf("==");
        // print(res)
        return res;
    }
};

mat base(0);

void read() {
    scanf("%lld%lld",&n,&k);
    base = mat(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lld", &base(i, j));
        }
    }
    // print(base);
}


void doit() {
    mat res(n);
    // print(res)
    while(k) {
        if(k&1) res = res * base;
        base = base * base;
        // print(base)
        k = k >> 1;
    }
    // reduce
    // print(res)
    ll sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
                sum = (sum + res(i,j)) % mod; 

    printf("%lld", sum);
}


int main(void) { 
    read();
    doit();
    return 0;
}