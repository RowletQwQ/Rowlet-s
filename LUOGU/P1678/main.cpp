#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[100005],n,m,t,ans=0;
int min(int x,int y){
	if(x<0)x=-x;
	if(y<0)y=-y;
	if(x>y)return y;
	return x;
}
int search(int mark,int l,int r){
	if(r-l==1)return min(mark-a[l],a[r]-mark); 
	int mid=(l+r)/2;
	if(a[mid]>mark)return search(mark,l,mid);
	else return search(mark,mid,r);
}
int main(int argc, char** argv) {
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		ans+=search(t,1,m);
	}
	printf("%d",ans);
	return 0;
}
