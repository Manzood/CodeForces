#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		int countodd=0;
		int counteven=0;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (a[i]%2!=i%2) {
				if (a[i]%2==0)
					countodd++;
				else
					counteven++;
			}
		}
		if (countodd==counteven) {
			cout<<countodd<<endl;
		}
		else
			cout<<-1<<endl;
	}
}