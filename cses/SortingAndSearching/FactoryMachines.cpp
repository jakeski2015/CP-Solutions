#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n; ll t;
    cin >> n >> t;
    vector<ll> machines;
    ll lower = 1; ll upper = LONG_LONG_MAX;
    for(ll i = 0; i < n; i++) {
        ll machine;
        cin >> machine;
        machines.push_back(machine);
        upper = machine < upper ? machine : upper;
    }
    upper = t * upper;

    while(lower < upper) {
        ll minTime = lower + (ll)((upper - lower)/2);
        bool decision = false;
        ll totalProducts = 0;
        for(ll timePerProduct : machines) {
            totalProducts += (ll)(minTime/timePerProduct);
        }
        if (totalProducts >= t) {
            decision = true;
        }
        if (decision) {
            upper = minTime;
        } else {
            lower = minTime + 1;
        }
    }
    cout << lower;
    return 0;
}
