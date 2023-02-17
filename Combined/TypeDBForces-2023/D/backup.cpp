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
    // detect cycles, find chain length
    vector<int> chain(n, 1);  // opposite of is_cycle
    vector<bool> is_final(n, false), visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int cur = i;
            vector<int> current_chain;
            while (cur >= 0 && cur < n && !visited[cur]) {
                current_chain.push_back(cur);
                visited[cur] = true;
                if (cur + a[cur] < n && cur + a[cur] >= 0)
                    chain[cur + a[cur]] += chain[cur];
                cur = cur + a[cur];
            }
            if (cur >= 0 && cur < n) {
                if (is_final[cur]) {
                    for (auto x : current_chain) {
                        is_final[x] = true;
                    }
                }
            }
        }
    }
    int final_count = 0, source_count = 0;
    // for (int i = 0; i < n; i++) final_count += is_final[i];
    vector<bool> is_source(n, false);
    if (is_final[0]) {
        int cur = 0;
        while (cur >= 0 && cur < n) {
            is_source[cur] = true;
            source_count++;
            cur = cur + a[cur];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!is_source[i]) {
            ans += (source_count + n + 1) * is_final[0];
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
