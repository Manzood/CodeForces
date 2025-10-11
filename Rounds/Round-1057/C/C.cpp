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
    vector<int> chosen;
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (!used[i - 1] && a[i] == a[i - 1]) {
            chosen.push_back(a[i]);
            chosen.push_back(a[i]);
            sum += 2 * a[i];
            used[i] = true;
            used[i - 1] = true;
        }
    }

    vector<int> rem;
    rem.push_back(0);
    rem.push_back(0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            rem.push_back(a[i]);
        }
    }
    sort(rem.begin(), rem.end());

    int m = (int)rem.size();
    bool possible = false;
    int val = 0;

    for (int i = 2; i < m; i++) {
        if (rem[i] - rem[i - 1] < sum) {
            val = max(val, rem[i] + rem[i - 1]);
            possible = true;
        }
    }

    sum += val;
    if ((int)chosen.size() == 0) possible = false;
    if ((int)chosen.size() > 2) possible = true;

    printf("%lld\n", possible ? sum : 0LL);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
