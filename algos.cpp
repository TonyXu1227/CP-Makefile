#include <bits/stdc++.h>
#include <iostream>
#define BIG_P (1000000007)
using namespace std;
 
using ll = long long;
using ld = long double;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

ll binpow(ll x, ll y) {
    ll z = 1;
    while (y) {
        if (y & 1) {
            z = z * x % BIG_P;
        }
        x = x * x % BIG_P;
        y >>= 1;
    }
    return z;
}

ll gcd(ll x, ll y) {
    while(x > 0 && y > 0) {
        x = x%y;
        //cout << x << " " << y << "\n";
        if(x == 0) {
            break;
        }
        y = y%x;
        //cout << x << " " << y << "\n";
    }
    if(x == 0) {
        return y;
    }
    return x;
}

ll inv(ll a) {
  return a <= 1 ? a : BIG_P - (ll)(BIG_P/a) * inv(BIG_P % a) % BIG_P;
}