#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll a; ll x; ll y;
    cin >> a >> x >> y;
    if ((a < x and a < y) or (x < a and y < a)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << "\n";
}

int main() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        solve();
    }
    return 0;
}