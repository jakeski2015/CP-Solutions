#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    ll L;
    cin >> n >> L;
    vector<ll> cuts(n);
    for(int j = 0; j < n; j++) {
        ll x; ll i;
        cin >> x >> i;
        cuts[i - 1] = x;
    }
    set<ll> ends;
    ends.insert(0);
    ends.insert(L);
    ll totalCost = 0;
    for (ll cut : cuts) {
        auto upper = ends.upper_bound(cut);
        totalCost += *upper - *(--upper);
        ends.insert(cut);
    }
    cout << totalCost;
    return 0;
}