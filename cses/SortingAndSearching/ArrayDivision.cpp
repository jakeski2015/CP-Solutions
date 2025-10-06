#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> arr;
ll n; ll k;

bool solve(ll target, ll divs) {
    ll curr = 0;
    for(ll i = 0; i < n; i++) {
        if (curr + arr[i] > target) {
            divs--;
            curr = 0;
        }
        curr += arr[i];
    }
    return (divs < 0) ? false : true;
}

int main() {
    cin >> n >> k;
    ll lmax = 0;
    ll arrSum = 0;
    for(ll i = 0; i < n; i++) {
        ll a; cin >> a; arr.push_back(a);
        lmax = max(lmax, a);
        arrSum += a;
    }
    ll l = lmax;
    ll r = arrSum;
    while (l < r) {
        ll target = l + (r-l)/2;
        if (solve(target, k - 1)) {
            r = target;
        } else {
            l = target + 1;
        }
    }
    cout << l;
    return 0;
}
