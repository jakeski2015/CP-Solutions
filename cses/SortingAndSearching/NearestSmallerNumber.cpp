#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> nums;
    for(ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        nums.push_back(temp);
    }
    
    vector<ll> ans(n);
    ans[0] = 0;
    vector<ll> stck;
    stck.push_back(0);
    for(ll i = 1; i < n; i++) {
        ll locAns = -1;
        if (nums[i] > nums[stck.back()]) {
            locAns = stck.back();
        } else {
            while (!stck.empty() and nums[stck.back()] >= nums[i]) {
                stck.pop_back();
            }
            if (!stck.empty()) {
                locAns = stck.back();
            }
        }
        ans[i] = (locAns + 1);
        stck.push_back(i);
    }
    for(auto a : ans) {
        cout << a << " ";
    }
    return 0;
}