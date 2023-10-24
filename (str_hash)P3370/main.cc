// AC: you need 2 big prime numbers
// 2023/10/19 7:14:15

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
// #pragma GCC optimize("-O3")
// not allowed in luogu
int n;
int prime =  91815541;
int mod = 290182597;
constexpr uint64_t table_len = 122420729;
bool table[table_len];
int main(void) {
    auto hash = [](string s)-> uint64_t{
        // was uint16_t sum = 0;
        uint64_t sum = 0, power = 131;
        for(int i = 0; i < s.length(); i++) {
            sum = (sum*power + s[i]) % mod + prime;
        }
        return sum;
    };
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        table[hash(str)%table_len] = true;
    }
    int cnt = 0;
    // #pragma unroll 5
    for(int i = 0; i < table_len; i++) {
        if(table[i]) cnt++;
    }
    cout << cnt;
    return 0;
}