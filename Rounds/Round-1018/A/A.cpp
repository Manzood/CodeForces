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
    int low = 1, high = n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '<') {
            a[i + 1] = low;
            low++;
        } else {
            a[i + 1] = high;
            high--;
        }
    }
    a[0] = low;
    for (int i = 0; i < n; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
