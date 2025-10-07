#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll m; ll s; cin >> m >> s;
    if (s > 9 * m or (s == 0 and m > 1)) {
        cout << "-1 -1";
        return 0;
    }
    string maxRes = "";
    ll curr = s;
    ll lastDig = -1;
    while (maxRes.size() < m) {
        if (curr > 9) {
            maxRes += to_string(9);
            curr -= 9;
        } else if (curr > 0) {
            maxRes += to_string(curr);
            curr = 0;
            lastDig = maxRes.size() - 1;
        } else {
            maxRes += to_string(0);
        }
    }
    string minRes = maxRes;
    if (lastDig >= 0 and lastDig < minRes.size() - 1) {
        minRes[lastDig] = '0' + (minRes[lastDig] - '0' - 1);
        minRes[minRes.size() - 1] = '1';
    }
    reverse(minRes.begin(), minRes.end());

    cout << minRes << " " << maxRes;
    
    return 0;

}