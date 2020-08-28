#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        string w;
        for (int i = 0; i < s.size(); i+=2) {
            w += s[i];
        }
        cout << w << endl;
    }
}