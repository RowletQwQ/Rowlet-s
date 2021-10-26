#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll n,ans,a[50005],t,book[7][2];
void readi(ll &a){
	char c;bool is=false;
	for(c=getc(stdin);c<'0'||c>'9';c=getc(stdin))if(c=='-')is=true;
	for(a=0;c<='9'&&c>='0';c=getc(stdin))a=(a<<3)+(a<<1)+c-'0';
	if(is)a=-a;
}
int main(int argc, char** argv) {
	readi(n);
	a[0]=0;
	for(int i=1;i<=n;i++){
		readi(a[i]);
		a[i]=(a[i]+a[i-1])%7;
	}
	for(int i=1;i<=n;i++)book[a[i]][0]=i;
	for(int i=n;i>0;i--)book[a[i]][1]=i;
	for(int i=0;i<7;i++){
		ans=max(ans,book[i][0]-book[i][1]);
	}
	printf("%d",ans);
	return 0;
}
