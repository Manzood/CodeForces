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
        int num1 = 0, num2 = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                num1 *= 10;
                num1 += s[i] - '0';
            } else {
                num2 *= 10;
                num2 += s[i] - '0';
            }
        }
        int ans = (num1 + 1) * (num2 + 1) - 2;
        printf("%lld\n", ans);
    }
}
