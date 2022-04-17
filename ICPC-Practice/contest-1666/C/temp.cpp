#include "bits/stdc++.h"
using namespace std;
#define ll long long

#define MOD 998244353

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;

    cin >> n >> m >> s;
    vector<vector<int>> v(n + 1, vector<int>());

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
    }

    stack<int> st;
    vector<int> parent(n + 1, -1);
    vector<int> group(n + 1, -1);

    vector<int> p1, p2;

    bool flag = 1;

    int curr;
    for (int i : v[s]) {
        st.push(i);
        curr = i;

        if (group[i] == -1 || group[i] == i) {
            group[i] = i;
        } else {
            while (curr != -1) {
                p1.push_back(curr);
                assert(p1.size() < (int)1e6);
                curr = parent[curr];
            }
            p2.push_back(i);
            p2.push_back(s);
            assert(p2.size() < (int)1e6);
            flag = 0;
            break;
        }

        parent[i] = s;

        while (!st.empty()) {
            assert(st.size() < (int)1e6);
            curr = st.top();
            st.pop();

            if (flag == 0) break;

            for (int j : v[curr]) {
                if (parent[j] == -1) {
                    st.push(j);
                    parent[j] = curr;
                }

                if (group[j] == -1 || group[j] == i) {
                    group[j] = i;
                } else {
                    p1.push_back(j);
                    while (curr != -1) {
                        p1.push_back(curr);
                        assert(p1.size() < (int)1e6);
                        curr = parent[curr];
                    }
                    curr = j;
                    while (curr != -1) {
                        p2.push_back(curr);
                        assert(p2.size() < (int)1e6);
                        curr = parent[curr];
                    }
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
    }

    // for (int i=1; i<n+1; i++) {
    //    cout << group[i] << " ";
    //}
    // cout << "\n";

    // for (int i=1; i<n+1; i++) {
    //    cout << parent[i] << " ";
    //}
    // cout << "\n";

    if (flag == 0) {
        cout << "Possible\n";
        cout << p1.size() << "\n";
        for (int i = p1.size() - 1; i >= 0; i--) {
            cout << p1[i] << " ";
        }
        cout << "\n";
        cout << p2.size() << "\n";
        for (int i = p2.size() - 1; i >= 0; i--) {
            cout << p2[i] << " ";
        }
        cout << "\n";
    }

    else {
        cout << "Impossible\n";
    }
}
