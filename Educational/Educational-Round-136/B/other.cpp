#include <bits/stdc++.h>

using namespace std;

#define int long long
#define inf INT_MAX
#define vi vector<int>
#define vs vector<string>

int mod = 1e9 + 7;

template <typename T>
vector<T> I(int n) {
    vector<T> vector;
    for (int i = 0; i < n; i++) {
        T input;
        cin >> input;
        vector.push_back(input);
    }

    return vector;
}

template <typename T>
void D(vector<T> vector) {
    for (auto i : vector) {
        cout << i << " ";
    }

    cout << "\n";
}

bool check(vi x) {
    for (int i = 1; i < x.size(); i++) {
        if (x[i] != x[i - 1]) return false;
    }

    return true;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi x = I<int>(n), ans;
        ans.push_back(x[0]);
        bool ok = true;
        for (int i = 1; i < n; i++) {
            int c = x[i] + ans[i - 1];
            int d = ans[i - 1] - x[i];
            // cout << c << " " << d << "\n";
            if (c > 0 && d > 0 && c != d) {
                ok = false;
                break;
            }

            else
                ans.push_back(max(c, d));
        }

        if (ok)
            D<int>(ans);
        else
            cout << -1 << "\n";
    }
}
