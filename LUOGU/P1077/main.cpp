#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int f[105],n,m,ans[105],mod = 1000007;
int min(int x,int y){
	if(x<y)return x;
	return y;
}
int main(int argc, char** argv) {
	memset(ans,0,sizeof(ans));
	ans[0]=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&f[i]);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){
			for(int k=1;k<=min(f[i],j);k++){
				ans[j]=(ans[j]+ans[j-k])%mod;
			}
		}
	}
	printf("%d",ans[m]);
	return 0;
}
