#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    vector<bool> isPrime(1E6 + 1);
    queue<ll> q;
    for(ll i = 2; i < 1E6+1; i++) {
        isPrime[i] = true;
        q.push(i);
    }

    while (!q.empty()) {
        ll curr = q.front();
        q.pop();
        if (isPrime[curr]) {
            for(ll i = curr * 2; i < 1E6 + 1; i += curr) {
                isPrime[i] = false;
            }
        }
    }

    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        ll sqrtNum = (ll)sqrt(num);
        if (isPrime[sqrtNum] and (sqrtNum * sqrtNum == num)) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}