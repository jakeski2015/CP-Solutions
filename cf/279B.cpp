#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n; ll t; cin >> n >> t;
    vector<ll> books(n);
    for(ll i = 0; i < n; i++) {ll book; cin >> book; books[i] = book;}
    ll r = 0;
    ll window = 0;
    ll lmax = 0;
    for(ll l = 0; l < n; l++) {
        while (r < n and window + books[r] <= t) {
            window += books[r];
            r++;
        }
        lmax = max(lmax, r-l);
        window -= books[l];
    }
    cout << lmax;
}