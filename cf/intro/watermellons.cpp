#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
	long long a;
	cin >> a;
	(a%2 == 0 and a != 2) ? cout << "YES" : cout << "NO";
}
