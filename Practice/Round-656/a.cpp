#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector <int> a(3);
		for (int i=0; i<3; i++) scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		if (a[2] == a[1]) {
			printf("YES\n");
			printf("%d %d %d\n", a[2], a[0], a[0]);
		}
		else
			printf("NO\n");
	}
}
