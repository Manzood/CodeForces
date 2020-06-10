#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,m;
		scanf("%d%d",&n,&m);
		vector <int> rowcount(n);
		vector <int> colscount(m);
		for (int i=0;i<max(n,m);i++) {
			if (i<n)
				rowcount[i]=0;
			if (i<m)
				colscount[i]=0;
		}
		int temp;
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				scanf("%d",&temp);
				if (temp==1) {
					rowcount[i]=1;
					colscount[j]=1;
				}
			}
		}	
		int rcnt=0, ccnt=0;
		for (int i=0;i<max(n,m);i++) {
			if (i<n && rowcount[i]==0)
				rcnt++;
			if (i<m && colscount[i]==0)
				ccnt++;
		}
		if (min(rcnt,ccnt)%2==0) printf("Vivek\n");
		else printf("Ashish\n");
	}
}