#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n; cin >> n;
    vector<ll> events;
    for(ll i = 0; i < 2*n; i++) { ll e; cin >> e; events.push_back(e); }

    vector<ll> firstK;
    vector<ll> lastK;
    vector<ll> everyOther;
    for(ll i = 0; i < n; i++) {
        if (i < 2) {
            everyOther.push_back(events[i]);
        } else {
            everyOther.push_back(events[i] + everyOther[i-2]);
        }
        if (!firstK.empty()) {
            firstK.push_back(firstK[i-1] + events[i]);
            lastK.push_back(lastK[i-1] + events[(2*n)-i-1]);
        } else {
            firstK.push_back(events[i]);
            lastK.push_back(events[n-i-1]);
        }
    }
    for(ll k = 1; k <= n; k++){
        ll ans = 0;
        ans -= firstK[k-1];
        ans += lastK[k-1];
        ans -= 
    }
    cout<<"\n";
}

int main() {
    ll t; cin >> t; for(ll i = 0; i < t; i++) { solve(); }
}