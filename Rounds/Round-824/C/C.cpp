#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool checkcycle(vector<bool>& used, vector<char>& mp, char source, char dest) {
    int len = 1;
    // check if you get source back
    char cur = dest;
    while (cur != source && used[cur - 'a'] == true) {
        len++;
        cur = mp[cur - 'a'] + 'a';
    }
    if (cur == source && len < 26) return false;
    return true;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string t;
    cin >> t;
    // none of the mappings should create a cycle
    vector<bool> used(26, false);
    vector<char> mp(26, ' ');
    vector<char> back(26);
    vector<bool> f(26, false);
    for (int i = 0; i < n; i++) {
        bool found = false;
        if (f[t[i] - 'a'] == true) continue;
        for (int j = 0; j < 26 && !found; j++) {
            if (j + 'a' != t[i] && !used[j]) {
                if (checkcycle(used, mp, (char)j + 'a', t[i])) {
                    // mapping is okay
                    mp[j] = t[i] - 'a';
                    back[t[i] - 'a'] = (char)j + 'a';
                    f[t[i] - 'a'] = true;
                    used[j] = true;
                    found = true;
                }
            }
        }
    }
    string s;
    for (int i = 0; i < n; i++) {
        s += back[t[i] - 'a'];
    }
    cout << s << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
