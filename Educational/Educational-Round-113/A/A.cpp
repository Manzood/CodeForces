#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        int l = -1, r = -1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                r = i + 1;
                l = i;
                break;
            }
        }
        printf("%lld %lld\n", l, r);
    }
}
