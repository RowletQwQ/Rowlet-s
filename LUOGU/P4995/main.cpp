#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long 
using namespace std;
ll n,a[305],ans;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool cmp(ll x,ll y){
	return x<y;
}
int main(int argc, char** argv) {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n==1){
		printf("%lld",a[1]*a[1]);
	}else{
		sort(a+1,a+1+n,cmp);
		ans+=a[n]*a[n];
		int l=1,r=n;
		bool is=true;
		while(l<r){
			ans+=(a[r]-a[l])*(a[r]-a[l]);
			if(is){
				r--;is=false;
			}else{
				l++;is=true;
			}
		}
		printf("%lld",ans);
	}
	
	
	return 0;
}
