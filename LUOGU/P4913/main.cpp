#include <iostream>
#include <cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node{
	int l,r;
}node[200005];
int n,ans;
int max(int a,int b){
	return (a>b)?a:b;
}
int dfs(int x){
	if(!x)return 0;
	return max(dfs(node[x].l),dfs(node[x].r))+1;
}
int main(int argc, char** argv) {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&node[i].l,&node[i].r);
	}
	printf("%d",dfs(1));
	return 0;
}
