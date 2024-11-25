#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    string ans;
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
        int ind = 0;
        for (int j = 0; j < n; j++) {
            if (cnt[j] == a[i]) {
                ind = j;
                break;
            }
        }
        ans += 'a' + (char)ind;
        cnt[ind]++;
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
