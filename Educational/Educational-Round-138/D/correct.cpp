// const int MOD = 1e9 + 7;
const int MOD = 998244353;
const int mxN = 3e5;

int add(int a, int b) { return ((1LL * a + b) % MOD + MOD) % MOD; }

template <typename Head, typename... Tail>
int add(Head h, Tail... t) {
    return add(h, add(t...));
}

int sub(int a, int b) { return add(a, -b); }

int mult(int a, int b) { return 1LL * a * b % MOD; }

template <typename Head, typename... Tail>
int mult(Head h, Tail... t) {
    return mult(h, mult(t...));
}

int pow(int b, int p) {
    int res = 1;
    while (p) {
        if (p & 1) {
            res = mult(res, b);
        }
        p /= 2;
        b = mult(b, b);
    }
    return res;
}

int inv(int x) { return pow(x, MOD - 2); }

int divide(int a, int b) { return mult(a, inv(b)); }

int fact_arr[mxN + 1] = {}, ifact_arr[mxN + 1] = {};

void init() {
    ifact_arr[0] = fact_arr[0] = 1;
    for (int i = 1; i <= mxN; i++) {
        ifact_arr[i] = mult(ifact_arr[i - 1], inv(i));
        fact_arr[i] = mult(fact_arr[i - 1], i);
    }
}

int fact(int n) {
    if (fact_arr[0] == 0) {
        init();
    }
    return fact_arr[n];
}

int ifact(int n) {
    if (ifact_arr[0] == 0) {
        init();
    }
    return ifact_arr[n];
}

int nck(int n, int k) {
    if (k > n) {
        return 0;
    }
    return mult(fact(n), mult(ifact(k), ifact(n - k)));
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long m;
    cin >> n >> m;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 0; i <= n; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int cur = 1;
    long long prod = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (is_prime[i] && prod <= m) {
            prod *= i;
        }
        cur = mult(cur, (int)((m / prod) % MOD));
        ans = add(ans, sub(pow(m % MOD, i), cur));
    }
    cout << ans << '\n';
}
