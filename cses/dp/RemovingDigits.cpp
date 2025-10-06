#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n; //n = 10
    vector<ll> dp(n + 1);
    dp[0] = 0;
    for(ll i = 1; i <= n; i++) {
        ll power = 0;
        ll currMin = LONG_LONG_MAX;
        while(i/((ll)pow(10,power)) > 0) {
            ll currDig = (i%(ll)pow(10, power + 1))/(ll)pow(10, power);
            if (currDig != 0 and (i-currDig) >= 0) {
                currMin = min(currMin, dp[i - currDig] + 1);
            }
            power++;
        }
        dp[i] = currMin;
    }
    cout << dp[n];
    return 0;
}