#include <bits/stdc++.h>
#include <stack>
#include <set>
#include <regex>
#include <map>
#include <iostream>
#include <unordered_set>
#pragma 3
#define BIG_P (ll)(1000000007)
using namespace std;
 
using ll = long long;
using ld = long double;
#define abs(a) ((a) > 0 ? (a) : (-(a)))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
 
typedef vector<ll> vll;

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

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin.exceptions(cin.failbit);
    int t; cin >> t;
    while(t--) {
        
    }
}