#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    map<ll,ll> b;
    ll n; cin >> n; for(ll i = 0; i < n; i++) {ll bi; cin >> bi; b[bi]++;}
    ll mn = b.begin()->first; ll mx = (--b.end())->first;
    ll possibilities = b[mn] * b[mx];
    if (mn == mx) {
        possibilities = (b[mn]*(b[mn] - 1))/2;
    }
    cout << mx - mn << " " << possibilities;
}