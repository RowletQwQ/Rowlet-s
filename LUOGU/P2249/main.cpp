#include <iostream>
#include <cstdio>
using namespace std;
int a[1000005],m,n,t;
void readi(int &x){
	char c;bool is=false;
	for(c=getc(stdin);c<'0'||c>'9';c=getc(stdin));
	for(x=0;c>='0'&&c<='9';c=getc(stdin))x=(x<<1)+(x<<3)+c-'0';
}
int main(int argc, char** argv) {
	readi(n);readi(m);
	for(int i=1;i<=n;i++)readi(a[i]);
	for(int i=1;i<=m;i++){
		readi(t);
		int l=1,r=n;
		while(l<r){
			if(a[l]==t){
				printf("%d ",l);
				break;
			}
			if(r-l==1){
				if(a[r]==t){
					printf("%d ",r);
					break;
				}else{
					printf("-1 ");
					break;
				}
			}
			int mid=(l+r)>>1;
			if(a[mid]<t){
				l=mid;
			}else{
				r=mid;
			}
		}
	}
	return 0;
}
