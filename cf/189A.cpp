#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n; ll a; ll b; ll c;
    cin >> n >> a >> b >> c;
    vector<ll> dp(n+1);
    for(int i = 0; i < n+1; i++) {
        dp[i] = 0;
    }
    if (a <= n) {
        dp[a] = 1;
    }
    if (b <= n) {
        dp[b] = 1;
    }
    if (c <= n) {
        dp[c] = 1;
    }
    for(ll i = min(a,min(b,c)) + 1; i <= n; i++) {
        ll res = dp[i];
        if (i - a > 0) {
            if (dp[i-a] > 0) {
                res = max(1 + dp[i-a], res);
            }
        }
        if (i-b > 0) {
            if(dp[i-b] > 0) {
                res = max(1 + dp[i-b], res);
            }
        }
        if (i-c > 0) {
            if (dp[i-c] > 0) {
                res = max(1 + dp[i-c], res);
            }
        }
        dp[i] = res;
    }
    cout << dp[n];
    return 0;
}