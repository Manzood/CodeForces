#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string run;
    cin >> run;
    if (run == "first") {
        int n;
        scanf("%lld", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            a[i] -= 1;
        }
        string out;
        for (int i = 0; i < n; i++) {
            string cur = to_string(a[i]);
            out.push_back((char)cur.size() + 'a');
            for (auto c : cur) {
                out += c - '0' + 'a';
            }
        }
        cout << out << "\n";
    } else {
        string s;
        cin >> s;
        int n = (int)s.size();
        vector<int> a;
        int ptr = 0;
        while (ptr < n) {
            int len = (int)(s[ptr] - 'a');
            ptr++;
            string cur;
            for (int j = 0; j < len; j++) {
                cur += s[ptr++] - 'a' + '0';
            }
            a.push_back(stoi(cur));
        }
        printf("%lld ", (int)a.size());
        for (int i = 0; i < (int)a.size(); i++) {
            printf("%lld ", a[i] + 1);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
