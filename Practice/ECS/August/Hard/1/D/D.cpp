#include <sys/time.h>

#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef uint64_t ull;
static int C;  // initialized below

// taken from kactl
template <int M, class B>
struct A {
    int x;
    B b;
    A(int x = 0) : x(x), b(x) {}
    A(int x, B b) : x(x), b(b) {}
    A operator+(A o) {
        int y = x + o.x;
        return {y - (y >= M) * M, b + o.b};
    }
    A operator-(A o) {
        int y = x - o.x;
        return {y + (y < 0) * M, b - o.b};
    }
    A operator*(A o) { return {(int)(1LL * x * o.x % M), b * o.b}; }
    explicit operator ull() { return x ^ (ull)b << 21; }
    bool operator==(A o) const { return (ull) * this == (ull)o; }
    bool operator<(A o) const { return (ull) * this < (ull)o; }
};
typedef A<1000000007, A<1000000009, int>> H;

struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string& str) : ha(((int)str.size()) + 1), pw(ha) {
        pw[0] = 1;
        for (int i = 0; i < (int)str.size(); i++)
            ha[i + 1] = ha[i] * C + str[i], pw[i + 1] = pw[i] * C;
    }
    H hashInterval(int a, int b) {  // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};

vector<H> getHashes(string& str, int length) {
    if ((int)str.size() < length) return {};
    H h = 0, pw = 1;
    for (int i = 0; i < length; i++) h = h * C + str[i], pw = pw * C;
    vector<H> ret = {h};
    for (int i = length; i < (int)str.size(); i++) {
        ret.push_back(h = h * C + str[i] - pw * str[i - length]);
    }
    return ret;
}

H hashString(string& s) {
    H h{};
    for (char c : s) h = h * C + c;
    return h;
}

void populate(string& cur, int len, vector<string>& out) {
    if ((int)cur.size() == len) {
        if (cur == "0011" || cur == "0101" || cur == "1110" || cur == "1111")
            return;

        out.push_back(cur);
        return;
    }

    cur += '0';
    populate(cur, len, out);
    cur.pop_back();

    cur += '1';
    populate(cur, len, out);
    cur.pop_back();
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s += c;
    }

    vector<string> morse;
    for (int len = 1; len <= 4; len++) {
        string cur;
        populate(cur, len, morse);
    }

    unordered_set<int, custom_hash> m1;
    for (auto x : morse) {
        m1.insert((ull)hashString(x));
    }

    HashInterval hi(s);
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++) {
        for (int i = j; i >= 0; i--) {
            for (int x = 1; x <= 4; x++) {
                if (j - i + 1 == x) {
                    H h = hi.hashInterval(i, i + x);
                    if (m1.count((ull)h)) {
                        (dp[i][j] += 1) %= MOD;
                    }
                } else if (j - i + 1 > x) {
                    H h = hi.hashInterval(i, i + x);
                    if (m1.count((ull)h)) {
                        (dp[i][j] += dp[i + x][j]) %= MOD;
                    }
                }
            }
        }
    }

    vector<int> out(n, 0);

    int sz = 0;
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            H h = hi.hashInterval(i, j + 1);
            ull hv = (ull)h;
            v.push_back({(int)hv, {j, dp[i][j]}});
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); i++) {
        if (i == 0 || v[i].first != v[i - 1].first) {
            out[v[i].second.first] += v[i].second.second;
        }
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
        (out[i] += cur) %= MOD;
        cur = out[i];
    }

    for (auto x : out) {
        printf("%lld\n", x);
    }
    debug(v.size());
}

int32_t main() {
    int t = 1;
    // cin >> t;

    timeval tp;
    gettimeofday(&tp, 0);
    C = (int)tp.tv_usec;  // (less than modulo)
    assert((ull)(H(1) * 2 + 1 - 3) == 0);

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
