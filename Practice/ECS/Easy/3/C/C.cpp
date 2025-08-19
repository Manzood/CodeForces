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

    sort(a.begin(), a.end());
    int ans = a.front() * a.back();

    vector<int> div;
    for (int i = 2; i * i <= ans; i++) {
        if (i * i == ans) {
            div.push_back(i);
        } else {
            if (ans % i == 0) {
                div.push_back(i);
                div.push_back(ans / i);
            }
        }
    }
    sort(div.begin(), div.end());

    printf("%lld\n", div == a ? ans : -1LL);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
