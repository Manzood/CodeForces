#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> ans, val;
vector<pair<int, int>> swaps;

int throwat(int x) {
    cout << "throw " << x + 1 << endl;
    int response;
    cin >> response;
    return response;
}

int swapat(int x) {
    cout << "swap " << x + 1 << endl;
    swap(ans[x], ans[x + 1]);
    swap(val[x], val[x + 1]);

    int res = throwat(x);
    int n = (int)ans.size();
    ans[x] = res;
    int exp = x < n - 2 ? ans[x + 2] + 1 : 1;
    debug(exp);
    val[x] = res > exp ? 1 : 2;
    // ans[x] = x + val[x] < n ? ans[x + val[x]] + 1 : 1;

    swaps.push_back({x, x + 1});
    return res;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    ans.assign(n, -1);
    val.assign(n, -1);
    swaps.clear();

    for (int i = n - 2; i >= 0; i -= 2) {
        int res = throwat(i);
        int exp = i == n - 2 ? 1 : ans[i + 2] + 1;
        ans[i] = res;
        val[i] = res > exp ? 1 : 2;
        debug(val, ans);
        swapat(i);
        debug(val, ans);
    }

    if (n & 1) {
        swapat(0);
    }

    while (swaps.size()) {
        pair<int, int> cur = swaps.back();
        swap(val[cur.first], val[cur.second]);
        swaps.pop_back();
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << val[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
