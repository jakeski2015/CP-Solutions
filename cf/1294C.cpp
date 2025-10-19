#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll t; cin >> t;
    for (ll i = 0; i < t; i++) {
        ll n; cin >> n;
        ll a = 0;
        ll condVal = n;
        bool solFound = false;
        for (ll j = 2; j < ceil(sqrt(n)); j++) {
            if (condVal%j == 0) {
                if (a) {
                    ll b = j;
                    ll c = n/(a*b);
                    if (c != a and c != 1 and c != b) {
                        cout << "YES" << "\n";
                        cout << a << " " << b << " " << c << "\n";
                    } else {
                        cout << "NO" << "\n";
                    }
                    solFound = true;
                    break;
                } else {
                    a = j;
                    condVal = n/a;
                }
            }
        }
        if (not solFound) {
            cout << "NO" << "\n";
        }
    }
}