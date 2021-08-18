#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int k;
        scanf("%lld", &k);
        int start = 1;
        int c = 1;
            while (k > start) {
                k -= start;
                start += 2;
                c++;
            }

            int r = 0;

            if (k <= start / 2) {
                r = k;
            } else {
                r = start / 2 + 1;
                k -= start / 2 + 1;
                c -= k;
            }

            printf("%lld %lld\n", r, c);
        }
}
