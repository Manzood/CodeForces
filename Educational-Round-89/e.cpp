#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	vector <int> a(n);
	vector <int> b(m);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for (int i=0;i<m;i++) {
		scanf("%d",&b[i]);
	}
	int ind=0;
	vector <int> positions(m);
	for (int i=0;i<n;i++) {
		if (ind<b.size()-2) {
			if (a[i]==b[ind+2]) {
				ind++;			
			}
			else if (a[i]==b[ind]) 
				positions[ind]=i;
			else if (a[i]==b[ind+1])
				positions[i]=i;
		}
	}
}