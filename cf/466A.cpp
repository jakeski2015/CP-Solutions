#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    ll m;
    ll a;
    ll b;
    cin >> n >> m >> a >> b;
    double ratio = b/m;
    if (ratio < a) {
        cout << (b * int(n/m)) + min(a * (n%m), b);
    } else {
        cout << a * n;
    }
    return 0;
}