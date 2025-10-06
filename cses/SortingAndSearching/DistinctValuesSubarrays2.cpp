#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n; ll k;
    cin >> n >> k;
    vector<ll> nums;
    for(ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        nums.push_back(num);
    }

    ll r = 0;
    map<ll, ll> window;
    ll ans = 0;
    for(ll l = 0; l < n; l++) {
        while (r < n and 
            (((window.find(nums[r]) != window.end()) and window.size() <= k) or 
        (window.find(nums[r]) == window.end() and window.size() < k))) {
            window[nums[r]]++;
            //cout << "l: " << l << " r: " << r << "\n";
            r++;
        }
        ans += r-l;
        window[nums[l]]--;
        if (window[nums[l]] == 0) {
            window.erase(nums[l]);
        }
    }
    cout << ans;
}