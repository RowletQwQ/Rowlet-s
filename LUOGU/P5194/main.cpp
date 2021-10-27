#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
int n,c,fa[1005];
ll sum_fa[1005],maxsum[1005],ans;
bool book[1005];
void dfs(int cnt,ll sum){
	if(sum>c)return;
	maxsum[cnt]=max(maxsum[cnt],sum);
	for(int i=n;i>=1;i--){
		//if(sum+fa[i]>c)continue;
		if(sum+sum_fa[i]<maxsum[cnt])break; 
		if(!book[i]){
			//if(sum+fa[i]<maxsum[cnt])continue;
			book[i]=true;
			dfs(cnt+1,sum+fa[i]);
			book[i]=false;
		}
	}
	return;
}
int main(int argc, char** argv) {
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%lld",&fa[i]);
		sum_fa[i]=sum_fa[i-1]+fa[i]; 
	}
	dfs(0,0);
	for(int i=1;i<=n;i++){
		ans=max(ans,maxsum[i]);
	}
	printf("%lld",ans);
	return 0;
}
