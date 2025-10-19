#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n; cin >> n;
    vector<ll> nums(n); for(ll i = 0; i < n; i++) cin >> nums[i];

    map<string, vector<ll>> dp;
    dp["rest"] = vector<ll>(n,-1);
    dp["contest"] = vector<ll>(n,-1);
    dp["gym"] = vector<ll>(n,-1);

    ll day1 = nums[0];
    bool gymOpen = false;
    bool contest = false;
    if (day1 >= 2) gymOpen = true;
    if (day1 %2 == 1) contest = true;
    if (gymOpen) dp["gym"][0] = 0;
    if (contest) dp["contest"][0] = 0;
    dp["rest"][0] = 1;

    for(ll i = 1; i < n; i++) {
        // ll res = dp["rest"][i-1];
        // if (dp["contest"][i-1] != -1) res = min(res, dp["contest"][i-1]);
        // if (dp["gym"][i-1] != -1) res = min(res, dp["gym"][i-1]);
        // cout << i << " : " << dp["rest"][i-1] << " " << dp["contest"][i-1] << " " << dp["gym"][i-1] << " " << res << "\n";

        gymOpen = false;
        contest = false;
        ll dayi = nums[i];
        if (dayi >= 2) gymOpen = true;
        if (dayi%2 == 1) contest = true;
        dp["rest"][i] = dp["rest"][i-1] + 1;
        if (dp["contest"][i-1] != -1) dp["rest"][i] = min(dp["rest"][i], dp["contest"][i-1] + 1);
        if (dp["gym"][i-1] != -1) dp["rest"][i] = min(dp["rest"][i], dp["gym"][i-1] + 1);

        if (gymOpen and dp["contest"][i-1] != -1) {
            dp["gym"][i] = min(dp["rest"][i-1], dp["contest"][i-1]);
        } else if (gymOpen) {
            dp["gym"][i] = dp["rest"][i-1];
        }
        
        if (contest and dp["gym"][i-1] != -1) {
            dp["contest"][i] = min(dp["rest"][i-1], dp["gym"][i-1]);
        } else if (contest) {
            dp["contest"][i] = dp["rest"][i-1];
        }
    }
    ll res = dp["rest"][n-1];
    if (dp["contest"][n-1] != -1) res = min(res, dp["contest"][n-1]);
    if (dp["gym"][n-1] != -1) res = min(res, dp["gym"][n-1]);
    cout << res;

}