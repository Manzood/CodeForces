#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%lld", &n);
		string a, b;
		cin >> a;
		cin >> b;
		vector <set <char> > check(26);
		bool possible = true;
		int ans = 0;
		for (int i=0; i<n; i++) {
			// check it out
			int ind = a[i] - 'a';
			if (a[i] > b[i]) possible = false;
			else if (a[i] < b[i]) {
				bool found = false;
				if (check[ind].count(b[i]) > 0) 
					found = true;
				for (int j=0; found == false && j<check.size(); j++) {
					if (check[j].count(b[i]) > 0 && check[j].count(a[i]) > 0) {
						found = true;
						check[ind].insert(b[i]);
						break;
					}
				}
				for (char x: check[ind]) {
					for (char y: check[x-'a']) {
						if (y == b[i]) {
							found = true;
							break;
						}
					}
				}
				if (!found) {
					// debug(i);
					// debug(a[i]);
					ans++;
					check[ind].insert(b[i]);
				}
			}
		}
		if (possible) printf("%lld\n", ans);
		else printf("-1\n");
	}
}