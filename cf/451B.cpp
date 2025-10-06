#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n; 
    cin >> n;
    vector<ll> a;
    bool dec = false;
    bool alreadyDec = false;
    ll l = 1; ll r = n;
    for(ll i = 0; i < n; i++) {
        ll ai; cin >> ai;
        if(dec) {
            if (a.size() > 0 and a.back() < ai) {
                r = i;
                dec = false;
            }
        } else {
            if (a.size() > 0 and ai < a.back()) {
                dec = true;
                if (alreadyDec) {
                    cout << "no";
                    return 0;
                }
                alreadyDec = true;
                l = i;
            }
        }
        a.push_back(ai);
    }
    if ((l-2 >= 0 and a[r-1] < a[l-2]) or (r < n and a[l-1] > a[r])) {
        cout << "no";
        return 0;
    }
    if (not alreadyDec) {
        l = 1; r = 1;
    }
    cout << "yes\n";
    cout << l << " " << r;
    return 0;
}
