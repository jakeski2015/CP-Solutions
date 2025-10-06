#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> books;
    ll totalTimeToReadBooks = 0;
    for(ll i = 0; i < n; i++) {
        ll book;
        cin >> book;
        books.push_back(book);
        totalTimeToReadBooks += book;
    }

    sort(books.begin(), books.end());
    if (totalTimeToReadBooks - books[n - 1] >= books[n - 1]) {
        cout << totalTimeToReadBooks;
    } else {
        cout << 2 * books[n - 1];
    }

    return 0;
}