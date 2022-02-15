#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        scanf("%lld%lld", &n, &s);
        int m = 0;
        // if (n % 2 == 0) {
            // m = s / (n / 2);
        // } else {
        m = s / (n / 2 + 1);
        // }
        printf("%lld\n", m);
    }
}
