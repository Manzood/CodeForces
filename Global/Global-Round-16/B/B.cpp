#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int zeroes = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == '0') {
                if (i == 0 || s[i-1] == '1') {
                    zeroes++;
                }
            }
        }
        int ans = 0;
        if (zeroes == 1) {
            ans = 1;
        } else if (zeroes > 1) {
            ans = 2;
        } else {
            ans = 0;
        }
        printf("%lld\n", ans);
    }
}
