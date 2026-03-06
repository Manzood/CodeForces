#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> get(string& s) {
    int n = (int)s.size();
    vector<int> suffR(n, 0), prefL(n, 0);
    prefL[0] = s[0] == 'L';
    for (int i = 1; i < n; i++) prefL[i] = prefL[i - 1] + (s[i] == 'L');
    suffR[n - 1] = s[n - 1] == 'R';
    for (int i = n - 2; i >= 0; i--) suffR[i] = suffR[i + 1] + (s[i] == 'R');

    vector<int> out;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        if (i > 0) cnt += prefL[i - 1];
        if (i < n - 1) cnt += suffR[i + 1];
        out.push_back(cnt);
    }
    return out;
}

char opposite(char cur) {
    if (cur == 'L')
        return 'R';
    else
        return 'L';
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
    }

    string tmp;
    tmp += 'L';
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == a[i])
            tmp += opposite(tmp.back());
        else
            tmp += tmp.back();
    }
    vector<int> b = get(tmp);

    tmp.clear();
    tmp += 'R';
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == a[i])
            tmp += opposite(tmp.back());
        else
            tmp += tmp.back();
    }
    vector<int> c = get(tmp);

    int ans = 0;
    ans += c == a;
    ans += b == a;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
