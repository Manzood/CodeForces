#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    indexed_set s;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        if ((int)ans.size()) cur = ans.back();
        if (*s.find_by_order(s.order_of_key(a[i])) != a[i]) {
            s.insert(a[i]);
            int ind = s.order_of_key(a[i]);
            cur += a[i] - (ind + 1);
            int cnt = (int)s.size() - ind - 1;
            cur -= cnt;
        }
        ans.push_back(cur);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
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
