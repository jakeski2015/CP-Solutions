#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n; ll l;
vector<double> a;

int main() {
    scanf("%lld%lld", &n, &l);
    a.push_back(0);
    for(ll i = 0; i < n; i++) {
        ll curr;
        scanf("%lld", &curr);
        a.push_back(curr);
    }
    a.push_back(l);
    sort(a.begin(), a.end());
    double maxDist = 0;
    for(ll i = 0; i < n - 1; i++) {
        maxDist = max(maxDist, abs(a[i] - a[i+1]));
    }
    cout << fixed << setprecision(9) << maxDist/2 << "\n";
    return 0;
}