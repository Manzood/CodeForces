#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        int sum = a + c;
        b *= 2;
        int diff = abs (b - sum);
        diff %= 3;
        if (diff == 2) {
            diff = 1;
        }
        printf("%lld\n", diff);
    }
}
