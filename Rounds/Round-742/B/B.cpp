#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int MX_N = 3e5 + 5;

int32_t main () {
    int t;
    cin >> t;
    // precompute
    vector <int> xor_val (MX_N, 0);

    for (int i = 1; i < MX_N; i++) {
        xor_val[i] = xor_val[i-1] ^ i;
    }

    while (t--) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        int x = xor_val[a - 1];
        int cnt = a;
        int ans = 0;
        if (x == b) {
            ans = cnt;
        } else if ((x ^ b) == a) {
            ans = cnt + 2;
        } else {
            ans = cnt + 1;
        }
        printf("%lld\n", ans);
    }
}
