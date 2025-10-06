#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> dp;
    dp.push_back(1);
    const long long MOD = 1000000007LL;

    for(long long i = 1; i <= n; i++) {
        dp.push_back(0);
        for(long long j = 1; j <= 6; j++) {
            if (0 <= i - j) {
                dp[i] += (dp[i-j] % MOD);
            }
        }
    }
    cout << (dp[n] % 1000000007LL);
    return 0;
}