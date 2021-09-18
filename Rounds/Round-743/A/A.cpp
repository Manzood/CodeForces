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
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += s[i] - '0';
            if (s[i] - '0' > 0) ans++;
        }
        if (s[n-1] > '0') ans--;
        printf("%lld\n", ans);
    }
}
