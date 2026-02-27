#include <bits/stdc++.h>
#include <iostream>
#define BIG_P (1000000007)
using namespace std;
 
using ll = long long;
using ld = long double;
#define abs(a) ((a) > 0 ? (a) : (-(a)))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
 
typedef vector<ll> vll;
typedef vector<pair<ll, ll> > vpll;

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

//this fenwick tree
vll fentree(100000);
ll fentreequery(ll i) {
    ll ret = 0;
    while(i > 0) {
        ret += fentree[i];
        ll b = 1;
        while(!(b & i)) {
            b *= 2;
        }
        i -= b;
    }
    return ret;
}

void fentreeupdate(ll i, ll v) {
    while(i < fentree.size()) {
        fentree[i] += v;
        ll b = 1;
        while(!(b & i)) {
            b *= 2;
        }
        i += b;
    }
}

void fentreebuild(vll init, ll n) {
    for(int i = 0; i < n; i++) {
        fentree[i] = init[i];
    }
    for(int i = 0; i < n; i++) {
        ll b = i&(-1*i);
        ll pb = i+b;
        if(pb < n) {
            fentree[pb] += fentree[i];
        }
    }
}

ll buildsegtree(vll &tree, ll left, ll right, ll ind, vll &arr) {
    if(left == right) {
        tree[ind] = arr[left];
        return tree[ind];
    }
    ll mid = (left + right)/2;
    ll n1 = buildsegtree(tree, left, mid, ind*2+1, arr);
    ll n2 = buildsegtree(tree, mid+1, right, ind*2+2, arr);
    tree[ind] = max(n1, n2);
    return tree[ind];
}

ll querysegtree(vll &tree, ll v, ll tl, ll tr, ll l, ll r) {
    //cout << v << " " << tl << " " << tr << " " << l << " " << r << "\n";
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    ll tm = (tl + tr) / 2;
    ll n1 = querysegtree(tree, v*2+1, tl, tm, l, min(r, tm));
    ll n2 = querysegtree(tree, v*2+2, tm+1, tr, max(l, tm+1), r);
    return max(n1, n2);
}