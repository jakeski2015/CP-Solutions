#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    bool isEven = false;
    bool isOdd = false;
    ll firstEven = -1;
    ll firstOdd = -1;
    for(ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        if (num%2 == 0) {
            if (firstEven != -1) {
                isEven = true;
            } else {
                firstEven = i + 1;
            }
        } else {
            if (firstOdd != -1) {
                isOdd = true;
            } else {
                firstOdd = i + 1;
            }
        }
        if (isEven and firstOdd != -1) {
            cout << firstOdd;
            break;
        } else if (isOdd and firstEven != -1) {
            cout << firstEven;
            break;
        }
    }
    return 0;
}