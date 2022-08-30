/**
 * Dont raise your voice, improve your argument.
 * --Desmond Tutu
 */
#include <bits/stdc++.h>
using namespace std;

const bool ready = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);
    return true;
}();

using ld = long double;
const ld PI = acos((ld)-1);
using ll = long long;
#define int ll
#define all(v) (v).begin(), (v).end()
#define fori(n) for (int i = 0; i < int(n); i++)

#define cini(i) \
    int i;      \
    cin >> i;
#define cins(s) \
    string s;   \
    cin >> s;
#define cind(d) \
    ld d;       \
    cin >> d;
#define cinai(a, n) \
    vi a(n);        \
    fori(n) { cin >> a[i]; }
#define cinas(s, n) \
    vs s(n);        \
    fori(n) { cin >> s[i]; }
#define cinad(a, n) \
    vd a(n);        \
    fori(n) { cin >> a[i]; }

using pii = pair<int, int>;
using pdd = pair<ld, ld>;
using vd = vector<ld>;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

#define endl "\n"

/**
 */
void solve() {
    cini(n);
    cins(s);

    string t = "Timur";
    sort(all(s));
    do {
        if (s == t) {
            cout << "YES" << endl;
            return;
        }
    } while (next_permutation(all(s)));

    cout << "NO" << endl;
}

signed main() {
    cini(t);
    while (t--) solve();
}
