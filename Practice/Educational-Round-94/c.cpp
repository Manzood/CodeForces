// do this please, when your brain finally decides it wants to function again
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s;
        int x; cin >> x;
        int n = sz(s);
        string w;
        for (int i = 0; i < n; i++) {
            w += '0';
            if (i < x) {
                if (i + x < n && s[i+x] == '1') 
                    w[i] = '1';
            }
            else if (i < n-x) {
                if (s[i-x] == '1' && s[i+x] == '1') 
                    w[i] = '1';
            }
            else {
                if (i - x >= 0 && s[i-x] == '1')
                    w[i] = '1';
            } 
        }
        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                bool first = false, second = false;
                if (i - x >= 0 && w[i-x] == '1') first = true;
                if (i + x < n && w[i+x] == '1') second = true;
                if (first || second) possible = false;
            }
            else {
                bool first = false, second = false;
                if (i - x < 0 || w[i-x] == '0') first = true;
                if (i + x >= n || w[i+x] == '0') second = true;
                if (first && second) possible = false;
            }
        }
        if (possible) {
            cout << w << '\n';
        }
        else {
            printf("-1\n");
        }
    }
}