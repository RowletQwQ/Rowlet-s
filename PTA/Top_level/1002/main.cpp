#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,dp[1000005];
struct project{
	int p,l,d;
}p[55];
bool cmp(project x,project y){
	return x.d>y.d;
}
int max(int x,int y){
	return (x>y)?x:y;
}
int main(int argc, char** argv) {
	scanf("%d",&n);
	int maxd = 0; 
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&p[i].p,&p[i].l,&p[i].d);
		maxd=max(maxd,p[i].d);
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=maxd;j>=p[i].l;j--){
			if(p[i].d>j)continue;
			dp[j]=max(dp[j],dp[j-p[i].l]+p[i].p);
		}
	}
	printf("%d",dp[maxd]);
	return 0;
}
